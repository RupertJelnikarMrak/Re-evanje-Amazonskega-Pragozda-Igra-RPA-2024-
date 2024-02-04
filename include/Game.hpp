#pragma once

#include "GameBase.hpp"

class Game : public GameBase
{
public:
    int init() override;

    Game();
    ~Game() override;
};