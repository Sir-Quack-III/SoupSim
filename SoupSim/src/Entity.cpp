#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"

Entity::Entity(float px, float py, SDL_Texture* pTex)
:x(px), y(py), Tex(pTex)
{
    CurrentFrame.x = 0;
    CurrentFrame.y = 0;
    CurrentFrame.w = 16;
    CurrentFrame.h = 16;
}

float Entity::getX()
{
    return x;
}
float Entity::getY()
{
    return y;
}

SDL_Texture* Entity::getTex()
{
    return Tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return CurrentFrame;
}