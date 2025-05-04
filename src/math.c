#include "engine/math.h"

void engine_vec2Add(Vector2 *a, const Vector2 b)
{
    a->x += b.x;
    a->y += b.y;
}

void engine_vec2Sub(Vector2 *a, const Vector2 b)
{
    a->x -= b.x;
    a->y -= b.y;
}

void engine_vec2Mult(Vector2 *a, const float b)
{
    a->x *= b;
    a->y *= b;
}

float engine_vec2LenSqr(Vector2 a)
{
    return a.x * a.x + a.y * a.y;
}

float engine_vec2Len(Vector2 a)
{
    return SDL_sqrtf(engine_vec2LenSqr(a));
}

void engine_vec2Normalize(Vector2 *a)
{
    float length = engine_vec2Len(*a);
    a->x /= length;
    a->y /= length;
}

bool engine_checkAABB(Rect a, Rect b, Vector2 *out)
{
    if (a.x > b.x + b.w)
        return false;

    if (a.x + a.w < b.x)
        return false;

    if (a.y > b.y + b.h)
        return false;

    if (a.y + a.h < b.y)
        return false;

    if (out != NULL)
    {
        // Left, right, top, down
        float distances[] = {
            (b.x + b.w) - a.x,
            (a.x + a.w) - b.x,
            (b.y + b.h) - a.y,
            (a.y + a.h) - b.y,
        };

        int minIndex = 0;
        for (int i = 1; i < 4; i++)
        {
            if (distances[i] < distances[minIndex])
            {
                minIndex = i;
            }
        }
        switch (minIndex)
        {
        case 0:
            out->x = -distances[0];
            out->y = 0;
            break;
        case 1:
            out->x = distances[1];
            out->y = 0;
            break;
        case 2:
            out->x = 0;
            out->y = -distances[2];
            break;
        case 3:
            out->x = 0;
            out->y = distances[3];
            break;
        }
    }

    return true;
}
