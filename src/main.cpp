#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

int main(int argc, char *argv[])
{
    
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Test Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        std::cout << "Failed to create renderer: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return -1;
    }

    while (window != nullptr);
    SDL_Quit();
    return 0;
}