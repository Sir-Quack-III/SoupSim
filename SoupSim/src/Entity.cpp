#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "Entity.hpp"
#include "Movement.hpp"
#include "Globals.hpp"

Entity::Entity(Vector2f pPos, SDL_Texture* pTex)
:pos(pPos), Tex(pTex)
{
    CurrentFrame.x = 0;
    CurrentFrame.y = 0;
    CurrentFrame.w = 16;
    CurrentFrame.h = 16;
}

SDL_Texture* Entity::getTex()
{
    return Tex;
}

SDL_Rect Entity::getCurrentFrame()
{
    return CurrentFrame;
}

void Entity::setPos(Vector2f pPos)
{
    pos = pPos;
}