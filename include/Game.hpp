//
// Created by zimmer_n on 30/11/2017.
//

#ifndef GOMOKU_GAMEBOARD_HPP
#define GOMOKU_GAMEBOARD_HPP

#include <list>
#include <map>
#include <string>
#include <vector>

#define MY_TURN true
#define NOT_MY_TURN false

#define EMPTY_CASE 0
#define OWN_STONE 1
#define OPPONENT_STONE 2
#define OTHER_STONE 3

class Game {
public:
    struct Pos {
        Pos(unsigned int x = 0, unsigned int y = 0) : x(x), y(y) {}
        bool operator==(const Pos &pos) { return (this->x == pos.x && this->y == pos.y); }
        bool operator<(const Pos &pos) {
            if (this->y > pos.y)
                return true;
            else if (this->y < pos.y)
                return false;
            else if (this->x > pos.x)
                return true;
            else if (this->x < pos.x)
                return false;
            else
                return false;
        }
        unsigned int x;
        unsigned int y;
        friend std::ostream &operator<<(std::ostream &stream, const Pos &pos) {
            stream << std::to_string(pos.x);
            stream << std::string(" ");
            stream << std::to_string(pos.y);
            return stream;
        }
    };

    // Only usable by Protocol
    class GameSetter {
    public:
        inline static void size(Game &game, const unsigned int size) { game.size(size); }
        inline static void height(Game &game, const unsigned int height) { game.height(height); }
        inline static void width(Game &game, const unsigned int width) { game.height(width); }

        inline static void addInfo(Game &game, const std::string &key, const std::string &value) { game.addInfo(key, value); }
        inline static bool boardSet(Game &game, const Game::Pos &pos, const int value) { game.boardSet(pos, value); }
        inline static void changeTurn(Game &game, bool b) { game.changeTurn(b); }
    };

    friend Game::GameSetter;

    Game();
    Game(const unsigned int size);
    Game(const unsigned int height, const unsigned int width);

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
    bool isAdjacentTo(Pos pos1, Pos pos2) const;

    int size() const;
    int height() const;
    int width() const;
    bool isSquare() const;
    bool isEmptyBoard() const;
    bool isMyTurn() const;
    // !Board Management

    const Pos &lastPlay() const;

    const void printMap() const;
private:
    bool m_isMyTurn = false;
    bool m_isSquare = true;
    int m_boardHeight = 0;
    int m_boardWidth = 0;
    bool m_isEmptyBoard = true;
    Pos m_lastPlay;

    std::list<Pos> m_emptyPos;
    std::list<Pos> m_myPos;
    std::list<Pos> m_opponentPos;
    std::list<Pos> m_unknownPos;
    std::list<Pos> m_playablePos;

    std::vector<std::vector<unsigned int>> m_board;
    std::map<std::string, std::string> m_info;

    void size(const int size);
    void height(const int height);
    void width(const int width);

    void addInfo(const std::string &key, const std::string &value);
    bool boardSet(const Pos &pos, const int value);
    void changeTurn(bool b);

    void resizeBoard();
    void fillLists();
    void swapList(const Pos &pos, const int newValue);
};

#endif //GOMOKU_GAMEBOARD_HPP
