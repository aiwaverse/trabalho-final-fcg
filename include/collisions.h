#pragma once
#include "cube.h"
#include <cmath>
#include <iostream>

bool cubeToCubeCollision(cube &cube1, cube &cube2)
{
    if (fabs(cube1.posx - cube2.posx) < (0.5 * (cube1.scalex + 1) + 0.5 * (cube2.scalex + 1)))
    {
        std::cout << "X: "
                  << fabs(cube1.posx - cube2.posx)
                  << " < "
                  << (0.5 * cube1.scalex + 0.5 * cube2.scalex)
                  << " = "
                  << (fabs(cube1.posx - cube2.posx) < (0.5 * cube1.scalex + 0.5 * cube2.scalex))
                  << "\n";
        if (fabs(cube1.posy - cube2.posy) < (0.5 * (cube1.scaley + 1) + 0.5 * (cube2.scaley + 1)))
        {
            std::cout << "Y: "
                      << fabs(cube1.posy - cube2.posy)
                      << " < "
                      << (0.5 * cube1.scaley + 0.5 * cube2.scaley)
                      << " = "
                      << (fabs(cube1.posy - cube2.posy) < (0.5 * cube1.scaley + 0.5 * cube2.scaley))
                      << "\n";
            if (fabs(cube1.posz - cube2.posz) < (0.5 * (cube1.scalez + 1) + 0.5 * (cube2.scalez + 1)))
            {
                std::cout << "Z: "
                          << fabs(cube1.posz - cube2.posz)
                          << " < "
                          << (0.5 * cube1.scalez + 0.5 * cube2.scalez)
                          << " = "
                          << (fabs(cube1.posz - cube2.posz) < (0.5 * cube1.scalez + 0.5 * cube2.scalez))
                          << "\n";
                return true;
            }
        }
    }
    return false;
}