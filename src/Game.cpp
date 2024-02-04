#include "Game.hpp"

#include <spdlog/spdlog.h>

int Game::init()
{
    spdlog::info("Creating SDL Window");

    renderWindow = &RenderWindow("Savin Amazon Rainforest", 500, 500, false);

    isRunning = true;

    SDL_Event event;
    while (isRunning)
        while(SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                isRunning = false;

    spdlog::info("Exiting");

    return 0;
};

Game::Game() : GameBase()
{

}