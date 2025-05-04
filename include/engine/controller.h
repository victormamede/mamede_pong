#pragma once

#include <SDL3/SDL.h>
#include "math.h"

typedef struct Controller
{
    Vector2i directionInput;
} Controller;

void engine_processInput(SDL_Event *e, Controller *controller);