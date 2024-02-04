#pragma once

#include <SDL2/SDL.h>
#include <string>

class RenderWindow
{
    SDL_Window *_window;
    SDL_Renderer *_renderer;

    std::string _title;
    int _width;
    int _height;
    bool _isFullscreen;
    int _windowPosX;
    int _windowPosY;

public:
    RenderWindow(const char *pTitle, int pWidth, int pHeight, bool pIsFullscreen);
    RenderWindow(const char *pTitle, int pWidth, int pHeight, int pWindowPosX, int pWindowPosY, bool pIsFullscreen);
    ~RenderWindow();

    int init();

    std::string getTitle();
    int getWidth();
    int getHeight();
    bool isFullscreen();
    int getWindowPosX();
    int getWindowPosY();

    // TODO: add setters to allow changing widow properties
};