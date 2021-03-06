//
// Created by zimmer_n on 30/11/2017.
//

#include <utility>
#include <iostream>

#include "Game.hpp"

Game::Game() {
    fillLists();
    m_info.insert(std::make_pair<std::string, std::string>("NONE", ""));
}

Game::Game(const unsigned int size) {
    this->size(size);
    Game();
}

Game::Game(const unsigned int height, const unsigned int width) {
    this->width(width);
    this->height(height);
    Game();
}

void Game::addInfo(const std::string &key, const std::string &value) {
    auto it = m_info.find(key);
    if (it == m_info.end())
        m_info.insert(std::make_pair(key, value));
    else
        m_info.at(key) = value;
}

const std::string &Game::getInfo(const std::string &key) const {
    auto it = m_info.find(key);
    if (it == m_info.end())
        return m_info.at("NONE");
    else
        return m_info.at(key);
}

int Game::boardGet(const unsigned int x, const unsigned int y) const {
    if (x >= m_boardWidth || y >= m_boardHeight)
        return -1;
    return m_board[y][x];
}

const std::list<Game::Pos> &Game::getAllEmptyPos() const {
    return m_emptyPos;
}

const std::list<Game::Pos> &Game::getAllMyPos() const {
    return m_myPos;
}

const std::list<Game::Pos> &Game::getAllOpponentPos() const {
    return m_opponentPos;
}

const std::list<Game::Pos> &Game::getAllUnknownPos() const {
    return m_unknownPos;
}

const std::list<Game::Pos> &Game::getAllPlayablePos() {
    return m_playablePos;
}

bool Game::isPlayable(std::list<Game::Pos> &filledList, const Pos pos) {
    for (std::list<Pos>::iterator it = filledList.begin(); it != filledList.end(); it++)
        if (isAdjacentTo(*it, pos))
            return true;
    return false;
}

bool Game::isAdjacentTo(Pos pos1, Pos pos2) const {
    return (abs(pos1.x - pos2.y) + abs(pos1.y - pos2.x)) < 3;
}

unsigned int Game::size() const {
    if (m_isSquare)
        return m_boardHeight;
    else
        return -1;
}

unsigned int Game::height() const {
    return m_boardHeight;
}

unsigned int Game::width() const {
    return m_boardWidth;
}

bool Game::isSquare() const {
    return m_isSquare;
}

bool Game::isEmptyBoard() const {
    return m_isEmptyBoard;
}

bool Game::isMyTurn() const {
    return m_isMyTurn;
}

const Game::Pos &Game::lastPlay() const {
    return m_lastPlay;
}

const void Game::printMap() const {
    for (size_t y = 0; y < m_board.size(); y++) {
        for (size_t x = 0; x < m_board[y].size(); x++) {
            switch (m_board[y][x]) {
                case EMPTY_CASE :
                    std::cerr << 'o';
                    break;
                case OWN_STONE :
                    std::cerr << 'x';
                    break;
                case OPPONENT_STONE :
                    std::cerr << '*';
                    break;
                default:
                    std::cerr << '0';
                    break;
            }
        }
        std::cerr << std::endl;
    }
}

// Private Setters

void Game::size(const int size) {
    m_isSquare = true;
    m_boardHeight = size;
    m_boardWidth = size;
    resizeBoard();
    fillLists();
}

void Game::height(const int height) {
    m_boardHeight = height;
    if (m_boardHeight != m_boardWidth)
        m_isSquare = false;
    else
        m_isSquare = true;
    resizeBoard();
    fillLists();
}

void Game::width(const int width) {
    m_boardWidth = width;
    if (m_boardHeight != m_boardWidth)
        m_isSquare = false;
    else
        m_isSquare = true;
    resizeBoard();
}

bool Game::boardSet(const Pos &pos, const int value) {
    if (pos.x >= m_boardWidth || pos.y >= m_boardHeight || value < 0)
        return false;
    swapList(pos, value);
    m_board[pos.y][pos.x] = value;
    m_isEmptyBoard = false;
    m_lastPlay = pos;
    for (auto it = m_playablePos.begin(); it != m_playablePos.end(); it++)
        if (*it == pos)
            m_playablePos.erase(it);
    if (boardGet(pos.x - 1, pos.y - 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x - 1, pos.y - 1));
    if (boardGet(pos.x, pos.y - 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x, pos.y - 1));
    if (boardGet(pos.x + 1, pos.y - 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x + 1, pos.y - 1));
    if (boardGet(pos.x - 1, pos.y) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x - 1, pos.y));
    if (boardGet(pos.x + 1, pos.y) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x + 1, pos.y));
    if (boardGet(pos.x - 1, pos.y + 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x - 1, pos.y + 1));
    if (boardGet(pos.x, pos.y + 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x, pos.y + 1));
    if (boardGet(pos.x + 1, pos.y + 1) == EMPTY_CASE)
        m_playablePos.emplace_back(Game::Pos(pos.x + 1, pos.y + 1));
    m_playablePos.unique();
    //printMap();
    return true;
}

void Game::changeTurn(bool b) {
    m_isMyTurn = b;
}

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

void Game::fillLists() {
    for (size_t y = 0; y < m_boardHeight; y++)
        for (size_t x = 0; x < m_boardWidth; x++) {
            switch (m_board[y][x]) {
                case EMPTY_CASE :
                    m_emptyPos.emplace_back(Pos(x, y));
                    break ;
                case OWN_STONE :
                    m_myPos.emplace_back(Pos(x, y));
                    break ;
                case OPPONENT_STONE :
                    m_opponentPos.emplace_back(Pos(x, y));
                    break ;
                default :
                    m_unknownPos.emplace_back(Pos(x, y));
                    break ;
            }
        }
    /*auto emptyList = getAllEmptyPos();
    std::list<Pos> filledList(getAllMyPos());
    filledList.merge(std::list<Pos>(getAllOpponentPos()));
    filledList.merge(std::list<Pos>(getAllUnknownPos()));
    std::list<Pos> m_playablePos;
    for (auto it = emptyList.begin(); it != emptyList.end(); it++) {
        if (isPlayable(filledList, *it))
            m_playablePos.emplace_back(*it);
    }*/
}

void Game::swapList(const Pos &pos, const int newValue) {
    switch (m_board[pos.y][pos.x]) {
        case EMPTY_CASE :
            m_emptyPos.remove(pos);
            break ;
        case OWN_STONE :
            m_myPos.remove(pos);
            break ;
        case OPPONENT_STONE :
            m_opponentPos.remove(pos);
            break ;
        default :
            m_unknownPos.remove(pos);
            break ;
    }
    switch (newValue) {
        case EMPTY_CASE :
            m_emptyPos.emplace_back(pos);
            break ;
        case OWN_STONE :
            m_myPos.emplace_back(pos);
            break ;
        case OPPONENT_STONE :
            m_opponentPos.emplace_back(pos);
            break ;
        default :
            m_unknownPos.emplace_back(pos);
            break ;
    }
}

