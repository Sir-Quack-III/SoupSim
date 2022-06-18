#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

class RenderWin
{
public:
    RenderWin(const char* WinTitle, int WinWidth, int WinHeight);
    SDL_Texture* LoadTexture(const char* FilePath);

    int getRefreshRate();

    void Clean();
    void Clear();
    void Render(Entity& Entity);
    void Display();
    void ReRender(Entity& Entity);
    void RenderTex(int x, int y, SDL_Texture* Tex);

    SDL_Renderer* GetRenderer() { return Renderer; }
    SDL_Window* GetWin() { return Win; }
private:
    SDL_Window* Win;
    SDL_Renderer* Renderer;
};