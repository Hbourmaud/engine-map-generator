#pragma once

#include "HALWindowGLFW.h"

class HALFactory
{
    public:
        static HALWindow* CreateWindowHAL();
};