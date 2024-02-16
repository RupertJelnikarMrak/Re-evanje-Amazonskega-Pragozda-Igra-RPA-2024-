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
    static struct GameError
    {
        int code;
        const char *message;
    } _latestError;

    static void run(); // Runs the game loop
    static void quit(); // Cleans up and exits the program

public:
    Game() = delete;
    Game(const Game &) = delete;

    static void init(); // Called to start the game
    static void stop(); // Called to stop the game

    static Scene *getCurrentScene();
    static void setCurrentScene(Scene *scene);

    static const GameError &getError();
    static void setError(int code, const char *error);
};