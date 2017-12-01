//
// Created by zimmer_n on 30/11/2017.
//

#include <utility>

#include "Game.hpp"

Game::Game() {}

Game::Game(const unsigned int size) {
    m_isSquare = true,
    m_boardHeight = m_boardWidth = size;
}

Game::Game(const unsigned int height, const unsigned int width) {
    m_isSquare = false;
    m_boardHeight = height;
    m_boardWidth = width;
}

void Game::addInfo(const std::string &key, const std::string &value) {
    auto it = m_info.find(key);
    if (it == m_info.end())
        m_info.insert(std::make_pair(key, value));
    else
        m_info.at(key) = value;
}

const std::string &Game::getInfo(const std::string &key) {
    auto it = m_info.find(key);
    if (it == m_info.end())
        return "";
    else
        return m_info.at(key);
}

int Game::boardGet(const unsigned int x, const unsigned int y) {
    if (x >= m_boardWidth || y >= m_boardHeight)
        return -1;
    return m_board[y][x];
}

bool Game::boardSet(const unsigned int x, const unsigned int y, const int value) {
    if (x >= m_boardWidth || y >= m_boardHeight || value < 0)
        return false;
    m_board[y][x] = value;
    m_isEmptyBoard = false;
    return true;
}

void Game::size(const int size) {
    m_isSquare = true;
    m_boardHeight = size;
    m_boardWidth = size;
    resizeBoard();
}

int Game::size() {
    if (m_isSquare)
        return m_boardHeight;
    else
        return -1;
}

void Game::height(const int height) {
    m_boardHeight = height;
    if (m_boardHeight != m_boardWidth)
        m_isSquare = false;
    else
        m_isSquare = true;
    resizeBoard();
}

int Game::height() {
    return m_boardHeight;
}

void Game::width(const int width) {
    m_boardWidth = width;
    if (m_boardHeight != m_boardWidth)
        m_isSquare = false;
    else
        m_isSquare = true;
    resizeBoard();
}

int Game::width() {
    return m_boardWidth;
}

bool Game::isSquare() {
    return m_isSquare;
}

bool Game::isEmptyBoard() {
    return m_isEmptyBoard;
}

// Private Functions

void Game::resizeBoard() {
    for (std::size_t y = 0; y < m_boardHeight; y++) {
        if (y >= m_board.size())
            m_board.push_back(std::vector<unsigned int>());
        for (std::size_t x = 0; x < m_boardWidth; x++) {
            if (x >= m_board[y].size())
                m_board[y].push_back(0);
        }
        for (std::size_t x = m_board[y].size(); x > m_boardWidth; x--)
            m_board[y].pop_back();
    }
    for (std::size_t y = m_board.size(); y > m_boardHeight; y--)
        m_board.pop_back();
}