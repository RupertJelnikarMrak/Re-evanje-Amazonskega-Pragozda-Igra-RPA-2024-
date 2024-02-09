#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "RenderWindow.hpp"

class BaseScene
{
protected:
    RenderWindow *_rWindow;
    bool _isRunning;

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

    virtual void quit();

public:
    BaseScene(RenderWindow *pRenderWindow);
    virtual ~BaseScene();

    virtual void run();
    virtual void stop();
};