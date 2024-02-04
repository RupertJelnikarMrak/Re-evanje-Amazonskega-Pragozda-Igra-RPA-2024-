#include "RenderWindow.hpp"

#include <spdlog/spdlog.h>

RenderWindow::RenderWindow(const char *title, int width, int height, bool is_fullscreen)
{
    TITLE = title;
    WIDTH = width;
    HEIGHT = height;
    IS_FULLSCREEN = is_fullscreen;
}

int RenderWindow::init()
{
    window = SDL_CreateWindow(TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, IS_FULLSCREEN ? SDL_WINDOW_FULLSCREEN : SDL_WINDOW_SHOWN);
    if (window == nullptr)
    {
        spdlog::critical("Failed to create window: ", SDL_GetError());
        SDL_Quit();
        return -1;
    }
    return 0;
}

void RenderWindow::cleanUp()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

RenderWindow::~RenderWindow()
{
    if (window != NULL && renderer!= NULL)
        this->cleanUp();
}