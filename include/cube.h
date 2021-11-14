#pragma once
#include "matrices.h"
#include "objmodel.h"

// Headers das bibliotecas OpenGL
#include <glad/glad.h>  // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h> // Criação de janelas do sistema operacional

class cube
{
public:
    float posx{};
    float posy{};
    float posz{};
    float scalex{1};
    float scaley{1};
    float scalez{1};
    ObjModel cubemodel;
    cube(const char *path);
    ~cube();

    glm::mat4 getModel();

    void setPos(float x, float y, float z);

    void setScale(float x, float y, float z);
};

cube::cube(const char *path) : cubemodel(path)
{
    
}

glm::mat4 cube::getModel()
{
    return Matrix_Identity() * Matrix_Scale(scalex, scaley, scalez) * Matrix_Translate(posx, posy, posz);
}

void cube::setScale(float x, float y, float z)
{
    scalex = x;
    scaley = y;
    scalez = z;
}

void cube::setPos(float x, float y, float z)
{
    posx = x;
    posy = y;
    posz = z;
}

cube::~cube()
{
}
