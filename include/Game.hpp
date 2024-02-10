#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>

#include "RenderWindow.hpp"

class Game
{
private:
    static RenderWindow *rWindow;
    
    static void run();
    static void handleInput();
    static void update();
    static void render();
public:
    Game() = delete;
    Game(const Game &) = delete;

    static void init();

};