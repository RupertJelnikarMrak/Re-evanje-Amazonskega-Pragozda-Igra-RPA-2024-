#include "Game.hpp"
#include "scenes/Scenes.hpp"
#include "events/EventBus.hpp"
#include "events/Events.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>
#include <iostream>

RenderWindow *Game::_rWindow = nullptr;
Scene *Game::_currentScene = nullptr;
Game::GameError Game::_latestError = Game::GameError(0, nullptr);
bool Game::_isRunning = false;

void Game::init()
{
    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: " + *SDL_GetError());
        setError(-1, "Failed to initialize SDL: " + *SDL_GetError());
        return;
    }

    _rWindow = new RenderWindow("Saving Amazon Forest", 500, 500, -1, -1, true);

    _currentScene = new TestScene(_rWindow);

    run();

    quit();
}

void Game::quit()
{
    delete _currentScene;
    delete _rWindow;
    SDL_Quit();
    spdlog::info("Exiting...");
}

void Game::stop()
{
    spdlog::info("Stopping game loop");
    _isRunning = false;
}

void Game::run()
{
    spdlog::info("Starting game loop");
    _isRunning = true;
    while (_isRunning)
    {
        _currentScene->runCycle();
    }
}

void Game::setError(int pCode, const char *pMessage)
{
    _latestError.code = pCode;
    _latestError.message = pMessage;
}

const Game::GameError &Game::getError()
{
    return _latestError;
}

Scene *Game::getCurrentScene()
{
    return _currentScene;
}

void Game::setCurrentScene(Scene *pScene)
{
    _currentScene = pScene;
}