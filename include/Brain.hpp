//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_BRAIN_HPP
#define GOMOKU_BRAIN_HPP

#include "Application.hpp"
#include "Protocol.hpp"
#include "AI.hpp"

#include <bits/shared_ptr.h>
#include <bits/unique_ptr.h>
#include <future>
#include <iostream>


std::string getInput() {
    std::string str;
    std::getline(std::cin, str);
    return str;
}

class Brain : public Application {
public:
    Brain(const std::shared_ptr<Game> game);

    void run();
private:
    Protocol m_protocol;
    const std::shared_ptr<Game> m_game;
    // std::future<std::string> m_receive);
    AI m_ai;
};

#endif //GOMOKU_BRAIN_HPP
