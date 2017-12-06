//
// Created by 53915 on 01/12/2017.
//

#include <random>
#include "AI.hpp"

AI::AI(const std::shared_ptr<Game> &game) : m_game(game) {}

Protocol::AIReturn AI::think() {
    think(0);
}

Protocol::AIReturn AI::think(int timeOutMillisecond) {
    (void)timeOutMillisecond;
    Protocol::AIReturn ret;
    ret.isPos = true;
    ret.pos = getRandomPos(m_game->getAllEmptyPos());
    return ret;
}

// Private Functions

Game::Pos AI::getRandomPos(const std::list<Game::Pos> &list) {
    int rando = rand() % list.size();
    auto it = list.begin();
    for (size_t i = 0; i < rando; i++, it++);
    return *it;
}

