#pragma once

#include <SDL3/SDL.h>
#include "math.h"

struct Game;

typedef struct Paddle
{
    Vector2 position;
    Vector2 size;
    Vector2 velocity;

    double speed;
} Paddle;

void game_updatePaddle(struct Game *game, double dt, Paddle *paddle);
void game_inputPaddle(struct Game *game, Paddle *paddle);
void game_aiPaddle(struct Game *game, Paddle *paddle);
void game_renderPaddle(SDL_Renderer *renderer, Paddle *paddle);

Rect game_getPaddleBounds(Paddle *paddle);