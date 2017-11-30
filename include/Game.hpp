//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_GAMEBOARD_HPP
#define GOMOKU_GAMEBOARD_HPP

#include <map>
#include <string>
#include <vector>

class Game {
public:
    Game();
    Game(const unsigned int size);
    Game(const unsigned int height, const unsigned int width);

    // Info management
    void addInfo(const std::string &info);
    const std::string &getInfo(const std::string &key);
    // !Info management

    // Board Management
    int boardGet(const unsigned int x, const unsigned int y);
    void boardSet(const unsigned int x, const unsigned int y, const int value);

    void size(const int size);
    int size();
    void height(const int height);
    int height();
    void width(const int width);
    int width();
    bool isSquare();
    // !Board Management

private:
    bool m_isSquare;
    int m_boardHeight;
    int m_boardWidth;

    std::vector<std::vector<unsigned int>> m_board;
    std::map<std::string, std::string> m_info;

    void resizeBoard();
};

#endif //GOMOKU_GAMEBOARD_HPP
