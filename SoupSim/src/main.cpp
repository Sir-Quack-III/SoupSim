//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWin.hpp"
#include "Entity.hpp"
 
int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL Cannot be initializied! ERR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG library cannot be initialized! ERR: " << SDL_GetError() << std::endl;

    RenderWin Win("Soup Simulator v1.0", 1280, 720);

    SDL_Texture* GrassTexture = Win.LoadTexture("./res/img/GrassTile.png");

    std::vector<Entity> Entities;

    {
        Entity Maurice(100,50, GrassTexture);
        Entities.push_back(Maurice);
    }

    bool GameRunning = true;

    SDL_Event Event;

    while (GameRunning)
    {
        while (SDL_PollEvent(&Event)) // Asks for event info
        {
            if (Event.type == SDL_QUIT) GameRunning = false; // If game is stopped, then it stops (???)
        }

        Win.Clear();
        
        for (Entity& e : Entities)
        {
            Win.Render(e);
        }

        Win.Display();
    }
    
    Win.Clean();
    SDL_Quit();

    return 0;
}