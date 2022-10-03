#include "./core.h"

int main(void)
{
    InitWindow(1280, 720, "Game");

    while (!WindowShouldClose())
    {
        if (IsKeyDown(KEY_ESCAPE))
            SetWindowShouldClose(true);

        StartDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
