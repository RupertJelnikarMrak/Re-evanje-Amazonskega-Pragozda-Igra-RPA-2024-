#include "scene/SceneBase.hpp"

SceneBase::SceneBase(RenderWindow *pRenderWindow)
{
    _isRunning = false;
    _rWIndow = pRenderWindow;
}