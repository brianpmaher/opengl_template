#pragma warning(disable: 5045) // Not bounds-checking.

#include "./math.h"

float Clamp(float value, float min, float max)
{
    if (value < min) return min;
    if (value > max) return max;
    return value;
}
