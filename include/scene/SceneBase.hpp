#pragma once

#include "../RenderWindow.hpp"

class SceneBase
{
protected:
    RenderWindow *_rWIndow;
    bool _isRunning;

    virtual int processInput() = 0;
    virtual int update() = 0;
    virtual int render() = 0;

public:
    SceneBase(RenderWindow *renderWIndow);

    virtual int run() = 0;
};