#include "Game.hpp"
#include "scenes/BaseScene.hpp"
#include "events/EventBus.hpp"
#include "events/Events.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>
#include <iostream>

RenderWindow *Game::_rWindow = nullptr;
BaseScene *Game::_currentScene = nullptr;
const char *Game::_latestError = nullptr;

bool Game::_isRunning = false;

void Game::init()
{
    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: " + *SDL_GetError());
        setError("Failed to initialize SDL: " + *SDL_GetError());
        return;
    }
    else
        spdlog::info("SDL2 initialized successfully");

    _rWindow = new RenderWindow("Saving Amazon Forest", 500, 500, -1, -1, true);

    //run();

    SDL_Quit();
}

void Game::run()
{
    _isRunning = true;
    while (_isRunning)
    {
        _currentScene->runCycle();
    }
}

void Game::setError(const char *error)
{
    _latestError = error;
}

const char *Game::getError()
{
    return _latestError;
}

BaseScene *Game::getCurrentScene()
{
    return _currentScene;
}

void Game::setCurrentScene(BaseScene *pScene)
{
    _currentScene = pScene;
}