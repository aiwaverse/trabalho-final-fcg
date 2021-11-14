#pragma once
#include "matrices.h"
#include "objmodel.h"

// Headers das bibliotecas OpenGL
#include <glad/glad.h>  // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h> // Criação de janelas do sistema operacional

class cube
{
private:
    GLuint posx{};
    GLuint posy{};
    GLuint posz{};
    GLuint scalex{1};
    GLuint scaley{1};
    GLuint scalez{1};
public:
    ObjModel cubemodel;
    cube(const char *path);
    ~cube();

    glm::mat4 getModel();
};

cube::cube(const char *path) : cubemodel(path)
{
    
}

glm::mat4 cube::getModel()
{
    return Matrix_Identity() * Matrix_Translate(posx, posy, posz) * Matrix_Scale(scalex, scaley, scalez);
}

cube::~cube()
{
}
