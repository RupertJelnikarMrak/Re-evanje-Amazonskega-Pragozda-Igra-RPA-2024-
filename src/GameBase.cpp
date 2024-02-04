#include "GameBase.hpp"

GameBase::GameBase()
{
    renderWindow = nullptr;
    isRunning = false;
}

GameBase::~GameBase()
{
    renderWindow->cleanUp();
}