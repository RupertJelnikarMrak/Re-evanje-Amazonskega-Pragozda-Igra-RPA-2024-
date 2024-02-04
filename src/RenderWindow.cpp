#include "RenderWindow.hpp"

#include <spdlog/spdlog.h>
#include <SDL2/SDL.h>
#include <string>

int RenderWindow::init()
{
    _window = SDL_CreateWindow(
        _title.c_str(),
        (_windowPosX == -1) ? SDL_WINDOWPOS_UNDEFINED : _windowPosX,
        (_windowPosY == -1) ? SDL_WINDOWPOS_UNDEFINED : _windowPosY,
        _width,
        _height,
        _isFullscreen ? SDL_WINDOW_FULLSCREEN_DESKTOP : SDL_WINDOW_SHOWN);

    if (_window == nullptr)
    {
        spdlog::error("Failed to create window: {}", SDL_GetError());
        return -1;
    }

    _renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

    if (_renderer == nullptr)
    {
        spdlog::error("Failed to create renderer: {}", SDL_GetError());
        return -1;
    }

    return 0;
}

// * Constructors and Destructors

RenderWindow::RenderWindow()
{
    _window = nullptr;
    _renderer = nullptr;
}

RenderWindow::RenderWindow(const char *pTitle, int pWidth, int pHeight, bool pIsFullscreen)
{
    _title = pTitle;
    _width = pWidth;
    _height = pHeight;
    _isFullscreen = pIsFullscreen;
    _windowPosX = -1;
    _windowPosY = -1;
    spdlog::info("Successfully created RenderWindow: " + _title);
};

RenderWindow::RenderWindow(const char *pTitle, int pWidth, int pHeight, int pWindowPosX, int pWindowPosY, bool pIsFullscreen)
{
    _title = pTitle;
    _width = pWidth;
    _height = pHeight;
    _isFullscreen = pIsFullscreen;
    _windowPosX = pWindowPosX;
    _windowPosY = pWindowPosY;
    spdlog::info("Successfully created RenderWindow: " + _title);
};

RenderWindow::~RenderWindow()
{
    SDL_DestroyRenderer(_renderer);
    SDL_DestroyWindow(_window);
    spdlog::info("Successfully destructed RenderWindow: " + _title);
}

// * All of the getters and setters

std::string RenderWindow::getTitle() { return _title; }

int RenderWindow::getWidth() { return _width; };

int RenderWindow::getHeight() { return _height; };

bool RenderWindow::isFullscreen() { return _isFullscreen; };

int RenderWindow::getWindowPosX() { return _windowPosX; };

int RenderWindow::getWindowPosY() { return _windowPosY; };
