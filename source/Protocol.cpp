//
// Created by zimmer_n on 01/12/2017.
//

#include <utility>
#include <iostream>

#include "Protocol.hpp"

Protocol::Protocol(const std::shared_ptr<Game> game) : m_game(game) {
    m_isMyTurn.reset(&(m_game->m_isMyTurn));
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

void Protocol::processOutput(const unsigned int x, const unsigned int y) {
    // TODO
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
    m_game->size(size);
}

void Protocol::turn(const std::string &arg) {
    int x;
    try {
        x = std::stoi(arg.substr(0, arg.find_first_of(',')));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument x isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument x is out of range");
        return ;
    }
    int y;
    try {
        y = std::stoi(arg.substr(0, arg.find_first_of(',')));
    } catch (std::invalid_argument &e) {
        send(Action::ERROR, "The argument y isn't valid number");
        return ;
    } catch (std::out_of_range &e) {
        send(Action::ERROR, "The argument y is out of range");
        return ;
    }
    if (!m_game->boardSet(x, y, OPPONENT_STONE))
        send(Action::ERROR, "The given case is out of the board");
}

void Protocol::begin(const std::string &arg) {
    *m_isMyTurn = true;
}

void Protocol::board(const std::string &arg) {
    if (m_lastAction != Action::START && m_lastAction != Action::RESTART && m_lastAction != Action::RECSTART) {
        send(Action::ERROR, "Command BOARD must be sended after START, RESTART or RECSTART command.");
        return ;
    }

}

void Protocol::info(const std::string &arg) {
    m_game->addInfo(arg.substr(0, arg.find_first_of(' ')), arg.substr(arg.find_first_of(' ') + 1))
}

void Protocol::end(const std::string &arg) {
    // TODO
}

void Protocol::about(const std::string &arg) {
    // TODO
}

void Protocol::recStart(const std::string &arg) {
    // TODO
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
