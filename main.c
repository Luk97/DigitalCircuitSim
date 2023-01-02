#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <stdio.h>

#define true 1
#define false 0

int main()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    IMG_Init(IMG_INIT_PNG);

    SDL_Window* window;
    SDL_Renderer* renderer;

    window = SDL_CreateWindow("Temp", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    int running = true;

    while(running)
    {
        SDL_Event e;
        while(SDL_PollEvent(&e))
        {
            switch(e.type)
            {
                case SDL_QUIT: {
                    running = false;
                    break;
                }
            }
        }

        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 110, 110, 110, 255);
        SDL_RenderPresent(renderer);
    }

    IMG_Quit();
    SDL_Quit();
    return 0;
}