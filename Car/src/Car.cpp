// Car.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "Car.h"
#include <BBOX.h>
//constructor
Car::Car(const std::vector<Point3D>& inVertices, const std::vector<float>& inColor, bool straight):
mVertices(inVertices),
mColor(inColor),
mBool(straight)
{
	updateBBOX();
}
//destructor
Car::~Car() {
	
}
//vertices getter
const std::vector<Point3D> Car::getVertices() const{
	return mVertices;
}
//colors getter
const std::vector<float> Car::getColors() const{
	return mColor;
}
//alignment getter
bool Car::getAlignment() {
	return mBool;
}
//vertices setter
void Car::setVertices(const std::vector<Point3D>& newVertices) {
	mVertices = newVertices;
	updateBBOX();
}
//colors setter
void Car::setColor(const std::vector<float>& newColor) {
	mColor = newColor;
}

void Car::updateBBOX() {
	BBOX bbox;
	mMinX = bbox.min_X(mVertices);
	mMinY = bbox.min_Y(mVertices);
	mMinZ = bbox.min_Z(mVertices);
	mMaxX = bbox.max_X(mVertices);
	mMaxY = bbox.max_Y(mVertices);
	mMaxZ = bbox.max_Z(mVertices);
}

std::vector<double> Car::getBBOX() {
	std::vector<double> bbox_points;
	bbox_points.push_back(mMinX);
	bbox_points.push_back(mMinY);
	bbox_points.push_back(mMinZ);
	bbox_points.push_back(mMaxX);
	bbox_points.push_back(mMaxY);
	bbox_points.push_back(mMaxZ);
	return bbox_points;
}