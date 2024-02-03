#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <spdlog/spdlog.h>

#include "RenderWindow.hpp"

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    RenderWindow window("Reševanje Amazonskega Pragozda", 1920, 1080);

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                gameRunning = false;
        }
    }

    spdlog::info("Exiting");
    window.cleanUp();
    SDL_Quit();
    return 0;
}