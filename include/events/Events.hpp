#pragma once

#include <string>

class GameEvent
{
protected:
    std::string name;
public:
    GameEvent(std::string name) : name(name) {}

    std::string getName() const { return name; }
};

class TestGameEvent : public GameEvent
{
public:
    TestGameEvent(std::string name) : GameEvent(name) {}
};