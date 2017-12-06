//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_PROTOCOL_HPP
#define GOMOKU_PROTOCOL_HPP

#include "Game.hpp"

#include <functional>
#include <map>
#include <string>
#include <memory>

class Protocol {
public:
    typedef void (Protocol::*MethodPointer)(const std::string &);

    Protocol(const std::shared_ptr<Game> game);

    enum class Action {
        NONE,
        OK,
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

        Protocol::Action action;
        std::string mssg;
    };

    void processInput(const std::string &line);
    void processOutput(const AIReturn &aiRes);
    void processOutput(const unsigned int x, const unsigned int y);
    void processOutput(const Action action, const std::string &mssg);

private:
    const std::shared_ptr<Game> m_game;
    Action m_lastAction;
    const std::map<const std::string, const Action> m_action = {
            {"", Action::NONE},
            {"OK", Action::OK},
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
            {Action::OK, "OK"},
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
    std::map<const Action, Protocol::MethodPointer> m_func;
    void send(const Action action, const std::string &str);

    void start(const std::string &cmmd);
    void ok(const std::string &cmmd);
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
