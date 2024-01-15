# Car Class
The Car class is designed to represent a 3D car entity within a software system, providing functionalities to manage its geometry, color attributes, alignment, and bounding box information.

# Overview
The Car class encapsulates the following attributes and functionalities:

## Vertices: Represents the points in 3D space that define the car's shape.
## Colors: Stores the color information associated with the car.
## Alignment: Indicates whether the car is straight or not.
## Bounding Box (BBOX): Provides information about the bounding box coordinates.
# Usage
## Initializing a Car
To create a Car instance, follow these steps:
```
#include "Car.h"
#include <vector>
#include "Point3D.h"

int main() {
    // Define vertices, colors, and alignment
    std::vector<Point3D> carVertices = /* Define vertices */;
    std::vector<float> carColors = /* Define colors */;
    bool isStraight = /* Define alignment */;

    // Create a car instance
    Car myCar(carVertices, carColors, isStraight);
    // ...
    return 0;
}
```
## Accessing Car Data
You can retrieve the stored vertices, colors, alignment, and bounding box information using the following methods:

+ getVertices(): Returns the vector of 3D points defining the car's shape.
+ getColors(): Returns the vector of colors associated with the car.
+ getAlignment(): Returns the alignment status of the car.
+ getBBOX(): Returns a vector containing the bounding box coordinates.
```
// Example usage of getting vertices, colors, alignment, and bounding box
std::vector<Point3D> vertices = myCar.getVertices();
std::vector<float> colors = myCar.getColors();
bool isStraight = myCar.getAlignment();
std::vector<double> boundingBox = myCar.getBBOX();
```
## Modifying Car Data
You can also modify the vertices, colors, and alignment of the car using the following methods:

setVertices(const std::vector<Point3D>& newVertices): Set new vertices for the car.
setColor(const std::vector<float>& newColor): Set new colors for the car.
```
// Example usage of setting new vertices and colors
myCar.setVertices(newVertices);
myCar.setColor(newColors);
```
