#include <iostream>
#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>

#include "Game.hpp"

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: ", SDL_GetError());
        return 1;
    }

    Game saving_amazon;

    int code = saving_amazon.init();

    SDL_Quit();
    return code;
}