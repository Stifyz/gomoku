//
// Created by Dydimox on 06/12/2017.
//

#include "Application.hpp"

Application Application::m_app = Application();

Application &Application::getInstance() { return m_app; }

void Application::start() { m_isRunning = true; }

void Application::stop() { m_isRunning = false; }

bool Application::isRunning() const { return m_isRunning; }

Application &Application::operator=(const Application &app) {}

Application::Application(const Application &app) {}

Application::Application() { m_isRunning = false; }

