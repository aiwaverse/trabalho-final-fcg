#pragma once
#include "cube.h"
#include <cmath>


bool cubeToCubeCollision(cube& cube1, cube& cube2)
{
    if (abs(cube1.posx - cube2.posx) < (0.5 * cube1.scalex + 0.5 * cube2.scalex))
    {
        if (abs(cube1.posy - cube2.posy) < (0.5 * cube1.scaley + 0.5 * cube2.scaley))
        {
            if (abs(cube1.posz - cube2.posz) < (0.5 * cube1.scalez + 0.5 * cube2.scalez))
                return true;
        }
    }
    return false;
}