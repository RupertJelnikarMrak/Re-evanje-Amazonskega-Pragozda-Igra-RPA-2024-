#include "scenes/Scenes.hpp"
#include "Game.hpp"
#include "helper/Vec.hpp"

#include <SDL2/SDL.h>

void TestScene::handleInput()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_QUIT:
            Game::stop();
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            case SDLK_ESCAPE:
                Game::stop();
                break;

            case SDLK_SPACE:
                _rWindow->setFullscreen(!_rWindow->isFullscreen());
                break;

            case SDLK_p:
                {
                    vec::Vec2 pos = _rWindow->getPosition();
                    pos.y += 10;
                    _rWindow->setPosition(pos);
                }
                break;

            case SDLK_r:
                {
                    vec::Vec2<int> size = _rWindow->getSize();
                    size.y += 10;
                    _rWindow->setSize(size);
                }
                break;
            }
            break;
        }
    }
}

void TestScene::update()
{
}

void TestScene::render()
{
}