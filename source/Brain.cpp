//
// Created by 53915 on 01/12/2017.
//

#include <iostream>
#include "Brain.hpp"

Brain::Brain(const std::shared_ptr <Game> game) : m_game(game), m_protocol(m_game) {
    // m_receive = std::async(std::launch::async, getInput);
}

void Brain::run() {
    while (isRunning()) {
        AI::Pos pos = m_ai.think();
        m_protocol.processOutput(pos.x, pos.y);
        // TODO: Resolv problem with std::future and get Input from web site
    }
}
