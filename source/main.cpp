#include <Brain.hpp>

int main() {
    std::shared_ptr<Game> game(new Game);
    Brain brain(game);
    brain.start();
    brain.run();
    return 0;
}