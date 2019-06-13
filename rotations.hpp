#pragma once

#include <iostream>
#include "linalg.hpp"

class quaternion{
public:
    double s = 1.0;
    vec3 v = vec3();


    // Default constructor 
    quaternion() : quaternion(0.0,0.0,0.0,1.0){};
    // Axis angle constructor
    quaternion(vec3,double);
    // Quaternion constructor
    // Format is (S,Vx,Vy,Vz)
    quaternion(double,double,double,double);

    // Normalize the quaternion
    void normalize();

    // Prints the contents of the quaternion
    void print();
    // Prints the contents of the quaternion with a newline terminator
    void println();
    
};

