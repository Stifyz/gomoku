//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_PROTOCOL_HPP
#define GOMOKU_PROTOCOL_HPP

#include <functional>
#include <map>
#include <string>
#include <bits/unordered_map.h>
#include <bits/shared_ptr.h>
#include <bits/unique_ptr.h>

#include "Game.hpp"
#include "Brain.hpp"

#define EMPTY_CASE 0
#define OWN_STONE 1
#define OPPONENT_STONE 2
#define OTHER_STONE 3

class Protocol {
public:
    typedef void (Protocol::*MethodPointer)(const std::string &);

    Protocol(const std::shared_ptr<Game> game, std::unique_ptr<Brain> brain);

    class GameSetter {
    public:
        inline static void size(Game &game, const unsigned int size) { game.size(size); }
        inline static void height(Game &game, const unsigned int height) { game.height(height); }
        inline static void width(Game &game, const unsigned int width) { game.height(width); }

        inline static void addInfo(Game &game, const std::string &key, const std::string &value) { game.addInfo(key, value); }
        inline static bool boardSet(Game &game, const Game::Pos &pos, const int value) { game.boardSet(pos, value); }
        inline static void changeTurn(Game &game) { game.changeTurn(); }
        inline static void changeTurn(Game &game, bool b) { game.changeTurn(b); }
    };

    enum class Action {
        NONE,
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

    struct AIReturn {
        bool isPos;
        Game::Pos pos;

        Action action;
        std::string mssg;
    };

    void processInput(const std::string &line);
    void processOutput(const AIReturn &aiRes);
    void processOutput(const unsigned int x, const unsigned int y);
    void processOutput(const Action action, const std::string &mssg);

private:
    const std::shared_ptr<Game> m_game;
    const std::unique_ptr<Brain> m_brain;
    Action m_lastAction;
    const std::map<const std::string, const Action> m_action = {
            {"", Action::NONE},
            {"START", Action::START},
            {"TURN", Action::TURN},
            {"BEGIN", Action::BEGIN},
            {"BOARD", Action::BOARD},
            {"INFO", Action::INFO},
            {"END", Action::END},
            {"ABOUT", Action::ABOUT},
            {"RECSTART", Action::RECSTART},
            {"RESTART", Action::RESTART},
            {"TAKEBACK", Action::TAKEBACK},
            {"PLAY", Action::PLAY},
            {"UNKNOWN", Action::UNKNOWN},
            {"ERROR", Action::ERROR},
            {"MESSAGE", Action::MESSAGE},
            {"DEBUG", Action::DEBUG},
            {"SUGGEST", Action::SUGGEST}
    };
    const std::map<const Action, const std::string> m_actionToString = {
            {Action::NONE, ""},
            {Action::START, "START"},
            {Action::TURN, "TURN"},
            {Action::BEGIN, "BEGIN"},
            {Action::BOARD, "BOARD"},
            {Action::INFO, "INFO"},
            {Action::END, "END"},
            {Action::ABOUT, "ABOUT"},
            {Action::RECSTART, "RECSTART"},
            {Action::RESTART, "RESTART"},
            {Action::TAKEBACK, "TAKEBACK"},
            {Action::PLAY, "PLAY"},
            {Action::UNKNOWN, "UNKNOWN"},
            {Action::ERROR, "ERROR"},
            {Action::MESSAGE, "MESSAGE"},
            {Action::DEBUG, "DEBUG"},
            {Action::SUGGEST, "SUGGEST"}
    };
    std::map<const Action, const Protocol::MethodPointer> m_func;
    void send(const Action action, const std::string &str);

    void start(const std::string &cmmd);
    void turn(const std::string &cmmd);
    void begin(const std::string &cmmd);
    void board(const std::string &cmmd);
    void info(const std::string &cmmd);
    void end(const std::string &cmmd);
    void about(const std::string &cmmd);
    void recStart(const std::string &cmmd);
    void reStart(const std::string &cmmd);
    void takeBack(const std::string &cmmd);
    void play(const std::string &cmmd);
    void unknown(const std::string &cmmd);
    void error(const std::string &cmmd);
    void message(const std::string &cmmd);
    void debug(const std::string &cmmd);
    void suggest(const std::string &cmmd);
};

#endif //GOMOKU_PROTOCOL_HPP
