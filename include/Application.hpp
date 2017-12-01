//
// Created by 53915 on 01/12/2017.
//

#ifndef GOMOKU_APPLICATION_HPP
#define GOMOKU_APPLICATION_HPP

class Application {
public:
    virtual ~Application() {}
    void start() { m_isRunning = true; }
    void stop() { m_isRunning = false; }

protected:
    bool isRunning() { return m_isRunning; }

private:
    bool m_isRunning;
};

#endif //GOMOKU_APPLICATION_HPP
