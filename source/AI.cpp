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
    for (auto it = tmpList.begin(); it != tmpList.end(); it++) {
        tmpWeight = evalPos(*it);
        m_moveAi.addInList(*it, tmpWeight);
    }
    ret.isPos = true;
    if (m_isCritical)
        ret.pos = m_moveAi.getFirst();
    else
        ret.pos = m_moveAi.getLast();
    m_moveAi.removeAll();
    if (m_game->isEmptyBoard()) {
        ret.pos.x = (m_game->height() / 2);
        ret.pos.y = (m_game->width() / 2);
    }
    return ret;
}

// Private Functions

Game::Pos AI::getRandomPos(const std::list<Game::Pos> &list) {
    //std::cout << "List size : " << list.size() << std::endl;
    int rando = rand() % list.size();
    auto it = list.begin();
    for (size_t i = 0; i < rando; i++, it++);
    return *it;
}

int	AI::check_diagNE(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y + i) > m_game->height() || (pos.x + i) > m_game->width() || m_game->boardGet(pos.x + i, pos.y + i) == EMPTY_CASE)
        return val;
    while ((pos.y + i) <= m_game->height() && (pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y + i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.y + i) <= m_game->height() && (pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y + i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_diagNW(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y + i) > m_game->height() || (pos.x - i) < 0 || m_game->boardGet(pos.x - i, pos.y + i) == EMPTY_CASE)
        return val;
    while ((pos.y + i) <= m_game->height() && (pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y + i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.y + i) <= m_game->height() && (pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y + i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_diagSE(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y - i) < 0 || (pos.x + i) > m_game->width() || m_game->boardGet(pos.x + i, pos.y - i) == EMPTY_CASE)
        return val;
    while ((pos.y - i) >= 0 && (pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y - i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.y - i) >= 0 && (pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y - i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_diagSW(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y - i) < 0 || (pos.x - i) < 0 || m_game->boardGet(pos.x - i, pos.y - i) == EMPTY_CASE)
        return val;
    while ((pos.y - i) >= 0 && (pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y - i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.y - i) >= 0 && (pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y - i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_vert(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y + i) > m_game->height() || m_game->boardGet(pos.x, pos.y + i) == EMPTY_CASE)
        return val;
    while ((pos.y + i) <= m_game->height() && m_game->boardGet(pos.x, pos.y + i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.y + i) <= m_game->height() && m_game->boardGet(pos.x, pos.y + i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_vertReverse(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.y - i) < 0 || m_game->boardGet(pos.x, pos.y - i) == EMPTY_CASE)
        return val;
    while ((pos.y - i) >= 0 && m_game->boardGet(pos.x, pos.y - i) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    i = 1;
    if (val >= 3)
        m_isCritical = true;
    while ((pos.y - i) >= 0 && m_game->boardGet(pos.x, pos.y - i) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_horiReverse(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.x - i) < 0 || m_game->boardGet(pos.x - i, pos.y) == EMPTY_CASE)
        return val;
    while ((pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.x - i) >= 0 && m_game->boardGet(pos.x - i, pos.y) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::check_hori(const Game::Pos &pos) {
    int i;
    int val;

    i = 1;
    val = 0;
    if ((pos.x + i) > m_game->width() || m_game->boardGet(pos.x + i, pos.y) == EMPTY_CASE)
        return val;
    while ((pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y) == OPPONENT_STONE && i <= 4) {
        val++;
        i++;
    }
    if (val >= 3)
        m_isCritical = true;
    i = 1;
    while ((pos.x + i) <= m_game->width() && m_game->boardGet(pos.x + i, pos.y) == OWN_STONE && i <= 4) {
        val--;
        i++;
    }
    return val;
}

int	AI::evalPos(const Game::Pos &pos) {
    int	eval;

    eval = 0;
    eval += check_diagNE(pos);
    eval += check_diagSE(pos);
    eval += check_diagSW(pos);
    eval += check_diagNW(pos);
    eval += check_vert(pos);
    eval += check_vertReverse(pos);
    eval += check_hori(pos);
    eval += check_horiReverse(pos);
    return (eval);
}




