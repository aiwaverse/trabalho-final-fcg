#pragma once
#include "cube.h"
#include <cmath>
#include <iostream>

bool cubeToCubeCollision(cube &cube1, cube &cube2)
{
    if (fabs(cube1.posx - cube2.posx) < (cube1.scalex/2 + cube2.scalex))
    {
        
        std::cout << "X: "
                  << fabs(cube1.posx - cube2.posx)
                  << " < "
                  << ( cube1.scalex/2 +  cube2.scalex)
                  << " = "
                  << (fabs(cube1.posx - cube2.posx) < ( cube1.scalex/2 +  cube2.scalex))
                  << "\n";
        
        if (fabs(cube1.posy - cube2.posy) < ( cube1.scaley/2 +  cube2.scaley))
        {
            
            std::cout << "Y: "
                      << fabs(cube1.posy - cube2.posy)
                      << " < "
                      << ( cube1.scaley/2 +  cube2.scaley)
                      << " = "
                      << (fabs(cube1.posy - cube2.posy) < ( cube1.scaley/2 +  cube2.scaley))
                      << "\n";
            
            if (fabs(cube1.posz - cube2.posz) < ( cube1.scalez/2 +  cube2.scalez))
            {
                
                std::cout << "Z: "
                          << fabs(cube1.posz - cube2.posz)
                          << " < "
                          << ( cube1.scalez/2 +  cube2.scalez)
                          << " = "
                          << (fabs(cube1.posz - cube2.posz) < ( cube1.scalez/2 +  cube2.scalez))
                          << "\n";
                
                return true;
            }
        }
    }
    return false;
}