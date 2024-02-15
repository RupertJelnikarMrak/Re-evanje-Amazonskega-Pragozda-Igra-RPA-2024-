#include "RenderWindow.hpp"

#include "helper/Vec.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <spdlog/spdlog.h>

SDL_Texture *RenderWindow::loadTexture(const char *pPath)
{
    spdlog::debug("RenderWindow::loadTexture: {}", pPath);
    return IMG_LoadTexture(_renderer, pPath);
}

// Setters and Getters

void RenderWindow::setSize(Vec2<int> pSize)
{
    spdlog::debug("RenderWindow::setSize: {}", pSize);
    _width = pSize.x;
    _height = pSize.y;
    SDL_SetWindowSize(_window, _width, _height);
}

Vec2<int> RenderWindow::getSize() const
{
    return Vec2<int>(_width, _height);
}

void RenderWindow::setPosition(Vec2<int> pPosition)
{
    spdlog::debug("RenderWindow::setPosition: {}", pPosition);
    _x = pPosition.x;
    _y = pPosition.y;
    SDL_SetWindowPosition(_window, _x, _y);
}

Vec2<int> RenderWindow::getPosition() const
{
    return Vec2<int>(_x, _y);
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
    _window = SDL_CreateWindow(pTitle, pX, pY, pW, pH, pFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

RenderWindow::RenderWindow(const char *pTitle, int pW, int pH, bool pFullscreen)
    : _width(pW), _height(pH), _isFullscreen(pFullscreen)
{
    _window = SDL_CreateWindow(pTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, pW, pH, pFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);
    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
}