#pragma once

#include "helper/Vec.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
private:
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    int _width;
    int _height;
    int _x;
    int _y;
    bool _isFullscreen;

public:
    RenderWindow(const char *pTitle, int pW, int pH, int pX, int pY, bool pFullscreen);
    RenderWindow(const char *pTitle, int pW, int pH, bool pFullscreen);

    ~RenderWindow();

    void setSize(vec::Vec2<int> pSize);
    vec::Vec2<int> getSize() const;

    void setPosition(vec::Vec2<int> pPosition);
    vec::Vec2<int> getPosition() const;

    void setFullscreen(bool pFullscreen);
    bool isFullscreen() const;

    /*-------------------------------------------------------*/

    SDL_Texture *loadTexture(const char *pPath);
    void drawTexture(SDL_Texture *pTexture, vec::Vec2<int> pPos, vec::Vec2<int> pSrcSize, vec::Vec2<int> pDstSize);
};