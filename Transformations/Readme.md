# Transformations Class
The Transformations class is a component of a Dynamic Link Library (DLL), providing transformation operations for manipulating a vector of 3D points (Point3D). This class supports translations along the X and Y axes and rotation around the X axis.

# Overview
The Transformations class encapsulates the following functionalities:

+ Constructor: Initializes a Transformations instance.
+ Destructor: Cleans up resources when the Transformations instance is destroyed.
+ translate_X_Left(): Translates points toward the -X direction (left direction).
+ translate_X_Right(): Translates points toward the +X direction (right direction).
+ translate_Y_UP(): Translates points toward the +Y direction (upwards direction).
+ translate_Y_Down(): Translates points toward the -Y direction (downwards direction).
+ rotate_x_left(): Rotates points around the X axis in the left direction.
# Usage
Initializing Transformations
To use the Transformations class, follow these steps:
```
#include "Transformations.h"
#include "Point3D.h"
#include <vector>

int main() {
    // Example usage
    Transformations transformer;

    std::vector<Point3D> vertices = /* Define 3D points */;

    // Translate points left along the X axis
    std::vector<Point3D> translatedVertices = transformer.translate_X_Left(vertices);

    // ...
    return 0;
}
```
### Methods
+ translate_X_Left()
Translates points toward the -X direction (left direction).
```
std::vector<Point3D> translatedVertices = transformer.translate_X_Left(vertices);
```
+ translate_X_Right()
Translates points toward the +X direction (right direction).
```
std::vector<Point3D> translatedVertices = transformer.translate_X_Right(vertices);
```
+ translate_Y_UP()
Translates points toward the +Y direction (upwards direction).
```
std::vector<Point3D> translatedVertices = transformer.translate_Y_UP(vertices);
```
+ translate_Y_Down()
Translates points toward the -Y direction (downwards direction).
```
std::vector<Point3D> translatedVertices = transformer.translate_Y_Down(vertices);
```
+ rotate_x_left()
Rotates points around the X axis in the left direction.
```
std::vector<Point3D> rotatedVertices = transformer.rotate_x_left(vertices);
```
