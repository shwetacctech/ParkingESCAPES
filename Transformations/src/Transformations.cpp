// Transformations.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Transformations.h"
//Constructor
Transformations::Transformations()
{
    
}
//Destructor
Transformations::~Transformations() {

}
//translates points toward -x direction/left direction
const std::vector<Point3D> Transformations::translate_X_Left(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 5);
    }
    return inVertices;
}
//translates points toward +x direction/right direction
const std::vector<Point3D>  Transformations::translate_X_Right(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() + 5);
    }
    return inVertices;

}
//translates points toward +y direction/upwards direction
const std::vector<Point3D>  Transformations::translate_Y_UP(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() + 5);
    }
    return inVertices;

}
//translates points toward -y direction/downwards direction
const std::vector<Point3D>  Transformations::translate_Y_Down(std::vector<Point3D> inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setY(inVertices[i].Y() - 5);
    }
    return inVertices;

}
std::vector<Point3D> Transformations:: rotate_x_left(std::vector<Point3D> inVertices) {
    translate_nxy(inVertices);
    float angle = 90*3.14159 / 180.0;
    double cosTheta = cos(angle);
    double sinTheta = sin(angle);

    for (int i = 0; i < inVertices.size(); i++) {
        double x = inVertices[i].X();
        double y= inVertices[i].Y();
        inVertices[i].setX((x * cosTheta) - (y * sinTheta));
        inVertices[i].setY((x * sinTheta) + (y * cosTheta));

    }
    translate_pxy(inVertices);
    return inVertices;
}
void Transformations::translate_nxy(std::vector<Point3D>& inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 1);
        inVertices[i].setY(inVertices[i].Y() - 1);
        inVertices[i].setZ(inVertices[i].Z() - 1);
    }
    
}
void Transformations::translate_pxy(std::vector<Point3D>& inVertices) {
    for (int i = 0; i < inVertices.size(); i++) {
        inVertices[i].setX(inVertices[i].X() - 1);
        inVertices[i].setY(inVertices[i].Y() - 1);
        inVertices[i].setZ(inVertices[i].Z() - 1);
    }
    
}