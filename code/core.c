#include "./core.h"

#include "./trace_log.h"

#include <stdlib.h>

#pragma warning(push, 0)
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#pragma warning(pop)

static GLFWwindow *window;

void ForceCloseApplication(void)
{
    CloseWindow();
    exit(-1);
}

void SetWindowResizable(bool isResizable)
{
    glfwWindowHint(GLFW_RESIZABLE, isResizable);
}

static void HandleWindowResize(GLFWwindow *_window, int width, int height)
{
    _window;

    glViewport(0, 0, width, height);
}

void InitWindow(int width, int height, const char *windowName)
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if (window == NULL)
    {
        FatalLog("Unable to create window.");
        ForceCloseApplication();
    }

    glfwSetFramebufferSizeCallback(window, HandleWindowResize);

    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        FatalLog("Unable to load OpengGL.");
        ForceCloseApplication();
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

void SetWindowShouldClose(bool shouldClose)
{
    glfwSetWindowShouldClose(window, shouldClose);
}

void BeginDrawing(void)
{
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void EndDrawing(void)
{
    glfwSwapBuffers(window);
}

bool IsKeyDown(KeyboardKey key)
{
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool IsKeyUp(KeyboardKey key)
{
    return glfwGetKey(window, key) == GLFW_RELEASE;
}
