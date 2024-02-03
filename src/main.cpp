#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <spdlog/spdlog.h>

#include "Game.hpp"

int main(int argc, char *argv[])
{
    spdlog::set_level(spdlog::level::debug);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S] [%l] %v");

    Game saving_amazon;

    return saving_amazon.init();
}