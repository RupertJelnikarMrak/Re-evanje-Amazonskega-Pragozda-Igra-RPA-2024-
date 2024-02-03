#include "Game.hpp"

#include <spdlog/spdlog.h>

int Game::init()
{
    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: ", SDL_GetError());
        return 1;
    }

    spdlog::info("Initializing SDL Window");
    SDL_Window *window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        spdlog::critical("Failed to create window: ", SDL_GetError());
        SDL_Quit();
        return -1;
    }

    spdlog::info("Initializing SDL Renderer");
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        spdlog::critical("Failed to create renderer: ", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    while (window != nullptr);
    spdlog::info("Exiting");
    SDL_Quit();
};