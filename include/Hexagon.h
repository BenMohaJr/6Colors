#pragma once

#include "Shape.h"
#include <cmath>



// Hexagon to inherite from shapes, to represent a certain shape
class Hexagon : public Shape {
public:
    Hexagon(int, int, float);

    void CheckForNeighbors(Dev Grid);    

private:
};