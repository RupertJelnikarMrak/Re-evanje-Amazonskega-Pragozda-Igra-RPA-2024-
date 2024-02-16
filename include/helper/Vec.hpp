#pragma once

#include <ostream>
#include <string>

namespace vec
{
    template <typename T>
    class Vec2
    {
    public:
        T x, y;

        Vec2(int pX, int pY) : x(pX), y(pY) {}

        std::string to_string() const
        {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }        
    };
}