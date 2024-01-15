#include "pch.h"
#include <vector>
#include <Car.h>
// This class is exported from the dll
class COLLISIONDETECTION_API CollisionDetection {
public:
	CollisionDetection(int carNo, std::vector<Car>& inCarContainer);
	~CollisionDetection();
public:
	bool isMovable();
private:
	void checkCollision();
	bool isPointInsideCube(Point3D& point, std::vector<double> carBBox);


private:
	bool mMovable;
	int mcarNo;
	std::vector<Car> mCarContainer;
};

