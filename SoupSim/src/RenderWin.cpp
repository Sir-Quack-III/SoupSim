#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWin.hpp"
#include "Entity.hpp"

RenderWin::RenderWin(const char* WinTitle, int WinWidth, int WinHeight)
    :Win(NULL), Renderer(NULL)
{
    Win = SDL_CreateWindow(WinTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WinWidth, WinHeight, SDL_WINDOW_SHOWN);

    if (Win == NULL)
    {
        std::cout << "Window failed to initialize! ERR: " << SDL_GetError() << std::endl;
    }

    Renderer = SDL_CreateRenderer(Win, -1, SDL_RENDERER_ACCELERATED);
}

SDL_Texture* RenderWin::LoadTexture(const char* FilePath)
{
    SDL_Texture* Texture = NULL;
    Texture = IMG_LoadTexture(Renderer, FilePath);

    if (Texture == NULL)
        std::cout << "Failed to load texture! ERR: " << SDL_GetError() << std::endl;

    return Texture;
}

void RenderWin::Clean()
{
    SDL_DestroyWindow(Win);
}

void RenderWin::Clear()
{
    SDL_RenderClear(Renderer);
}

void RenderWin::Render(Entity& Entity)
{
    SDL_Rect src; // Defines texture stuff
    src.x = Entity.getCurrentFrame().x;
    src.y = Entity.getCurrentFrame().y;
    src.w = Entity.getCurrentFrame().w;
    src.h = Entity.getCurrentFrame().h;

    SDL_Rect dst; // tells src to exist
    dst.x = Entity.getX() * 4;
    dst.y = Entity.getY() * 4;
    dst.w = Entity.getCurrentFrame().w * 4;
    dst.h = Entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(Renderer, Entity.getTex(), &src, &dst);
}

void RenderWin::Display()
{
    SDL_RenderPresent(Renderer);
}