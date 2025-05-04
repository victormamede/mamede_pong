#pragma once

#include "ball.h"
#include "paddle.h"

struct Game;

void game_processCollisions(struct Game *game);
void game_processBallToPaddleCollision(Ball *ball, Paddle *paddle);
void game_processBallToBoundsCollision(Ball *ball, Vector2i screenSize);