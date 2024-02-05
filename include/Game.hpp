#pragma once

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

class Game
{
    RenderWindow *_rWindow;
    bool _isRunning;

public:
    Game();
    ~Game();

    int run();
};