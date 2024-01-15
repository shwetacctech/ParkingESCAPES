// CollisionDetection.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "CollisionDetection.h"


// This is the constructor of a class that has been exported.
CollisionDetection::CollisionDetection(int carNo, std::vector<Car>& inCarContainer):
    mCarContainer(inCarContainer),
    mcarNo(carNo)
{
    checkCollision();
}
CollisionDetection::~CollisionDetection()
{

}
void CollisionDetection::checkCollision() {
    std::vector<double> movingCar= mCarContainer[mcarNo].getBBOX();
    for (int i = 0; i < mCarContainer.size(); i++) {
        if (i == mcarNo) {
            continue;
        }
        Point3D p1(movingCar[0],movingCar[1],movingCar[2]);
        Point3D p2(movingCar[3],movingCar[1],movingCar[2]);
        Point3D p3(movingCar[3],movingCar[4],movingCar[2]);
        Point3D p4(movingCar[0],movingCar[4],movingCar[2]);
        std::vector<double> carBBox = mCarContainer[i].getBBOX();
        mMovable = isPointInsideCube(p1, mCarContainer[i].getBBOX()) &&
        isPointInsideCube(p2, mCarContainer[i].getBBOX()) &&
        isPointInsideCube(p3, mCarContainer[i].getBBOX()) &&
        isPointInsideCube(p4, mCarContainer[i].getBBOX());
        if (!mMovable) return;
    }
}
bool CollisionDetection::isMovable() {
    return mMovable;
}
bool CollisionDetection::isPointInsideCube(Point3D& point, std::vector<double> carBBox) {
    return !(point.X() >= carBBox[0] && point.X() <= carBBox[3] &&
        point.Y() >= carBBox[1] && point.Y() <= carBBox[4]);
}