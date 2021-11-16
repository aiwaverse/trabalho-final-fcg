#pragma once
struct cylinder
{
    float posx{};
    float posy{};
    float posz{};
    float radius{1};
    float height{1};

    cylinder(float x, float y, float z) : posx(x), posy(y), posz(z){};
    cylinder() : cylinder(0, 0, 0){};
    const float getSizeX()
    {
        return radius;
    }

    const float getSizeY()
    {
        return height;
    }

    const float getSizeZ()
    {
        return radius;
    }

    void setPos(float x, float y, float z)
    {
        posx = x;
        posy = y;
        posz = z;
    }
};