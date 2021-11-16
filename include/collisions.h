#pragma once
#include "cube.h"
#include "cylinder.h"
#include "plane.h"
#include <cmath>
#include <iostream>

bool cubeToCubeCollision(cube &cube1, cube &cube2);
bool cubeToCylinderCollision(const cube &c, cylinder &cy);
bool cylinderToPlaneCollision(cylinder &cy, plane &p);
