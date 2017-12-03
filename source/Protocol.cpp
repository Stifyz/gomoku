//
// Created by zimmer_n on 01/12/2017.
//

#include <utility>
#include <iostream>

#include "Protocol.hpp"

Protocol::Protocol(const std::shared_ptr<Game> game, const std::unique_ptr<Brain> brain) : m_game(game), m_brain(brain.get()) {
    m_func.insert(std::make_pair(Action::START, &start));
    m_func.insert(std::make_pair(Action::TURN, &turn));
    m_func.insert(std::make_pair(Action::BEGIN, &begin));
    m_func.insert(std::make_pair(Action::BOARD, &board));
    m_func.insert(std::make_pair(Action::INFO, &info));
    m_func.insert(std::make_pair(Action::END, &end));
    m_func.insert(std::make_pair(Action::ABOUT, &about));
    m_func.insert(std::make_pair(Action::RECSTART, &recStart));
    m_func.insert(std::make_pair(Action::RESTART, &reStart));
    m_func.insert(std::make_pair(Action::TAKEBACK, &takeBack));
    m_func.insert(std::make_pair(Action::PLAY, &play));
    m_func.insert(std::make_pair(Action::UNKNOWN, &unknown));
    m_func.insert(std::make_pair(Action::ERROR, &error));
    m_func.insert(std::make_pair(Action::MESSAGE, &message));
    m_func.insert(std::make_pair(Action::DEBUG, &debug));
    m_func.insert(std::make_pair(Action::SUGGEST, &suggest));
}

void Protocol::processInput(const std::string &line) {
    const std::string cmmd(line.substr(0, line.find_first_of(' ')));
    const std::string arg(line.substr(line.find_first_of(' ')));
    auto it = m_action.find(cmmd);
    if (it == m_action.end()) {
        send(Action::UNKNOWN, "I don't understand " + cmmd + " command.");
        return ;
    }
    m_lastAction = m_action.at(cmmd);
    m_func.at(m_action.at(cmmd))(arg);
}

void Protocol::processOutput(const AIReturn &aiRes) {
    if (aiRes.isPos)
        processOutput(aiRes.pos.x, aiRes.pos.y);
    else
        processOutput(aiRes.action, aiRes.mssg);
}

void Protocol::processOutput(const unsigned int x, const unsigned int y) {
    Game::Pos pos(x, y);
    GameSetter::boardSet(*m_game, pos, OWN_STONE);
    send(Action::NONE, std::to_string(x)+','+std::to_string(y));
}

void Protocol::processOutput(const Action action, const std::string &mssg) {
    send(action, mssg);
}

// Private Methods
void Protocol::send(const Action action, const std::string &str) {
    std::cout << m_actionToString.at(action) << " " << str << std::endl;
}

void Protocol::start(const std::string &arg) {
    int size;
    try {
        size = std::stoi(arg);
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument of size isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument of size is out of range");
        return ;
    }
    if (size < 0) {
        send(Action::ERROR, "Size must be positive");
        return ;
    }
    GameSetter::size(*m_game, size);
    m_lastAction = Action::START;
}

void Protocol::turn(const std::string &arg) {
    Game::Pos pos;
    try {
        pos.x = std::stoi(arg.substr(0, arg.find_first_of(',')));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument x isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument x is out of range");
        return ;
    }
    try {
        pos.y = std::stoi(arg.substr(0, arg.find_first_of(',')));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument y isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument y is out of range");
        return ;
    }
    if (!GameSetter::boardSet(*m_game, pos, OPPONENT_STONE))
        send(Action::ERROR, "The given case is out of the board");
    m_lastAction = Action::TURN;
}

void Protocol::begin(const std::string &arg) {
    if (m_game->isEmptyBoard()) {
        send(Action::ERROR, "BEGIN command cannot be called on no-empty board");
        return ;
    }
    GameSetter::changeTurn(*m_game, true);
    m_lastAction = Action::BEGIN;
}

void Protocol::board(const std::string &arg) {
    if (m_lastAction != Action::START && m_lastAction != Action::RESTART && m_lastAction != Action::RECSTART) {
        send(Action::ERROR, "Command BOARD must be sended after START, RESTART or RECSTART command.");
        return ;
    }
    std::string buf;
    Game::Pos pos;
    int value;
    std::getline(std::cin, buf);
    while (buf != "DONE") {
        try {
            pos.x = std::stoi(arg.substr(0, arg.find_first_of(',')));
        } catch (std::invalid_argument &e) {
            send(Action::ERROR, "The argument x isn't valid number");
            return ;
        } catch (std::out_of_range &e) {
            send(Action::ERROR, "The argument x is out of range");
            return ;
        }
        if (pos.x < 0 || pos.x >= m_game->width()) {
            send(Action::ERROR, "Argument x must be in the grid");
            return ;
        }
        try {
            pos.y = std::stoi(arg.substr(arg.find_first_of(',') + 1, arg.find_last_of(',')));
        } catch (std::invalid_argument &e) {
            send(Action::ERROR, "The argument y isn't valid number");
            return ;
        } catch (std::out_of_range &e) {
            send(Action::ERROR, "The argument y is out of range");
            return ;
        }
        if (pos.y < 0 || pos.y >= m_game->height()) {
            send(Action::ERROR, "Argument y must be in the grid");
            return ;
        }
        try {
            value = std::stoi(arg.substr(arg.find_last_of(',') + 1));
        } catch (std::invalid_argument &e) {
            send(Action::ERROR, "The argument value isn't valid number");
            return ;
        } catch (std::out_of_range &e) {
            send(Action::ERROR, "The argument value is out of range");
            return ;
        }
        GameSetter::boardSet(*m_game, pos, value);
        std::getline(std::cin, buf);
    }
}

void Protocol::info(const std::string &arg) {
    GameSetter::addInfo(*m_game, arg.substr(0, arg.find_first_of(' ')), arg.substr(arg.find_first_of(' ') + 1));
}

void Protocol::end(const std::string &arg) {
    m_brain->stop();
}

void Protocol::about(const std::string &arg) {
    send(Action::NONE, std::string("name=\"") + NAME + "\", version=\"" + VERSION + "\", autors=\"" + AUTHORS + "\", country=" + COUNTRY + "\"");
}

void Protocol::recStart(const std::string &arg) {
    int width;
    try {
        width = std::stoi(arg.substr(0, arg.find_first_of(',')));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument of width isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument of width is out of range");
        return ;
    }
    if (width < 0) {
        send(Action::ERROR, "Width must be positive");
        return;
    }
    int height;
    try {
        height = std::stoi(arg.substr(arg.find_first_of(',') + 1));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument of height isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument of height is out of range");
        return ;
    }
    if (width < 0) {
        send(Action::ERROR, "Height must be positive");
        return ;
    }
    GameSetter::width(*m_game, width);
    GameSetter::height(*m_game, height);
}

void Protocol::reStart(const std::string &arg) {
    // TODO
}

void Protocol::takeBack(const std::string &arg) {
    // TODO
}

void Protocol::play(const std::string &arg) {
    // TODO
}

void Protocol::unknown(const std::string &arg) {
    // TODO
}

void Protocol::error(const std::string &arg) {
    // TODO
}

void Protocol::message(const std::string &arg) {
    // TODO
}

void Protocol::debug(const std::string &arg) {
    // TODO
}

void Protocol::suggest(const std::string &arg) {
    // TODO
}

