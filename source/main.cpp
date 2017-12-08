#include <Brain.hpp>
#include <ctime>

int main() {
    srand(time(NULL));
    std::shared_ptr<Game> game(new Game);
    Brain brain(game);
    brain.run();
    return 0;
}