#pragma once
#include <random>
#include <chrono>
#include <array>
#include "cube.h"
#ifndef M_PI_2
#define M_PI_2 1.57079632679489661923
#endif

struct target : public cube
{
    std::array<glm::vec3,4> curve_points{};

    bool spawned{false};

    std::chrono::_V2::system_clock::rep now;

    // quanto menor, mais rápdio
    float speed {10};

    float t{0};

    void first_pos()
    {
        std::mt19937 rng(now);
        std::uniform_int_distribution<std::mt19937::result_type> range2to30(2, 20);
        std::uniform_int_distribution<std::mt19937::result_type> range0to4(0, 4);
        std::uniform_int_distribution<std::mt19937::result_type> range0to1(0, 1);

        int signal{};
        if (range0to1(rng) == 0)
            signal = 1;
        else
            signal = -1;

        curve_points[0] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[1] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[2] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[3] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        posx = curve_points[0].x;
        posy = curve_points[0].y;
        posz = curve_points[0].z;

    }

    target(const char *path) : cube(path)
    {
        respawn();
    };

    void respawn()
    {
        using namespace std::chrono;
        spawned = true;
        auto now = system_clock::now().time_since_epoch().count();
        std::mt19937 rng(now);
        std::uniform_int_distribution<std::mt19937::result_type> range2to30(2, 20);
        std::uniform_int_distribution<std::mt19937::result_type> range0to4(0, 4);
        std::uniform_int_distribution<std::mt19937::result_type> range0to1(0, 1);

        int signal{};
        if (range0to1(rng) == 0)
            signal = 1;
        else
            signal = -1;

        curve_points[0] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[1] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[2] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        curve_points[3] = glm::vec3(-static_cast<float>(range2to30(rng)), -0.2f, signal * static_cast<float>(range0to4(rng)));
        posx = curve_points[0].x;
        posy = curve_points[0].y;
        posz = curve_points[0].z;

        t = 0;
    }

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
        else
            return cube::getModel();
    }

    void calculate_bezier()
    {
        glm::vec3 p0 = curve_points[0];
        glm::vec3 p1 = curve_points[1];
        glm::vec3 p2 = curve_points[2];
        glm::vec3 p3 = curve_points[3];
        auto new_point = powf((1 - t), 3) * p0 + 3 * powf(1 - t, 2) * t * p1 + 3 * (1 - t) * powf(t, 2) * p2 + powf(t, 3) * p3;
        posx = new_point.x;
        posy = new_point.y;
        posz = new_point.z;
    }
};
