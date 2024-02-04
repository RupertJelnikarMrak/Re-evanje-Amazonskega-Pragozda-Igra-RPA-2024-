#include <iostream>
#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: ", SDL_GetError());
        return -1;
    }

    SDL_Quit();
    return 0;
}