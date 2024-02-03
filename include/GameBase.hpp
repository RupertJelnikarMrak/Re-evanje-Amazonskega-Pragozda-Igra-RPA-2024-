#pragma once
#include <SDL2/SDL.h>
#include <String>

class GameBase
{
private:
    std::string _title;

    static SDL_Window *_window;
    static SDL_Renderer *_renderer;

protected:
    virtual bool loadAssets() = 0;
    virtual void input() = 0;
    virtual void update() = 0;
    virtual void draw() = 0;

public:
    ~GameBase();

    int run();

    static int SCREEN_WIDTH;
    static int SCREEN_HEIGHT;

private:
};