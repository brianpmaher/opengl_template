#pragma once

#include <stdbool.h>

void InitWindow(int width, int height, const char *windowName);

void CloseWindow(void);

bool WindowShouldClose(void);

void StartDrawing(void);

void EndDrawing(void);
