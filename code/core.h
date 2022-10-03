#pragma once

#include <stdbool.h>

#include "./input.h"

void ForceCloseApplication(void);

void SetWindowResizable(bool isResizable);

void InitWindow(int width, int height, const char *windowName);

void CloseWindow(void);

bool WindowShouldClose(void);

void SetWindowShouldClose(bool shouldClose);

void BeginDrawing(void);

void EndDrawing(void);

bool IsKeyDown(KeyboardKey key);

bool IsKeyUp(KeyboardKey key);
