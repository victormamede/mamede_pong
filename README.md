# Mamede Pong – Pong Game in C

A minimal, efficient implementation of the classic Pong game using **C** and **SDL3**. The game features a modular design, simple build process, and clean input/rendering logic using SDL.

## Features

- Classic Pong gameplay
- Player 2 is controlled by a basic AI
- SDL3-based rendering and input
- Text rendering with SDL_ttf
- Modular architecture (engine, game logic, entities, input, math)
- Uses only stack memory (no dynamic allocation)

## Project Structure

```

mamede\_pong/
├── assets/               # Fonts and game assets
├── include/              # Header files
├── src/                  # Source files
│   ├── main.c
│   ├── game.c
│   ├── engine.c
│   ├── paddle.c
│   ├── ball.c
│   ├── controller.c
│   ├── collisions.c
│   └── math.c
├── vendor/
│   └── SDL\_ttf/          # SDL\_ttf source or submodule
├── CMakeLists.txt
└── README.md

````

## Build Instructions

### Prerequisites

- C compiler (e.g., gcc, clang)
- CMake 3.10 or newer
- SDL3 (found via CMake package config)
- SDL_ttf (included as a subdirectory)

### Steps

```bash
git clone git@github.com:victormamede/mamede_pong.git
cd mamede_pong
mkdir build && cd build
cmake ..
cmake --build .
````

Assets will be copied automatically to the build output directory.

## AI Logic

Player 2 is controlled by a simple AI that adjusts its paddle's vertical velocity to follow the ball:

```c
void game_aiPaddle(struct Game *game, Paddle *paddle)
{
    paddle->velocity.y = SDL_clamp(
        (game->ball.position.y - (paddle->position.y + (paddle->size.y / 2))) * 0.05,
        -1,
        1);
}
```

This creates a responsive but (maybe) beatable opponent.

## Controls

* **Player 1:** Up and Down arrow keys
* **Player 2:** AI-controlled
* **Quit:** Escape key

## License

This project is licensed under the MIT License. See the `LICENSE` file for details.
