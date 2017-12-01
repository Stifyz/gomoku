//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_AI_HPP
#define GOMOKU_AI_HPP

class AI {
public:
    Pos think();
    Pos think(int timeOutMillisecond);

    struct Pos {
        unsigned int x;
        unsigned int y;
    };
};

#endif //GOMOKU_AI_HPP
