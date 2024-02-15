#include "Game.hpp"
#include "helper/Constants.hpp"
#include "logging/Logging.hpp"

int main(int argc, char *argv[])
{
    Logging::init(); // Set up the Logging system

    Game::init(); // Initialize the game

    return 0;
}