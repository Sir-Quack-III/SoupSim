#pragma once

#include <iostream>

struct Vector2f
{
    Vector2f()
    :x(0.0f), y(0.0f)
    {}

    Vector2f(float px, float py)
    :x(px), y(py)
    {}

    void print()
    {
        std::cout << x << "," << y << std::endl;
    }


    float x, y;
};