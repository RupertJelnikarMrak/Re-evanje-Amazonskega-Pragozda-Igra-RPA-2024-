#pragma once

#include <SDL2/SDL.h>

class RenderWindow
{
    SDL_Window *window;
    SDL_Renderer *renderer;

    const char *TITLE;
    int WIDTH;
    int HEIGHT;
    bool IS_FULLSCREEN;

public:
    RenderWindow(const char *title, int width, int height, bool fullscreen = false);
    ~RenderWindow();
    int init();
    void cleanUp();
};