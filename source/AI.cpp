//
// Created by 53915 on 01/12/2017.
//

#include <random>
#include <iostream>
#include "AI.hpp"

// Extern function

bool	mySort(std::pair<Game::Pos, int> x, std::pair<Game::Pos, int> x2) {
    return (x.second > x2.second);
}

// !Extern functions

AI::AI(const std::shared_ptr<Game> &game) : m_game(game), m_moveAi(std::multiset<std::pair<Game::Pos, int>, bool (*)(std::pair<Game::Pos, int>, std::pair<Game::Pos, int>)>(&mySort)) {}

Protocol::AIReturn AI::think() {
    return think(0);
}

Protocol::AIReturn AI::think(int timeOutMillisecond) {
    (void)timeOutMillisecond;
    Protocol::AIReturn ret;
    std::list<Game::Pos> tmpList;
    //ret.pos = getRandomPos(m_game->getAllEmptyPos());
    int	tmpWeight;
    tmpList = m_game->getAllEmptyPos();
    ret.isPos = true;
    if (m_game->isEmptyBoard()) {
        ret.pos.x = (m_game->height() / 2);
        ret.pos.y = (m_game->width() / 2);
        return ret;
    }
    for (auto it = tmpList.begin(); it != tmpList.end(); it++) {
        tmpWeight = evalPos(*it);
        m_moveAi.addInList(*it, tmpWeight);
        //std::cout << tmpWeight << std::endl;
    }
    ret.isPos = true;
    /*if (m_isCritical)
        ret.pos = m_moveAi.getFirst();
    else
        ret.pos = m_moveAi.getLast();*/
    ret.pos = m_moveAi.getFirst();
    m_moveAi.removeAll();
    return ret;
}

// Private Functions

Game::Pos AI::getRandomPos(const std::list<Game::Pos> &list) {
    //std::cout << "List size : " << list.size() << std::endl;
    int rando = rand() % list.size();
    auto it = list.begin();
    for (int i = 0; i < rando; i++, it++);
    return *it;
}

int	AI::evalPos(const Game::Pos &pos) {
    int	eval, eval1, eval2, eval3, eval4;

    eval1 = check_hori(pos);
    eval1 += check_horiReverse(pos);

    eval2 = check_vert(pos);
    eval2 += check_vertReverse(pos);

    if (eval1 > eval2)
        eval = eval1;
    else
        eval = eval2;

    eval3 = check_diagNE(pos);
    eval3 += check_diagSW(pos);

    if (eval3 > eval)
        eval = eval3;

    eval4 = check_diagNW(pos);
    eval4 += check_diagSE(pos);

    if (eval4 > eval)
        eval = eval4;
    return (eval);
}

int	AI::check_hori(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && i <= 4 && m_game->boardGet(pos.x - i, pos.y) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y) == OPPONENT_STONE)
            val += 2 * i;
        if (m_game->boardGet(pos.x - i, pos.y) == OWN_STONE) {
            val--;
            break;
        }
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) <= m_game->width() && i <= 4 && m_game->boardGet(pos.x + i, pos.y) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y) == OPPONENT_STONE)
            val += 2 * save;
        if (m_game->boardGet(pos.x + i, pos.y) == OWN_STONE) {
            val--;
            break;
        }
        i++;
        save++;
    }
    return val;
}

int	AI::check_horiReverse(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && i <= 4 && m_game->boardGet(pos.x - i, pos.y) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x - i, pos.y) == OWN_STONE)
            val += 2 * (-i);
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) <= m_game->width() && i <= 4 && m_game->boardGet(pos.x + i, pos.y) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x + i, pos.y) == OWN_STONE)
            val += 2 * (-save);
        i++;
        save++;
    }
    return val;
}

int	AI::check_vert(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.y - i) >= 0 && i <= 4 && m_game->boardGet(pos.x, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x, pos.y - i) == OPPONENT_STONE)
            val += 2 * i;
        if (m_game->boardGet(pos.x, pos.y - i) == OWN_STONE) {
            val--;
            break ;
        }
        i++;
    }
    save = i;
    i = 1;
    while ((pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x, pos.y + i) == OPPONENT_STONE)
            val += 2 * save;
        if (m_game->boardGet(pos.x, pos.y + i) == OWN_STONE) {
            val--;
            break;
        }
        i++;
        save++;
    }
    return val;
}

int	AI::check_vertReverse(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.y - i) >= 0 && i <= 4 && m_game->boardGet(pos.x, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x, pos.y - i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x, pos.y - i) == OWN_STONE)
            val += 2 * (-i);
        i++;
    }
    save = i;
    i = 1;
    while ((pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x, pos.y + i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x, pos.y + i) == OWN_STONE)
            val += 2 * (-save);
        i++;
        save++;
    }
    return val;
}

int	AI::check_diagNE(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && (pos.y - i) >= 0 && i <= 4 && m_game->boardGet(pos.x - i, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y - i) == OPPONENT_STONE)
            val += 2 * i;
        if (m_game->boardGet(pos.x - i, pos.y - i) == OWN_STONE) {
            val--;
            break ;
        }
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) <= m_game->width() && (pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x + i, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y + i) == OPPONENT_STONE)
            val += 2 * save;
        if (m_game->boardGet(pos.x + i, pos.y + i) == OWN_STONE) {
            val--;
            break;
        }
        i++;
        save++;
    }
    return val;
}

int	AI::check_diagSW(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && (pos.y - i) >= 0 && i <= 4 && m_game->boardGet(pos.x - i, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y - i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x - i, pos.y - i) == OWN_STONE)
            val += 2 * (-i);
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) <= m_game->width() && (pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x + i, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y + i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x + i, pos.y + i) == OWN_STONE)
            val += 2 * (-save);
        i++;
        save++;
    }
    return val;
}

int	AI::check_diagNW(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && (pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x - i, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y + i) == OPPONENT_STONE)
            val += 2 * i;
        if (m_game->boardGet(pos.x - i, pos.y + i) == OWN_STONE) {
            val--;
            break ;
        }
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) >= 0 && (pos.y - i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x + i, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y - i) == OPPONENT_STONE)
            val += 2 * save;
        if (m_game->boardGet(pos.x + i, pos.y - i) == OWN_STONE) {
            val--;
            break;
        }
        i++;
        save++;
    }
    return val;
}

int	AI::check_diagSE(const Game::Pos &pos) {
    int i = 1;
    int val = 0;
    int save;
    while ((pos.x - i) >= 0 && (pos.y + i) <= m_game->height() && i <= 4 && m_game->boardGet(pos.x - i, pos.y + i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x - i, pos.y + i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x - i, pos.y + i) == OWN_STONE)
            val += 2 * (-i);
        i++;
    }
    save = i;
    i = 1;
    while ((pos.x + i) <= m_game->width() && (pos.y - i) >= 0 && i <= 4 && m_game->boardGet(pos.x + i, pos.y - i) != EMPTY_CASE) {
        if (m_game->boardGet(pos.x + i, pos.y - i) == OPPONENT_STONE) {
            val++;
            break;
        }
        if (m_game->boardGet(pos.x + i, pos.y - i) == OWN_STONE)
            val += 2 * (-save);
        i++;
        save++;
    }
    return val;
}