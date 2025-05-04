#include "engine/game.h"
#include "engine/ball.h"

void game_updateBall(Game *game, double dt, Ball *ball)
{
    Vector2 change = ball->direction;
    engine_vec2Mult(&change, ball->speed * dt);

    engine_vec2Add(&ball->position, change);
}

void game_renderBall(SDL_Renderer *renderer, Ball *ball)
{
    if (ball->isColliding)
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    }
    else
    {
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    }
    SDL_FRect rect = {ball->position.x - ball->radius,
                      ball->position.y - ball->radius,
                      ball->radius * 2.0,
                      ball->radius * 2.0};

    SDL_RenderFillRect(renderer, &rect);
}

Rect game_getBallBounds(Ball *ball)
{
    Rect bounds = {
        .x = ball->position.x - ball->radius,
        .y = ball->position.y - ball->radius,
        .w = ball->radius * 2.0,
        .h = ball->radius * 2.0,
    };

    return bounds;
}