#pragma once
#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include <cmath>
#include <iostream>

// A escala não funciona do jeito que eu esperava (ela aumenta "pra cada lado"), e mudar a divisão para só um dos cubos resolve isso
// Admito que não sei explicar porque isso resolve
bool cubeToCubeCollision(cube &cube1, cube &cube2)
{
    if (fabs(cube1.posx - cube2.posx) < (cube1.scalex / 2 + cube2.scalex))
    {
        /*
        std::cout << "X: "
                  << fabs(cube1.posx - cube2.posx)
                  << " < "
                  << (cube1.scalex / 2 + cube2.scalex)
                  << " = "
                  << (fabs(cube1.posx - cube2.posx) < (cube1.scalex / 2 + cube2.scalex))
                  << "\n";
        */
        if (fabs(cube1.posy - cube2.posy) < (cube1.scaley / 2 + cube2.scaley))
        {
            /*
            std::cout << "Y: "
                      << fabs(cube1.posy - cube2.posy)
                      << " < "
                      << (cube1.scaley / 2 + cube2.scaley)
                      << " = "
                      << (fabs(cube1.posy - cube2.posy) < (cube1.scaley / 2 + cube2.scaley))
                      << "\n";
            */
            if (fabs(cube1.posz - cube2.posz) < (cube1.scalez / 2 + cube2.scalez))
            {
                /*
                std::cout << "Z: "
                          << fabs(cube1.posz - cube2.posz)
                          << " < "
                          << (cube1.scalez / 2 + cube2.scalez)
                          << " = "
                          << (fabs(cube1.posz - cube2.posz) < (cube1.scalez / 2 + cube2.scalez))
                          << "\n";
                */
                return true;
            }
        }
    }
    return false;
}

bool cubeToCylinderCollision(const cube &c, cylinder &cy)
{
    if (fabs(c.posx - cy.posx) < cy.getSizeX() + c.scalex)
    {
        /*
        std::cout << "X: "
                  << fabs(c.posx - cy.posx)
                  << " < "
                  << (cy.getSizeX() + c.scalex)
                  << " = "
                  << (fabs(c.posx - cy.posx) < (cy.getSizeX() + c.scalex))
                  << "\n";
        */
        if (fabs(c.posy - cy.posy) < cy.getSizeY() + c.scaley)
        {
            if (fabs(c.posz - cy.posz) < cy.getSizeZ() + c.scalez)
            {
                return true;
            }
        }
    }
    return false;
}

bool cylinderToPlaneCollision(cylinder &cy, plane &p)
{
    if (fabs(p.posx - cy.posx) < cy.getSizeX() + 0.005)
    {
        /*
        std::cout << "X: "
                  << fabs(c.posx - cy.posx)
                  << " < "
                  << (cy.getSizeX() + c.scalex)
                  << " = "
                  << (fabs(c.posx - cy.posx) < (cy.getSizeX() + c.scalex))
                  << "\n";
        */
        if (fabs(p.posy - cy.posy) < cy.getSizeY() + p.scaley)
        {
            if (fabs(p.posz - cy.posz) < cy.getSizeZ() + p.scalez)
            {
                return true;
            }
        }
    }
    return false;
}