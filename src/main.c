#include <SDL3/SDL.h>

#include "engine/engine.h"

int main(int argc, char *args[])
{
    Game game = {};

    engine_init(&game);

    if (game.initSuccessful)
    {
        engine_run(&game);
    }

    engine_cleanup(&game);

    if (!game.initSuccessful)
    {
        return -1;
    }

    return 0;
}