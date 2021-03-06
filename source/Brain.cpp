//
// Created by 53915 on 01/12/2017.
//

#include <iostream>
#include "Brain.hpp"

Brain::Brain(const std::shared_ptr <Game> game) : m_game(game), m_protocol(game), m_ai(game) {
    // m_receive = std::async(std::launch::async, getInput);
}

void Brain::run() {
    bool        b = true;
    Application &app = Application::getInstance();
    while (!app.isRunning() && b) {
        std::string receive = getMyInput();
        //std::cout << receive << std::endl;
        m_protocol.processInput(receive);
        while (app.isRunning()) {
            b = false;
            if (m_game->isMyTurn())
                m_protocol.processOutput(m_ai.think());
            // TODO: Resolv problem with std::future for multithreading getInput
            std::string receive = getMyInput();
            //std::cout << receive << std::endl;
            m_protocol.processInput(receive);
        }
    }
}
