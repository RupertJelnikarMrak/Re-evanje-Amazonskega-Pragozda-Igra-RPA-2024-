#pragma once

#include "RenderWindow.hpp"

class Scene
{
protected:
    RenderWindow *_rWindow;

    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

public:
    Scene(RenderWindow *);
    virtual ~Scene() {};

    virtual void runCycle();
};



class TestScene: public Scene
{
private:
    void handleInput() override;
    void update() override;
    void render() override;

public:
    TestScene(RenderWindow * pRenderWindow) : Scene(pRenderWindow) {}
    ~TestScene() override {}
};