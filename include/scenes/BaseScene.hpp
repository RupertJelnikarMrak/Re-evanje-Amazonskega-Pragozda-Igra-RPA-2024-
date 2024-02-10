#pragma once

#include "RenderWindow.hpp"

class BaseScene
{
protected:
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

public:
    BaseScene(RenderWindow *);

    virtual void runCycle();
};