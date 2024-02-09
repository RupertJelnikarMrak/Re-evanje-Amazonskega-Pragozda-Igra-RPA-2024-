#include "scene/BaseScene.hpp"

BaseScene::BaseScene(RenderWindow *pRenderWindow)
{
    this->_rWindow = pRenderWindow;
}

BaseScene::~BaseScene()
{
    if (_isRunning)
        quit();
}

void BaseScene::run()
{
    while (_isRunning)
    {
        this->handleInput();
        this->update();
        this->render();
    }
}

void BaseScene::stop()
{
    this->quit();
}

void BaseScene::quit()
{
    this->_isRunning = false;
}