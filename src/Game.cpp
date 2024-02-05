#include "Game.hpp"

int Game::run()
{
    _rWindow = new RenderWindow("Saving Amazon Rainforest", 1280, 720, false);
    if (_rWindow->init() != 0)
        return -1;

    return 0;
}

Game::Game()
{
    _isRunning = false;
}

Game::~Game()
{
    delete _rWindow;
}