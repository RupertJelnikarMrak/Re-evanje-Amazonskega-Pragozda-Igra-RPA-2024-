#pragma once

#include <SDL2/SDL.h>

class GameBase
{
protected:
    SDL_Window *window;
    SDL_Renderer *renderer;

public:
    virtual int init() = 0;
};