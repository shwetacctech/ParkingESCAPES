# BBOX Class
The BBOX class is designed to calculate the bounding box coordinates for a given set of 3D points (vertices). This class is part of a DLL (Dynamic Link Library) and provides methods to determine the maximum and minimum coordinates along the X, Y, and Z axes.

# Overview
The BBOX class encapsulates the following functionalities:

+ max_X(): Calculates the maximum X-coordinate from a vector of 3D points (vertices).
+ max_Y(): Calculates the maximum Y-coordinate from a vector of 3D points.
+ max_Z(): Calculates the maximum Z-coordinate from a vector of 3D points.
+ min_X(): Calculates the minimum X-coordinate from a vector of 3D points.
+ min_Y(): Calculates the minimum Y-coordinate from a vector of 3D points.
+ min_Z(): Calculates the minimum Z-coordinate from a vector of 3D points.
# Usage
Initializing BBOX
To use the BBOX class, follow these steps:
```
#include "BBOX.h"
#include "Point3D.h"
#include <vector>

int main() {
    // Example usage
    BBOX boundingBoxCalculator;

    std::vector<Point3D> vertices = /* Define 3D points */;
    
    // Calculate maximum and minimum coordinates
    double maxX = boundingBoxCalculator.max_X(vertices);
    double maxY = boundingBoxCalculator.max_Y(vertices);
    double maxZ = boundingBoxCalculator.max_Z(vertices);
    
    double minX = boundingBoxCalculator.min_X(vertices);
    double minY = boundingBoxCalculator.min_Y(vertices);
    double minZ = boundingBoxCalculator.min_Z(vertices);

    // ...
    return 0;
}
```
## Methods
+ max_X()
Calculates the maximum X-coordinate from a vector of 3D points.

```
double maxX = boundingBoxCalculator.max_X(vertices);
```
+ max_Y()
Calculates the maximum Y-coordinate from a vector of 3D points.
```
double maxY = boundingBoxCalculator.max_Y(vertices);
```
+ max_Z()
Calculates the maximum Z-coordinate from a vector of 3D points.

```
double maxZ = boundingBoxCalculator.max_Z(vertices);
```
+ min_X()
Calculates the minimum X-coordinate from a vector of 3D points.
```
double minX = boundingBoxCalculator.min_X(vertices);
```
+ min_Y()
Calculates the minimum Y-coordinate from a vector of 3D points.
```
double minY = boundingBoxCalculator.min_Y(vertices);
```
+ min_Z()
Calculates the minimum Z-coordinate from a vector of 3D points.

```
double minZ = boundingBoxCalculator.min_Z(vertices);
```
