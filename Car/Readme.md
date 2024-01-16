# Car Class
The Car class is a C++ representation of a 3D car entity, designed to be part of a Dynamic Link Library (DLL). This class provides methods for managing the car's geometry, color attributes, alignment, and bounding box information.

# Overview
The Car class encapsulates the following functionalities:

+ Constructor: Initializes a Car instance with a set of vertices, colors, and alignment.
+ Destructor: Cleans up resources when the Car instance is destroyed.
+ getVertices(): Returns the vector of 3D points defining the car's shape.
+ getColors(): Returns the vector of colors associated with the car.
+ getAlignment(): Returns the alignment status of the car.
+ setVertices(): Sets new vertices for the car.
+ setColor(): Sets new colors for the car.
+ getBBOX(): Returns a vector containing the bounding box coordinates.
# Usage
Initializing a Car
To create a Car instance, follow these steps:
```
#include "Car.h"
#include "Point3D.h"
#include <vector>

int main() {
    // Example usage
    std::vector<Point3D> carVertices = /* Define vertices */;
    std::vector<float> carColors = /* Define colors */;
    bool isStraight = /* Define alignment */;

    // Create a car instance
    Car myCar(carVertices, carColors, isStraight);
    // ...
    return 0;
}
```
+ Accessing Car Data
You can retrieve the stored vertices, colors, alignment, and bounding box information using the following methods:
```
// Example usage of getting vertices, colors, alignment, and bounding box
std::vector<Point3D> vertices = myCar.getVertices();
std::vector<float> colors = myCar.getColors();
bool isStraight = myCar.getAlignment();
std::vector<double> boundingBox = myCar.getBBOX();
```
+ Modifying Car Data
You can also modify the vertices and colors of the car using the following methods:
```
// Example usage of setting new vertices and colors
myCar.setVertices(newVertices);
myCar.setColor(newColors);
```
