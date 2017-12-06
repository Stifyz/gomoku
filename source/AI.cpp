//
// Created by 53915 on 01/12/2017.
//

#include <random>
#include "AI.hpp"

AI::AI(const std::shared_ptr<Game> &game) : m_game(game), m_moveAi(&MySort) {}

Protocol::AIReturn AI::think() {
    think(0);
}

Protocol::AIReturn AI::think(int timeOutMillisecond) {
    (void)timeOutMillisecond;
    Protocol::AIReturn ret;
    std::list<Game::Pos> tmpList;
    int	tmpWeight;
    tmpList = m_game->getAllPlayablePos();
    ret.isPos = true;
<<<<<<< HEAD
    ret.pos = getRandomPos(m_game->getAllPlayablePos());
    for (auto it = tmpList.begin(); it != tmpList.end(); it++) {
      tmpWeight = evalPos(*it);
      m_moveAi.addInList(*it, tmpWeight);
    }
    ret.pos = m_moveAi.getFirst();
=======
    ret.pos = getRandomPos(m_game->getAllEmptyPos());
>>>>>>> 0998b64732f950798731d3f9b71de95439d2f637
    return ret;
}

// Private Functions

Game::Pos AI::getRandomPos(const std::list<Game::Pos> &list) {
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

// Function extern

bool	MySort(std::pair<Game::Pos, int> x, std::pair<Game::Pos, int> x2) {
  return (x.second < x2.second);
}


