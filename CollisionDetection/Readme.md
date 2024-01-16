# CollisionDetection Class
The CollisionDetection class is a component of a Dynamic Link Library (DLL), providing collision detection functionality for a specific car within a container of cars. This class enables the detection of collisions and checks whether the specified car is movable.

# Overview
The CollisionDetection class encapsulates the following functionalities:

+ Constructor: Initializes a CollisionDetection instance with a car number and a container of cars.
+ Destructor: Cleans up resources when the CollisionDetection instance is destroyed.
+ isMovable(): Checks whether the specified car is movable.
+ checkCollision(): Performs collision detection between the specified car and others in the container.
+ isPointInsideCube(): Checks if a 3D point is inside the bounding box of a car.
# Usage
Initializing CollisionDetection
To use the CollisionDetection class, follow these steps:
```
#include "CollisionDetection.h"
#include "Car.h"
#include <vector>

int main() {
    // Example usage
    int carNumber = /* Define car number */;
    std::vector<Car> carContainer = /* Define a container of cars */;

    // Create a CollisionDetection instance
    CollisionDetection collisionDetector(carNumber, carContainer);

    // Check if the specified car is movable
    bool isMovable = collisionDetector.isMovable();

    // ...
    return 0;
}
```
### Methods
+ isMovable()
Checks whether the specified car is movable.
```
bool isMovable = collisionDetector.isMovable();
```
+ checkCollision()
Performs collision detection between the specified car and others in the container.
```
collisionDetector.checkCollision();
```
+ isPointInsideCube()
Checks if a 3D point is inside the bounding box of a car.
```
Point3D pointToCheck = /* Define a 3D point */;
std::vector<double> carBoundingBox = /* Get bounding box from a specific car */;
bool insideCube = collisionDetector.isPointInsideCube(pointToCheck, carBoundingBox);
```
