#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWin
{
public:
    RenderWin(const char* WinTitle, int WinWidth, int WinHeight);
    SDL_Texture* LoadTexture(const char* FilePath);
    void Clean();
    void Clear();
    void Render(Entity& Entity);
    void Display();
private:
    SDL_Window* Win;
    SDL_Renderer* Renderer;
};