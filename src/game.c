#include "engine/game.h"
#include "engine/collisions.h"
#include "engine/configs.h"

void engine_gameInit(Game *game)
{
    game->paddles[0] = (Paddle){
        .position = {.x = MAP_PADDING, .y = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2.0},
        .size = {.x = PADDLE_WIDTH, .y = PADDLE_HEIGHT},
        .speed = PADDLE_SPEED,
    };

    game->paddles[1] = (Paddle){
        .position = {.x = SCREEN_WIDTH - PADDLE_WIDTH - MAP_PADDING, .y = (SCREEN_HEIGHT - PADDLE_HEIGHT) / 2.0},
        .size = {.x = PADDLE_WIDTH, .y = PADDLE_HEIGHT},
        .speed = PADDLE_SPEED,
    };

    game->ball = (Ball){
        .position = {.x = SCREEN_WIDTH / 2, .y = SCREEN_HEIGHT / 2},
        .radius = BALL_RADIUS,
        .direction = {.x = -1, .y = 0},
        .speed = BALL_SPEED,
    };
}

void engine_gameUpdate(Game *game, double dt)
{
    game_inputPaddle(game, &game->paddles[0]);
    game_aiPaddle(game, &game->paddles[1]);

    game_processCollisions(game);

    game_updatePaddle(game, dt, &game->paddles[0]);
    game_updatePaddle(game, dt, &game->paddles[1]);

    game_updateBall(game, dt, &game->ball);
}

void engine_gameRender(Game *game, SDL_Renderer *renderer)
{
    game_renderPaddle(renderer, &game->paddles[0]);
    game_renderPaddle(renderer, &game->paddles[1]);

    game_renderBall(renderer, &game->ball);
}