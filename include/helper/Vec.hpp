#pragma once

#include <ostream>

namespace vec
{
    template <typename T>
    class Vec2
    {
    public:
        T x, y;

        Vec2(int pX, int pY) : x(pX), y(pY) {}

        char const* c_str() const
        {
            return '(' + x + ", " + y + ')';
        }
    };
}