#include <RenderWin.hpp>
#include <Entity.hpp>
#include <iostream>

#include "RenderMap.hpp"
#include "Math.hpp"

void RenderMap(RenderWin Win, SDL_Texture* Tile)
{
    int WinWidth;
    int WinHeight;
    SDL_GetWindowSize(Win.GetWin(), &WinWidth, &WinHeight);

    for (int y = 0; y < WinHeight; y += 16)
    {
        for (int x = 0; x < WinWidth; x += 16)
        {
            Win.RenderTex(x, y, Tile);
        }
    }
}