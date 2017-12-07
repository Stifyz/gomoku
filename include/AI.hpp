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

    int	      evalPos(const Game::Pos &pos);
    int       check_vert(const Game::Pos &pos);
    int       check_vertReverse(const Game::Pos &pos);
    int       check_hori(const Game::Pos &pos);
    int       check_horiReverse(const Game::Pos &pos);
    int       check_diagNE(const Game::Pos &pos);
    int       check_diagSE(const Game::Pos &pos);
    int       check_diagSW(const Game::Pos &pos);
    int       check_diagNW(const Game::Pos &pos);
};

bool      MySort(std::pair<Game::Pos, int> x, std::pair<Game::Pos, int> x2);

#endif //GOMOKU_AI_HPP
