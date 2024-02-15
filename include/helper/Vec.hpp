#pragma once

#include <ostream>

template <typename T>
class Vec2
{
public:
    T x, y;

    Vec2(int pX, int pY) : x(pX), y(pY) {}

    template <typename OStream>
    inline OStream &operator<<(OStream &os, const Vec2<T> &vec)
    {
        return os << "X: " << vec.x << ", Y: " << vec.y;
    }
};