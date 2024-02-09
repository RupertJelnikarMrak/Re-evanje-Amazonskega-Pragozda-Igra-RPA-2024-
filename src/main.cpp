#include "Game.hpp"
#include "helper/Constants.hpp"
#include "logging/Logging.hpp"

int main(int argc, char *argv[])
{
    Const::init(); // Create the constants

    Logging::init(); // Set up the Logging system

    Game *game = new Game;

    game->init(); // Initialize a new game instance

    delete game;

    return 0;
}