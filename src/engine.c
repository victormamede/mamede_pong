#include <SDL3/SDL.h>
#include <SDL3_ttf/SDL_ttf.h>

#include "engine/engine.h"
#include "engine/game.h"
#include "engine/configs.h"
#include "engine/controller.h"

void engine_init(Game *game)
{
    game->renderer = NULL;
    game->window = NULL;
    game->initSuccessful = false;
    game->screenSize = (Vector2i){.x = SCREEN_WIDTH, .y = SCREEN_HEIGHT};

    // Initialize SDL
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    if (!TTF_Init())
    {
        SDL_Log("Couldn't initialise SDL_ttf: %s\n", SDL_GetError());
        return;
    }

    // Create window
    game->window = SDL_CreateWindow("Pong", game->screenSize.x, game->screenSize.y, 0);
    if (game->window == NULL)
    {
        SDL_Log("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    game->renderer = SDL_CreateRenderer(game->window, NULL);
    if (game->renderer == NULL)
    {
        SDL_Log("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return;
    }

    engine_gameInit(game);
    game->initSuccessful = true;
}

void engine_run(Game *game)
{
    Uint64 now = SDL_GetPerformanceCounter();
    Uint64 last = 0;
    double deltaTime = 0.0;

    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        // Calculate delta time
        last = now;
        now = SDL_GetPerformanceCounter();
        deltaTime = (double)((now - last) * 1000) / SDL_GetPerformanceFrequency(); // ms

        // Handle events on queue
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_EVENT_QUIT)
            {
                quit = true;
            }

            engine_processInput(&e, &game->controller);
        }

        engine_gameUpdate(game, deltaTime);

        // Clear screen
        SDL_SetRenderDrawColor(game->renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(game->renderer);

        engine_gameRender(game, game->renderer);

        // Update screen
        SDL_RenderPresent(game->renderer);

        SDL_Delay(16);
    }
}

void engine_cleanup(Game *game)
{
    if (game->renderer != NULL)
    {
        SDL_DestroyRenderer(game->renderer);
        game->renderer = NULL;
    }

    if (game->window != NULL)
    {
        SDL_DestroyWindow(game->window);
        game->window = NULL;
    }

    SDL_Quit();
    TTF_Quit();
}
