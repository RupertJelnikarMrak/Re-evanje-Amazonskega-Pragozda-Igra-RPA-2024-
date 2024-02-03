#include "GameStages/GameStageBase.hpp"

GameStageBase::GameStageBase(SDL_Window *window, SDL_Renderer *renderer)
{
    WINDOW = window;
    RENDERER = renderer;
}