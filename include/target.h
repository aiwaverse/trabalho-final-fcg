#pragma once
#include "cube.h"
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

struct target : public cube
{
    bool spawned {false};

    target(const char* path) : cube(path){};

    bool rotated_y{true};

    // +1.0 e 0.5 porque a bala é muito rápida, e pode "pular" o alvo em um frame
    // Isso acaba por tornar o alvo mais "grosso" em código, mas não no modelo
    virtual float getSizeX() override
    {
        if (rotated_y)
            return scalez + 1.0;
        return scalex + 1.0;
    }

    virtual float getSizeY() override
    {
        return scaley;
    }

    virtual float getSizeZ() override
    {
        if (rotated_y)
            return scalex + 0.5;
        return scalez + 0.5;
    }

    virtual glm::mat4 getModel() override
    {
        if (rotated_y)
            return cube::getModel() * Matrix_Rotate_Y(M_PI_2);
        else return cube::getModel();
    }
};
