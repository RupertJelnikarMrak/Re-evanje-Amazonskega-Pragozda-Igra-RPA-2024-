#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

#include "RenderWindow.hpp"
#include "scenes/Scenes.hpp"

class Game
{
private:
    static RenderWindow *_rWindow;
    static Scene *_currentScene;
    static bool _isRunning;
    static const char *_latestError;

    static void run();
    static void quit();

public:
    Game() = delete;
    Game(const Game &) = delete;

    static void init();
    static void stop();

    static Scene *getCurrentScene();
    static void setCurrentScene(Scene *scene);

    static const char *getError();
    static void setError(const char *error);
};