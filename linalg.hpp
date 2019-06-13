#pragma once

#include <array>
#include <math.h>
#include <iostream>

class vec3{
public:
    std::array<double,3> xyz;
    double& x = xyz[0];
    double& y = xyz[1];
    double& z = xyz[2];
    
    // Default constructor
    vec3() : vec3(0.0,0.0,0.0){};
    // Standard vector 3 (x,y,z)
    vec3(double,double,double);
    // Copy constructor
    vec3(const vec3&);

    // Normalizes this vector.
    void normalize();
    // Returns the current length of the vector.
    double length();
    // Crosses two vec3's and returns a new vec3 with the result
    static vec3 cross(vec3&,vec3&);
    // Dots two vec3's and returns a double with the result
    static double dot(vec3&,vec3&);
    // Prints the contents of the vector
    void print();
    // Prints the contents of the vector with a newline terminator
    void println();

    // Copy constructors
    vec3& operator=(vec3&);
    vec3& operator=(const vec3&);
};

// Operator overloads
bool operator==(vec3&,vec3&);
bool operator!=(vec3&,vec3&);
