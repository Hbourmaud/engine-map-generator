#include <GLFW/glfw3.h>

#include "HAL/HALFactory.h"
#include "HAL/HALWindow.h"

int main(void)
{
    HALWindow* window = HALFactory::CreateWindowHAL();
    window->Initialize();

    while (!window->ShouldClose())
    {
        glClear(GL_COLOR_BUFFER_BIT);

        window->SwapBuffers();
        window->Update();
    }

    window->Shutdown();
    delete window;
    
    return 0;
}
