#pragma once

#include <SDL3/SDL.h>
#include "math.h"

struct Game;

typedef struct Ball
{
    Vector2 position;
    Vector2 direction;
    float speed;
    float radius;
    bool isColliding;
} Ball;

void game_updateBall(struct Game *game, double dt, Ball *ball);
void game_renderBall(SDL_Renderer *renderer, Ball *ball);

Rect game_getBallBounds(Ball *ball);