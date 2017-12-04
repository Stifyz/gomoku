#include <Brain.hpp>

int main() {
    Application app;
    std::shared_ptr<Game> game(new Game);
    Brain brain(game);
    app.start();
    brain.run();
    return 0;
}