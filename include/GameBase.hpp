#pragma once

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

class GameBase
{
protected:
    RenderWindow *renderWindow;
    bool isRunning;

public:
    GameBase();
    virtual ~GameBase();
    virtual int init() = 0;
};