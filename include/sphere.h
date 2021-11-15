#pragma once
#include "objmodel.h"
#include "matrices.h"

// Headers das bibliotecas OpenGL
#include <glad/glad.h>  // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h> // Criação de janelas do sistema operacional
struct sphere
{
    float posx{};
    float posy{};
    float posz{};
    float scalex{1};
    float scaley{1};
    float scalez{1};
    ObjModel obj;
    sphere(const char *path): obj(path){};

    glm::vec4 movement_view_vector{};

    glm::mat4 getModel();

    void setPos(float x, float y, float z);

    void setScale(float x, float y, float z);

    void setMovement(glm::vec4 v){
        movement_view_vector = v;
    }
};