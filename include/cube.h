#pragma once
#include "matrices.h"
#include "objmodel.h"

// Headers das bibliotecas OpenGL
#include <glad/glad.h>  // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h> // Criação de janelas do sistema operacional

struct cube
{
    float posx{};
    float posy{};
    float posz{};
    float scalex{1};
    float scaley{1};
    float scalez{1};
    ObjModel cubemodel;
    cube(const char *path): cubemodel(path) {};

    glm::mat4 getModel()
    {
        return Matrix_Identity() * Matrix_Translate(posx, posy, posz) * Matrix_Scale(scalex, scaley, scalez);
    }

    void setPos(float x, float y, float z)
    {
        posx = x;
        posy = y;
        posz = z;
    }

    void setScale(float x, float y, float z)
    {
        scalex = x;
        scaley = y;
        scalez = z;
    }
};
