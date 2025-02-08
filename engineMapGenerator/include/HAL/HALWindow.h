#pragma once

#include "HAL.h"

class HALWindow : public HAL
{
    public:
        virtual bool ShouldClose() = 0;
        virtual void SwapBuffers() = 0;
};