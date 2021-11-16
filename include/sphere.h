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
    bool spawned{false};
    ObjModel obj;
    glm::vec4 view{};


    sphere(const char *path): obj(path){};

    void setMovement(glm::vec4 v){
        view = v;
    }

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

    glm::vec4 getPos()
    {
        return glm::vec4(posx, posy, posz, 0.0);
    }

    void loadPosVec(const glm::vec4& new_pos)
    {
        posx = new_pos.x;
        posy = new_pos.y;
        posz = new_pos.z;
    }

};