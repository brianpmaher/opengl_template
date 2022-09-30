#include <stdlib.h>
#include "./graphics.h"

#pragma warning(push, 0)
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma warning(pop)

static GLFWwindow *window;

void InitWindow(int width, int height, const char *windowName)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if (window == NULL)
    {
        // TODO: LogError
        glfwTerminate();
        exit(-1);
    }

    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        // TODO: LogError
        exit(-1);
    }

    glViewport(0, 0, width, height);
}

void CloseWindow(void)
{
    glfwTerminate();
}

bool WindowShouldClose(void)
{
    glfwPollEvents();
    return glfwWindowShouldClose(window);
}

void StartDrawing(void)
{
}

void EndDrawing(void)
{
    glfwSwapBuffers(window);
}
