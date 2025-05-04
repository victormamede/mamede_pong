#include "engine/game.h"
#include "engine/paddle.h"

void game_updatePaddle(Game *game, double dt, Paddle *paddle)
{
    Vector2 delta = paddle->velocity;
    engine_vec2Mult(&delta, dt * paddle->speed);
    engine_vec2Add(&paddle->position, delta);

    if (paddle->position.y + paddle->size.y / 2 < 0)
    {
        paddle->position.y = -paddle->size.y / 2;
    }
    else if (paddle->position.y + (paddle->size.y / 2) > game->screenSize.y)
    {
        paddle->position.y = game->screenSize.y - (paddle->size.y / 2);
    }
}

void game_inputPaddle(struct Game *game, Paddle *paddle)
{
    paddle->velocity.y = game->controller.directionInput.y;
}

void game_aiPaddle(struct Game *game, Paddle *paddle)
{
    paddle->velocity.y = SDL_clamp(
        (game->ball.position.y - (paddle->position.y + (paddle->size.y / 2))) * 0.05,
        -1,
        1);
}

void game_renderPaddle(SDL_Renderer *renderer, Paddle *paddle)
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_FRect rect = {paddle->position.x,
                      paddle->position.y,
                      paddle->size.x,
                      paddle->size.y};

    SDL_RenderFillRect(renderer, &rect);
}

Rect game_getPaddleBounds(Paddle *paddle)
{
    Rect bounds = {
        .x = paddle->position.x,
        .y = paddle->position.y,
        .w = paddle->size.x,
        .h = paddle->size.y,
    };

    return bounds;
}