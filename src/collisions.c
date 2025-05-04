#include "engine/collisions.h"
#include "engine/game.h"

void game_processCollisions(struct Game *game)
{
    game_processBallToPaddleCollision(&game->ball, &game->paddles[0]);
    game_processBallToPaddleCollision(&game->ball, &game->paddles[1]);
    game_processBallToBoundsCollision(&game->ball, game->screenSize);
}

void game_processBallToPaddleCollision(Ball *ball, Paddle *paddle)
{
    Rect ballBounds = game_getBallBounds(ball);
    Rect paddleBounds = game_getPaddleBounds(paddle);

    Vector2 collisionVector;
    bool isColliding = engine_checkAABB(paddleBounds, ballBounds, &collisionVector);

    if (isColliding)
    {
        // Stop colliding
        engine_vec2Add(&ball->position, collisionVector);

        Vector2 newDirection = ball->direction;

        // Reflect
        if (collisionVector.x != 0)
        {
            newDirection.x *= -1;
        }
        if (collisionVector.y != 0)
        {
            newDirection.y *= -1;
        }

        // Add directional force
        Vector2 paddleCenter = {
            .x = paddle->position.x + paddle->size.x / 2.0,
            .y = paddle->position.y + paddle->size.y / 2.0,
        };

        const float DIRECTIONAL_FORCE_AMOUNT = 0.02;
        Vector2 directionalForce = ball->position;
        engine_vec2Sub(&directionalForce, paddleCenter);
        engine_vec2Mult(&directionalForce, DIRECTIONAL_FORCE_AMOUNT);

        engine_vec2Add(&newDirection, directionalForce);

        engine_vec2Normalize(&newDirection);
        ball->direction = newDirection;
    }
}

void game_processBallToBoundsCollision(Ball *ball, Vector2i screenSize)
{
    if (ball->position.y - ball->radius < 0)
    {
        ball->position.y = ball->radius;
        ball->direction.y *= -1;
    }

    if (ball->position.y + ball->radius > screenSize.y)
    {
        ball->position.y = screenSize.y - ball->radius;
        ball->direction.y *= -1;
    }
}