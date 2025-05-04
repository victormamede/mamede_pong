#pragma once

#include <SDL3/SDL.h>
#include <stdbool.h>
#include "math.h"
#include "game.h"

void engine_init(Game *game);
void engine_run(Game *game);
void engine_cleanup(Game *game);
