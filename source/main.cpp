#include <Brain.hpp>

int main() {
    std::shared_ptr<Game> game(new Game);
    Brain brain(game);
    brain.run();
    return 0;
}