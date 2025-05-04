#include "engine/controller.h"

void engine_processInput(SDL_Event *e, Controller *controller)
{
    const bool *currentKeyStates = SDL_GetKeyboardState(NULL);
    controller->directionInput.y = 0;
    controller->directionInput.x = 0;

    if (currentKeyStates[SDL_SCANCODE_UP])
    {
        controller->directionInput.y -= 1;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN])
    {
        controller->directionInput.y += 1;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT])
    {
        controller->directionInput.x -= 1;
    }
    if (currentKeyStates[SDL_SCANCODE_RIGHT])
    {
        controller->directionInput.x += 1;
    }
}