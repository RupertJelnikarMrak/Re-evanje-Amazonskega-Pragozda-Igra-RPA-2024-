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
    std::string _latestError;
    
    static void run();
public:
    Game() = delete;
    Game(const Game &) = delete;

    static BaseScene *getCurrentScene();
    static void setCurrentScene(BaseScene *scene);

    static void getError();
    static void setError(const char *error);

    static void init();
};