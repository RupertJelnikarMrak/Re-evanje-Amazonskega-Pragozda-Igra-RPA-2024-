#include "scenes/BaseScene.hpp"

void BaseScene::runCycle()
{
    handleInput();
    update();
    render();
}