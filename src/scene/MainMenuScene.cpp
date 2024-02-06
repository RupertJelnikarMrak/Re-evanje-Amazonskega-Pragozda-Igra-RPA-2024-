#include "scene/MainMenuScene.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>

int MainMenuScene::run()
{
    _isRunning = true;

    while (_isRunning)
    {
        if (int rCode = processInput())
        {
            if (rCode == 7)
            {
                _isRunning = false;
                return 0;
            }
            if (!rCode)
                return rCode;
        }
        if (int rCode = update())
        {
            return rCode;
        }
        if (int rCode = render())
        {
            return rCode;
        }
    }

    return 0;
}

int MainMenuScene::processInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
        if (event.type == SDL_QUIT)
        {
            spdlog::info("Unexpected quit signal");
            return 7; // Return code for unexpected quit
        }

    return 0;
}
int MainMenuScene::update()
{
    return 0;
}
int MainMenuScene::render()
{
    return 0;
}

MainMenuScene::MainMenuScene(RenderWindow *pRenderWindow)
    : SceneBase(pRenderWindow)
{
    _rWIndow = pRenderWindow;
    _isRunning = false;
}