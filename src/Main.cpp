#include <stdexcept>
#include <iostream>

#include "Game.h"

int main(int argc, char* argv[])
{
    Game game;

    try {
        game.run();
    } catch (std::runtime_error& e) {
        std::cout << "------- Stopping on exception -------" << std::endl;
        std::cout << e.what() << std::endl;
        return -1;
    }

    return 0;
}