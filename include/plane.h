#pragma once
#include "matrices.h"
#include "objmodel.h"
struct plane
{
private:
    ObjModel obj;
    glm::mat4 model_matrix;
public:
    float posx{};
    float posy{};
    float posz{};
    float scalex{1};
    float scaley{1};
    float scalez{1};
    float rotatex{0};
    float rotatey{0};
    float rotatez{0};

    void setPos(float x, float y, float z)
    {
        posx = x;
        posy = y;
        posz = z;
        calculateModelMatrix();
    }

    void loadModel(const char* path)
    {
        obj = ObjModel(path);
    }

    void setScale(float x, float y, float z)
    {
        scalex = x;
        scaley = y;
        scalez = z;
        calculateModelMatrix();
    }

    void calculateModelMatrix()
    {
        model_matrix = Matrix_Translate(posx, posy, posz) * Matrix_Scale(scalex, scaley, scalez) *  Matrix_Rotate_X(rotatex) * Matrix_Rotate_Y(rotatey)  * Matrix_Rotate_Z(rotatez);
        posx = model_matrix[0][0];
        posy = model_matrix[1][1];
        posz = model_matrix[2][2];
    }

    glm::mat4 getModel()
    {
        return model_matrix;
    }
};