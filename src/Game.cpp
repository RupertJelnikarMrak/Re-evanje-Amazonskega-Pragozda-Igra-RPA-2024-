#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/rotating_file_sink.h>

void Game::init()
{
    spdlog::info("Initializing SDL2");
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        spdlog::critical("Failed to initialize SDL: ", SDL_GetError());
    }

    run();

    SDL_Quit();
}

void Game::run()
{
    handleInput();
    update();
    render();
}

void Game::handleInput()
{

}

void Game::update()
{

}

void Game::render()
{
    
}