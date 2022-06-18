//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "Entity.hpp"
#include "Utils.hpp"
// #include "Globals.hpp"
#include "RenderWin.hpp"
#include "RenderMap.hpp"

RenderWin Win("Soup Simulator v1.0", 1280, 720);

void Move(Vector2f pStartPos, Vector2f pDestination, Entity Ent)
{
    // int xDiff = pDestination.x - pStartPos.x;
    // int yDiff = pDestination.y - pStartPos.y;

    // for (int i = 0; i < 4; i++)
    // {
    //     float cxPos = Ent.getPos().x; // current x pos
    //     float cyPos = Ent.getPos().y; // current y pos
    //     Ent.setPos(Vector2f(cxPos + (xDiff / 4), cyPos + (yDiff / 4)));
    //     SDL_Delay(7);
    //     Win.ReRender(Ent);
    // }

    Ent.setPos(pDestination);
}
 
int main(int argc, char* argv[])
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        std::cout << "SDL Cannot be initializied! ERR: " << SDL_GetError() << std::endl;

    if (!(IMG_Init(IMG_INIT_PNG)))
        std::cout << "IMG library cannot be initialized! ERR: " << SDL_GetError() << std::endl;


    SDL_Texture* GrassTexture = Win.LoadTexture("./res/img/GrassTile.png");
    SDL_Texture* PlayerTexture = Win.LoadTexture("./res/img/Player1.png");

    // std::vector<Entity> Entities;

    Entity Maurice(Vector2f(0,0), PlayerTexture);

    bool GameRunning = true;

    SDL_Event Event;

    const float timeStep = 0.01f;
    float accumulator = 0.0f;
    float currentTime = utils::hireTimeInSeconds();

    while (GameRunning)
    {
        float cxPos = Maurice.getPos().x; // current x pos
        float cyPos = Maurice.getPos().y; // current y pos
        int starTicks = SDL_GetTicks();

        int Vel = 8;

        float newTime = utils::hireTimeInSeconds();
        float frameTime = newTime - currentTime;

        currentTime = newTime;

        accumulator += frameTime;

        

        while (accumulator >= timeStep) // "time to update dumbass"
        {

            while (SDL_PollEvent(&Event)) // Asks for event info
            {
                if (Event.type == SDL_QUIT)GameRunning = false; // If game is stopped, then it stops (???)
                else if (Event.type == SDL_KEYDOWN)
                {
                    if (Event.key.keysym.sym == SDLK_q)
                    {
                        if (Vel == Vel * 4) Vel = 16;
                        else Vel *= 4;
                        std::cout << "Balls" << std::endl;
                    }
                    switch (Event.key.keysym.sym)
                    {
                        case SDLK_w:
                            Move(Vector2f(cxPos, cyPos), Vector2f(cxPos, cyPos - Vel), Maurice);
                            Maurice.setPos(Vector2f(cxPos, cyPos - Vel));
                            SDL_Delay(10);
                            break;
                        
                        case SDLK_a:
                            Move(Vector2f(cxPos, cyPos), Vector2f(cxPos - Vel, cyPos), Maurice);
                            Maurice.setPos(Vector2f(cxPos - Vel, cyPos));
                            SDL_Delay(10);
                            break;
                        
                        case SDLK_s:
                            Move(Vector2f(cxPos, cyPos), Vector2f(cxPos, cyPos + Vel), Maurice);
                            Maurice.setPos(Vector2f(cxPos, cyPos + Vel));
                            SDL_Delay(10);
                            break;

                        case SDLK_d:
                            Move(Vector2f(cxPos, cyPos), Vector2f(cxPos + Vel, cyPos), Maurice);
                            Maurice.setPos(Vector2f(cxPos + Vel, cyPos));
                            SDL_Delay(10);
                            break;
                    }
                }
            }

            accumulator -= timeStep;
        }

        const float alpha = accumulator / timeStep;

        Win.Clear();
        
        // for (Entity& e : Entities)
        // {
        //     Win.Render(e);
        // }
        
        RenderMap(Win, GrassTexture);
        Win.Render(Maurice);

        Win.Display();

        int frameTicks = SDL_GetTicks() - starTicks;

        if (frameTicks < 1000 / Win.getRefreshRate()) SDL_Delay(1000 / Win.getRefreshRate());
    }
    
    Win.Clean();
    SDL_Quit();

    return 0;
}