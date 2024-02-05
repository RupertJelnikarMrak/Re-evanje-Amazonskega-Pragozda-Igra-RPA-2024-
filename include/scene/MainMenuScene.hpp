#pragma once

#include "SceneBase.hpp"

class MainMenuScene : public SceneBase
{
private:
    int pollEvents() override;
    int update() override;
    int render() override;

public:
    MainMenuScene(RenderWindow *pRenderWindow);
    ~MainMenuScene() override;

    int run() override;
};