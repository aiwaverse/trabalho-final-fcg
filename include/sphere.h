#pragma once
#include "objmodel.h"
#include "matrices.h"

// Headers das bibliotecas OpenGL
#include <glad/glad.h>  // Criação de contexto OpenGL 3.3
#include <GLFW/glfw3.h> // Criação de janelas do sistema operacional
struct sphere
{
    glm::vec3 pos{};
    float radius{0.5};
    bool spawned{false};
    ObjModel obj;
    glm::vec4 view{};

    sphere(const char *path) : obj(path){};

    void setMovement(glm::vec4 v)
    {
        view = v;
    }

    glm::mat4 getModel()
    {
        return Matrix_Identity() * Matrix_Translate(pos.x, pos.y, pos.z) * Matrix_Scale(radius * 2, radius * 2, radius * 2);
    }

    void setPos(float x, float y, float z)
    {
        pos.x = x;
        pos.y = y;
        pos.z = z;
    }

    glm::vec4 getPos()
    {
        return glm::vec4(pos.x, pos.y, pos.z, 0.0);
    }

    void loadPosVec(const glm::vec4 &new_pos)
    {
        pos.x = new_pos.x;
        pos.y = new_pos.y;
        pos.z = new_pos.z;
    }
};