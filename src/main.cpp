#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <spdlog/spdlog.h>

#include "Game.hpp"

int main(int argc, char *argv[])
{
    Game mainGame;

    return mainGame.init();
}