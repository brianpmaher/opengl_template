#include "./graphics.h"

int main(void)
{
    InitWindow(1280, 720, "Game");

    while (!WindowShouldClose())
    {
        StartDrawing();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
