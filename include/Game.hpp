#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <unordered_map>
#include <string>

#include "RenderWindow.hpp"
#include "scenes/Scenes.hpp"

namespace Game
{
    namespace
    {
        RenderWindow *_rWindow = nullptr;
        Scene *_currentScene = nullptr;
        bool _isRunning = false;
        struct GameError
        {
            int code;
            const char *message;
        } _latestError;
    }

    void run();  // Runs the game loop
    void quit(); // Cleans up and exits the program

    void init(); // Called to start the game
    void stop(); // Called to stop the game

    Scene *getCurrentScene();
    void setCurrentScene(Scene *scene);

    const GameError &getError();
    void setError(int code, const char *error);
};