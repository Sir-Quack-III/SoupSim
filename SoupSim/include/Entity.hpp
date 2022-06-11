#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class Entity
{
public:
    Entity(float px, float py, SDL_Texture* pTex);
    float getX();
    float getY();
    SDL_Texture* getTex();
    SDL_Rect getCurrentFrame();
private:
    float x, y;
    SDL_Rect CurrentFrame;
    SDL_Texture* Tex;
};