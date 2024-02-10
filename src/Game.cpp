#include "Game.hpp"
#include "scenes/BaseScene.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>

void Game::init()
{
    _latestError = nullptr;

    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: " + *SDL_GetError());
        setError("Failed to initialize SDL: " + *SDL_GetError());
        return;
    }

    _rWindow = new RenderWindow("Saving Amazon Forest", 500, 500, NULL, NULL, true);

    // TODO: Add a default scene before running the loop

    run();

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

BaseScene* Game::getCurrentScene()
{
    return _currentScene;
}

void Game::setCurrentScene(BaseScene* pScene)
{
    _currentScene = pScene;
}