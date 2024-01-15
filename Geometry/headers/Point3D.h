#pragma once
#include "pch.h"
class GEOMETRY_API Point3D
{
    
public:
        // Constructors
        Point3D();
        Point3D(double inx_coord, double iny_coord, double inz_coord);

        //Destructor
        ~Point3D();
public:
        // Getter methods
        double X() ;
        double Y() ;
        double Z() ;

        // Setter methods
        void setX(double x_coord);
        void setY(double y_coord);
        void setZ(double z_coord);
private:
    double mX; //member variable x
    double mY; //member variable y
    double mZ; //member variable z

};


