#ifndef BOX2D_PLATFORM_H_
#define BOX2D_PLATFORM_H_

#ifdef __unix__
    #include <Box2D/Box2D.h>
#elif _WIN32
    #include "Box2D.h"
#endif

#endif // BOX2D_PLATFORM_H_
