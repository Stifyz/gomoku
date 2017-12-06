//
// Created by 53915 on 01/12/2017.
//

#include <iostream>
#include "Brain.hpp"

Brain::Brain(const std::shared_ptr <Game> game) : m_protocol(game), m_ai(game) {
    // m_receive = std::async(std::launch::async, getInput);
}

void Brain::run() {
    Application app;
    while (app.isRunning()) {
        m_protocol.processOutput(m_ai.think());
        // TODO: Resolv problem with std::future for multithreading getInput
        std::string receive = getMyInput();
        m_protocol.processInput(receive);
    }
}
