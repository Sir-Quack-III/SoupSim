#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"
#include "Movement.hpp"

class Entity
{
public:
    Entity(Vector2f pPos, SDL_Texture* pTex);
    Vector2f& getPos()
    {
        return pos;
    }
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
    void setPos(Vector2f pPos);
private:
    Vector2f pos;
    SDL_Rect CurrentFrame;
    SDL_Texture* Tex;
};