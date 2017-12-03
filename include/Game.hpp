//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_GAMEBOARD_HPP
#define GOMOKU_GAMEBOARD_HPP

#include <list>
#include <map>
#include <string>
#include <vector>
#include "Protocol.hpp"

class Game {
public:
    friend class Protocol::GameSetter;

    Game();
    Game(const unsigned int size);
    Game(const unsigned int height, const unsigned int width);

    struct Pos {
        Pos(unsigned int x = 0, unsigned int y = 0) : x(x), y(y) {}
        unsigned int x;
        unsigned int y;
    };

    // Info management
    const std::string &getInfo(const std::string &key) const;
    // !Info management

    // Board Management
    int boardGet(const unsigned int x, const unsigned int y) const;

    const std::list<Pos> &getAllEmptyPos() const;
    const std::list<Pos> &getAllMyPos() const;
    const std::list<Pos> &getAllOpponentPos() const;
    const std::list<Pos> &getAllUnknownPos() const;
    const std::list<Pos> &getAllPlayablePos();

    bool isPlayable(std::list<Pos> &filledList, Pos pos);
    bool isAdjacentTo(Pos pos1, Pos pos2);

    int size() const;
    int height() const;
    int width() const;
    bool isSquare() const;
    bool isEmptyBoard() const;
    bool isMyTurn() const;
    // !Board Management

private:
    bool m_isMyTurn = false;
    bool m_isSquare = true;
    int m_boardHeight = 0;
    int m_boardWidth = 0;
    bool m_isEmptyBoard = true;

    std::list<Pos> m_emptyPos;
    std::list<Pos> m_myPos;
    std::list<Pos> m_opponentPos;
    std::list<Pos> m_unknownPos;

    std::vector<std::vector<unsigned int>> m_board;
    std::map<std::string, std::string> m_info;

    void size(const int size);
    void height(const int height);
    void width(const int width);

    void addInfo(const std::string &key, const std::string &value);
    bool boardSet(const Pos &pos, const int value);
    void changeTurn(bool b = !m_isMyTurn);

    void resizeBoard();
    void fillLists();
    void swapList(const Pos &pos, const int newValue);
};

#endif //GOMOKU_GAMEBOARD_HPP
