#pragma once
#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include "sphere.h"
#include <cmath>
#include <iostream>

bool cubeToCubeCollision(cube &cube1, cube &cube2);
bool cubeToCylinderCollision(cube &c, cylinder &cy);
bool cylinderToPlaneCollision(cylinder &cy, plane &p);
bool sphereToCubeCollision(sphere &s, cube &c);
