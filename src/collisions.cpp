#include "collisions.h"

// A escala não funciona do jeito que eu esperava (ela aumenta "pra cada lado"), e mudar a divisão para só um dos cubos resolve isso
// Admito que não sei explicar porque isso resolve
bool cubeToCubeCollision(cube &cube1, cube &cube2)
{
    if (fabs(cube1.posx - cube2.posx) < (cube1.getSizeX() / 2 + cube2.getSizeX()))
    {
        /*
        std::cout << "X: "
                  << fabs(cube1.posx - cube2.posx)
                  << " < "
                  << (cube1.getSizeX() / 2 + cube2.getSizeX())
                  << " = "
                  << (fabs(cube1.posx - cube2.posx) < (cube1.getSizeX() / 2 + cube2.getSizeX()))
                  << "\n";
        */
        if (fabs(cube1.posy - cube2.posy) < (cube1.getSizeY() / 2 + cube2.getSizeY()))
        {
            /*
            std::cout << "Y: "
                      << fabs(cube1.posy - cube2.posy)
                      << " < "
                      << (cube1.getSizeY() / 2 + cube2.getSizeY())
                      << " = "
                      << (fabs(cube1.posy - cube2.posy) < (cube1.getSizeY() / 2 + cube2.getSizeY()))
                      << "\n";
            */
            if (fabs(cube1.posz - cube2.posz) < (cube1.getSizeZ() / 2 + cube2.getSizeZ()))
            {
                /*
                std::cout << "Z: "
                          << fabs(cube1.posz - cube2.posz)
                          << " < "
                          << (cube1.getSizeZ() / 2 + cube2.getSizeZ())
                          << " = "
                          << (fabs(cube1.posz - cube2.posz) < (cube1.getSizeZ() / 2 + cube2.getSizeZ()))
                          << "\n";
                */
                return true;
            }
        }
    }
    return false;
}

bool cubeToCylinderCollision(cube &c, cylinder &cy)
{
    if (fabs(c.posx - cy.posx) < cy.getSizeX() + c.getSizeX())
    {
        /*
        std::cout << "X: "
                  << fabs(c.posx - cy.posx)
                  << " < "
                  << (cy.getSizeX() + c.getSizeX())
                  << " = "
                  << (fabs(c.posx - cy.posx) < (cy.getSizeX() + c.getSizeX()))
                  << "\n";
        */
        if (fabs(c.posy - cy.posy) < cy.getSizeY() + c.getSizeY())
        {
            if (fabs(c.posz - cy.posz) < cy.getSizeZ() + c.getSizeZ())
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
                  << (cy.getSizeX() + c.getSizeX())
                  << " = "
                  << (fabs(c.posx - cy.posx) < (cy.getSizeX() + c.getSizeX()))
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

bool sphereToCubeCollision(sphere &s, cube &c)
{
    /*
    std::cout << "X: "
              << fabs(s.pos.x - c.posx)
              << " < "
              << (c.getSizeX() + s.radius)
              << " = "
              << (fabs(s.pos.x - c.posx) < (c.getSizeX() + s.radius))
              << "\n";
    */
    if (fabs(s.pos.x - c.posx) < c.getSizeX() + s.radius)
    {
        /*
        std::cout << "Y: "
                  << fabs(s.pos.y - c.posy)
                  << " < "
                  << (c.getSizeY() + s.radius)
                  << " = "
                  << (fabs(s.pos.y - c.posy) < (c.getSizeY() + s.radius))
                  << "\n";
        */
        if (fabs(s.pos.y - c.posy) < c.getSizeY() + s.radius)
        {
            /*
            std::cout << "Z: "
                      << fabs(s.pos.z - c.posz)
                      << " < "
                      << (c.getSizeZ() + s.radius)
                      << " = "
                      << (fabs(s.pos.z - c.posz) < (c.getSizeZ() + s.radius))
                      << "\n";
            */
            if (fabs(s.pos.z - c.posz) < c.getSizeZ() + s.radius)
            {
                return true;
            }
        }
    }
    return false;
}
