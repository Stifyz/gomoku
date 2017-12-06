//
// Created by 53915 on 01/12/2017.
//


#ifndef GOMOKU_APPLICATION_HPP
#define GOMOKU_APPLICATION_HPP

class Application {
public:
    static Application &getInstance();
    void start();
    void stop();
    bool isRunning() const;

private:
    Application &operator=(const Application &);
    Application(const Application &);

    Application();
    bool m_isRunning;
    static Application m_app;
};


#endif //GOMOKU_APPLICATION_HPP
