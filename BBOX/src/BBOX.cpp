// BBOX.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "BBOX.h"
#include <algorithm>
// This is the constructor of a class that has been exported.
BBOX::BBOX()
{
    
}
BBOX::~BBOX() {

}
double BBOX::max_X(std::vector<Point3D> inVertices)
{
    double maxX = inVertices[0].X();
    for (int i = 1; i < inVertices.size(); i++) {
        if (maxX < inVertices[i].X()) {
            maxX = inVertices[i].X();
        }
    }
    return maxX;
}
double BBOX::max_Y(std::vector<Point3D> inVertices) {
    double maxY = inVertices[0].Y();
    for (int i = 1; i < inVertices.size(); i++) {
        if (maxY < inVertices[i].Y()) {
            maxY = inVertices[i].Y();
        }
    }
    return maxY;
}
double BBOX::max_Z(std::vector<Point3D> inVertices)
{
    double maxZ = inVertices[0].Z();
    for (int i = 1; i < inVertices.size(); i++) {
        if (maxZ < inVertices[i].Z()) {
            maxZ = inVertices[i].Z();
        }
    }
    return maxZ;
}
double BBOX::min_X(std::vector<Point3D> inVertices)
{
    double minX = inVertices[0].X();
    for (int i = 1; i < inVertices.size(); i++) {
        if (minX > inVertices[i].X()) {
            minX = inVertices[i].X();
        }
    }
    return minX;
}
double BBOX::min_Y(std::vector<Point3D> inVertices)
{

    double minY = inVertices[0].Y();
    for (int i = 1; i < inVertices.size(); i++) {
        if (minY > inVertices[i].Y()) {
            minY = inVertices[i].Y();
        }
    }
    return minY;
}
double BBOX::min_Z(std::vector<Point3D> inVertices)
{
    double minZ = inVertices[0].Z();
    for (int i = 1; i < inVertices.size(); i++) {
        if (minZ > inVertices[i].Z()) {
            minZ = inVertices[i].Z();
        }
    }
    return minZ;
}