#include <vector>
#include "pch.h"
#include <Point3D.h>
// This class is exported from the dll
class BBOX_API BBOX {
public:
	BBOX();
	~BBOX();
public:
	double max_X(std::vector<Point3D> inVertices);
	double max_Y(std::vector<Point3D> inVertices);
	double max_Z(std::vector<Point3D> inVertices);
	double min_X(std::vector<Point3D> inVertices);
	double min_Y(std::vector<Point3D> inVertices);
	double min_Z(std::vector<Point3D> inVertices);
};

