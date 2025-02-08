#pragma once

#include <GLFW/glfw3.h>
#include "HALWindow.h"

class HALWindowGLFW : public HALWindow
{
    private:
        GLFWwindow* window;

    public:
        HALWindowGLFW();

        GLFWwindow* GetGLFWWindow() const;
        void Initialize() override;
        bool ShouldClose() override;
        void Shutdown() override;
        void SwapBuffers() override;
        void Update() override;
};
