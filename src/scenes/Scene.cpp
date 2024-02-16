#include "scenes/Scenes.hpp"
#include "RenderWindow.hpp"

Scene::Scene(RenderWindow *pRenderWindow)
{
    _rWindow = pRenderWindow;
}

void Scene::runCycle()
{
    handleInput();
    update();
    render();
}