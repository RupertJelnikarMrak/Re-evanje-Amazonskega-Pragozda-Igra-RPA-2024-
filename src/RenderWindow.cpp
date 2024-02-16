#include "RenderWindow.hpp"

#include "helper/Vec.hpp"
#include "Game.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <spdlog/spdlog.h>

SDL_Texture *RenderWindow::loadTexture(const char *pPath)
{
    spdlog::debug("RenderWindow::loadTexture: {}", pPath);
    return IMG_LoadTexture(_renderer, pPath);
}

// Setters and Getters

void RenderWindow::setSize(vec::Vec2<int> pSize)
{
    spdlog::debug("RenderWindow::setSize: {}", pSize.c_str());
    _width = pSize.x;
    _height = pSize.y;
    SDL_SetWindowSize(_window, _width, _height);
}

vec::Vec2<int> RenderWindow::getSize() const
{
    return vec::Vec2<int>(_width, _height);
}

void RenderWindow::setPosition(vec::Vec2<int> pPosition)
{
    spdlog::debug("RenderWindow::setPosition: {}", pPosition.c_str());
    _x = pPosition.x;
    _y = pPosition.y;
    SDL_SetWindowPosition(_window, _x, _y);
}

vec::Vec2<int> RenderWindow::getPosition() const
{
    return vec::Vec2<int>(_x, _y);
}

void RenderWindow::setFullscreen(bool pFullscreen)
{
    _isFullscreen = pFullscreen;
    SDL_SetWindowFullscreen(_window, _isFullscreen ? SDL_WINDOW_FULLSCREEN : 0);
}

bool RenderWindow::isFullscreen() const
{
    return _isFullscreen;
}

// Constructors and Destructors

RenderWindow::RenderWindow(const char *pTitle, int pW, int pH, int pX, int pY, bool pFullscreen)
    : _width(pW), _height(pH), _x(pX), _y(pY), _isFullscreen(pFullscreen)
{
    spdlog::info("Opening window: {}", pTitle);
    _window = SDL_CreateWindow(pTitle, pX, pY, pW, pH, pFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        spdlog::critical("Failed to create window: {}", SDL_GetError());
        Game::setError(-1, "Failed to create window: " + *SDL_GetError());
        Game::stop();
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr)
    {
        spdlog::critical("Failed to create renderer: {}", SDL_GetError());
        Game::setError(-1, "Failed to create renderer: " + *SDL_GetError());
        Game::stop();
    }
}

RenderWindow::RenderWindow(const char *pTitle, int pW, int pH, bool pFullscreen)
    : _width(pW), _height(pH), _isFullscreen(pFullscreen)
{
    spdlog::info("Opening window: {}", pTitle);
    _window = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pW, pH, pFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        spdlog::critical("Failed to create window: {}", SDL_GetError());
        Game::setError(-1, "Failed to create window: " + *SDL_GetError());
        Game::stop();
    }
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (_renderer == nullptr)
    {
        spdlog::critical("Failed to create renderer: {}", SDL_GetError());
        Game::setError(-1, "Failed to create renderer: " + *SDL_GetError());
        Game::stop();
    }
}

RenderWindow::~RenderWindow()
{
    spdlog::info("Closing window: {}", SDL_GetWindowTitle(_window));
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}