#include "HAL/HALWindowGLFW.h"

#include <iostream>
#include <ostream>

HALWindowGLFW::HALWindowGLFW() : window(nullptr){}

void HALWindowGLFW::Initialize()
{
    if (!glfwInit())
    {
        std::cerr << "Failed to initialize GLFW" << '\n';
        exit(EXIT_FAILURE);
    }

    window = glfwCreateWindow(800, 600, "Window", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Failed to create GLFW window" << '\n';
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
}

void HALWindowGLFW::Update()
{
    glfwPollEvents();
}

bool HALWindowGLFW::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void HALWindowGLFW::SwapBuffers()
{
    glfwSwapBuffers(window);
}

void HALWindowGLFW::Shutdown()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

GLFWwindow* HALWindowGLFW::GetGLFWWindow() const
{
    return window;
}

