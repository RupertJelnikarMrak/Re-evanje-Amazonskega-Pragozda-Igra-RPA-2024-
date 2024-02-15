#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

#include "RenderWindow.hpp"
#include "scenes/BaseScene.hpp"

class Game
{
private:
    static RenderWindow *_rWindow;
    static BaseScene *_currentScene;
    static bool _isRunning;
    static const char *_latestError;
    
    static void run();
public:
    Game() = delete;
    Game(const Game &) = delete;

    static BaseScene *getCurrentScene();
    static void setCurrentScene(BaseScene *scene);

    static const char *getError();
    static void setError(const char *error);

    static void init();
};