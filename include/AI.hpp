//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_AI_HPP
#define GOMOKU_AI_HPP

#include "Protocol.hpp"

#include <memory>

class AI {
public:
    AI(const std::shared_ptr<Game> &game);

    Protocol::AIReturn think();
    Protocol::AIReturn think(int timeOutMillisecond);

private:
    const std::shared_ptr<Game> m_game;

    Game::Pos getRandomPos(const std::list<Game::Pos> &list);
};

#endif //GOMOKU_AI_HPP
