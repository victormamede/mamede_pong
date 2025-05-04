#pragma once

#include <SDL3/SDL.h>
#include "paddle.h"
#include "ball.h"
#include "controller.h"

typedef struct Game
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool initSuccessful;

    Vector2i screenSize;
    Paddle paddles[2];
    Ball ball;
    Controller controller;
} Game;

void engine_gameInit(Game *game);
void engine_gameUpdate(Game *game, double dt);
void engine_gameRender(Game *game, SDL_Renderer *renderer);
