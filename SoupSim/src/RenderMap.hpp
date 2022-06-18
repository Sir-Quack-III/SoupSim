#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <RenderWin.hpp>
#include <Entity.hpp>
#include <iostream>

void RenderMap(RenderWin Win,  SDL_Texture* Tile);
void PlaceTile(int x, int y);