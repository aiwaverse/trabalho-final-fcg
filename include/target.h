#pragma once
#include "cube.h"
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

struct target : public cube
{
    bool spawned {false};

    target(const char* path) : cube(path){};

    glm::mat4 getModel()
    {
        return cube::getModel() * Matrix_Rotate_Y(M_PI_2);
    }
};
