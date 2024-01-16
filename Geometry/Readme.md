# Point3D Class
The Point3D class represents a three-dimensional point in space. It provides methods for setting and retrieving the coordinates of the point.

# Overview
The Point3D class encapsulates the following functionalities:

+ Constructors: Initializes a Point3D instance with default or specified coordinates.
+ Destructor: Cleans up resources when the Point3D instance is destroyed.
# Usage
Initializing Point3D
To create a Point3D instance, use one of the following constructors:
```
#include "Point3D.h"

// Example usage
Point3D point1; // Default constructor, initializes to (0, 0, 0)
Point3D point2(1.0, 2.0, 3.0); // Constructor with specified coordinates
```
Accessing Coordinates
Retrieve the coordinates of a Point3D instance using the getter methods:
```
// Example usage of getting coordinates
double xCoord = point2.X();
double yCoord = point2.Y();
double zCoord = point2.Z();
```
Modifying Coordinates
Modify the coordinates of a Point3D instance using the setter methods:
```
// Example usage of setting coordinates
point1.setX(4.0);
point1.setY(5.0);
point1.setZ(6.0);
```
