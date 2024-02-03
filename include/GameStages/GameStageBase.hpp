#pragma once

#include <SDL2/SDL.h>

class GameStageBase
{
protected:
    const SDL_Window *WINDOW;
    const SDL_Renderer *RENDERER;

public:
    GameStageBase(SDL_Window *, SDL_Renderer *);
    virtual ~GameStageBase() = 0;

protected:
    virtual int processInput() = 0;
    virtual int update() = 0;
    virtual int render() = 0;
};