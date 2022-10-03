#pragma once

#include <stdbool.h>

#include "./input.h"

void InitWindow(int width, int height, const char *windowName);

void CloseWindow(void);

bool WindowShouldClose(void);

void SetWindowShouldClose(bool value);

void StartDrawing(void);

void EndDrawing(void);

bool IsKeyDown(KeyboardKey key);

bool IsKeyUp(KeyboardKey key);
