#pragma once

#include <SDL2/SDL.h>

#include "RenderWindow.hpp"

class GameStageBase
{
protected:
    RenderWindow *renderWindow;

public:
    GameStageBase(RenderWindow *pRenderWindow);
    virtual ~GameStageBase() = 0;

protected:
    virtual int pollEvents() = 0;
    virtual int update() = 0;
    virtual int render() = 0;
};