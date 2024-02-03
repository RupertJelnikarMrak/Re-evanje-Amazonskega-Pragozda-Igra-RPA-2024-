#pragma once

#include "GameBase.hpp"
#include "entities/EntityBase.hpp"

class Game : public GameBase
{
public:
    int init() override;

protected:
    int mainMenuLoop();
    int gameLoop();
    int pollEvents();
    int update();
    int render(EntityBase *entity);
};