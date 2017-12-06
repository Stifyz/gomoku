//
// Created by 53915 on 01/12/2017.
//

static bool m_isRunning;

#ifndef GOMOKU_APPLICATION_HPP
#define GOMOKU_APPLICATION_HPP

class Application {
public:
    virtual ~Application() {}
    void start() { m_isRunning = true; }
    void stop() { m_isRunning = false; }
    bool isRunning() { return m_isRunning; }
private:
};

#endif //GOMOKU_APPLICATION_HPP
