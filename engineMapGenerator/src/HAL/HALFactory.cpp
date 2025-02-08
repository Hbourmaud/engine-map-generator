#include "HAL\HALFactory.h"

HALWindow* HALFactory::CreateWindowHAL()
{
    return new HALWindowGLFW();
}
