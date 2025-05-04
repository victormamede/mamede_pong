#pragma once

#include <SDL3/SDL.h>

typedef struct Vector2
{
  float x;
  float y;
} Vector2;

typedef struct Vector2i
{
  int x;
  int y;
} Vector2i;

typedef struct Rect
{
  float x;
  float y;
  float w;
  float h;
} Rect;

void engine_vec2Add(Vector2 *a, const Vector2 b);
void engine_vec2Sub(Vector2 *a, const Vector2 b);
void engine_vec2Mult(Vector2 *a, const float b);
float engine_vec2LenSqr(Vector2 a);
float engine_vec2Len(Vector2 a);
void engine_vec2Normalize(Vector2 *a);

/**
 * @param out The collision vector, add this to rect b position to stop colliding
 *
 * @return If the collision was successful
 */
bool engine_checkAABB(Rect a, Rect b, Vector2 *out);