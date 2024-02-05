#include "Game.hpp"

#include "scene/MainMenuScene.hpp"

int Game::run()
{
    _rWindow = new RenderWindow("Saving Amazon Rainforest", 1280, 720, false);
    if (_rWindow->init() != 0)
        return -1;

    MainMenuScene *mainMenuScene = new MainMenuScene(_rWindow);

    if (int returnCode = mainMenuScene->run())
    {
        delete mainMenuScene;
        return returnCode;
    }

    delete mainMenuScene;
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