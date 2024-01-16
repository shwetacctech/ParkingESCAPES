#pragma once
#include <vector>
#include "pch.h"
#include <Point3D.h>
// This class is exported from the dll
class CAR_API Car {
public:
	Car(const std::vector<Point3D>& inVertices, const std::vector<float>& inColor, bool straight); //constructor of car
	~Car(); //destructor of car
public:
	const std::vector<Point3D> getVertices() const ; 
	const std::vector<float> getColors() const; 
	bool getAlignment();
	void setVertices(const std::vector<Point3D>& newVertice); 
	void setColor(const std::vector<float>& newColor);
	std::vector<double> getBBOX();
private:
	std::vector<Point3D> mVertices; 
	std::vector<float> mColor; 
	bool mBool; 
	double mMinX;
	double mMinY;
	double mMinZ;
	double mMaxX;
	double mMaxY;
	double mMaxZ;
private:
	void updateBBOX();
};
