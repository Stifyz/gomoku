//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_PROTOCOL_HPP
#define GOMOKU_PROTOCOL_HPP

class Protocol {
public:
    enum class Action {
        START,
        TURN,
        BEGIN,
        BOARD,
        INFO,
        END,
        ABOUT,
        RECSTART,
        RESTART,
        TAKEBACK,
        PLAY,
        UNKNOWN,
        ERROR,
        MESSAGE,
        DEBUG,
        SUGGEST,
        SIZE
    };
private:
};

#endif //GOMOKU_PROTOCOL_HPP
