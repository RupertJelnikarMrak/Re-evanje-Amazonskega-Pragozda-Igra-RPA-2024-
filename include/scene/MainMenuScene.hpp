#pragma once

#include "../RenderWindow.hpp"
#include "SceneBase.hpp"

class MainMenuScene : public SceneBase
{
private:
    int pollEvents() override;
    int update() override;
    int render() override;

public:
    MainMenuScene(RenderWindow *pRenderWindow);

    int run() override;
};