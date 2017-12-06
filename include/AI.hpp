//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_AI_HPP
#define GOMOKU_AI_HPP

#include "Protocol.hpp"
#include "MyMultiset.hpp"

#include <memory>

class AI {
public:
    AI(const std::shared_ptr<Game> &game);

    Protocol::AIReturn think();
    Protocol::AIReturn think(int timeOutMillisecond);
private:
    const std::shared_ptr<Game> m_game;
    MyMultiset<Game::Pos, int>	m_moveAi;

    Game::Pos getRandomPos(const std::list<Game::Pos> &list);
    int	      evalPos(Game::Pos p);
    int       check_vert(Game::Pos pos);
    int       check_vertReverse(Game::Pos);
    int       check_hori(Game::Pos);
    int       check_horiReverse(Game::Pos);
    int       check_diagNE(Game::Pos);
    int       check_diagSE(Game::Pos);
    int       check_diagSW(Game::Pos);
    int       check_diagNW(Game::Pos);
};

bool      MySort(std::pair<Game::Pos, int> x, std::pair<Game::Pos, int> x2);

#endif //GOMOKU_AI_HPP
