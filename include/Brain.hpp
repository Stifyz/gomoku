//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_BRAIN_HPP
#define GOMOKU_BRAIN_HPP

#include "Application.hpp"
#include "AI.hpp"

#include <memory>
// #include <future>
#include <iostream>

class Brain {
public:
    Brain(const std::shared_ptr<Game> game);

    void run();
    std::string getMyInput() {
        std::string str;
        std::getline(std::cin, str);
        return str;
    }
private:
    Protocol m_protocol;
    // std::future<std::string> m_receive;
    AI m_ai;
};


#endif //GOMOKU_BRAIN_HPP
