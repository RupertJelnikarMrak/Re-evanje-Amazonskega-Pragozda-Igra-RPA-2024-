#include "scene/MainMenuScene.hpp"

#include <SDL2/SDL.h>

int MainMenuScene::run()
{
    _isRunning = true;

    SDL_Event event;
    while (_isRunning)
        while (SDL_PollEvent(&event))
            if (event.type == SDL_QUIT)
                _isRunning = false;

    return 0;
}


MainMenuScene::MainMenuScene(RenderWindow *pRenderWindow)
    : SceneBase(pRenderWindow)
{
    
}

MainMenuScene::~MainMenuScene()
{

}