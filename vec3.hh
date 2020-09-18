#pragma once

#include <array>
#include <math.h>
#include <iostream>


class quaternion;
class mat4;
class mat3;
class vec4;
class vec3;

#define PI 3.14159265358979323846264

class vec3{
public:
    double x;
    double y;
    double z;

    double& operator[](unsigned int);
    
    // Default constructor
    vec3() : vec3(0.0,0.0,0.0){};
    // Standard vector 3 (x,y,z)
    vec3(double,double,double);

    // Sets the data to some new value
    void set(std::array<double,3> dat){
        x=dat[0];
        y=dat[1];
        z=dat[2];
    }

    // Negative Operator. returns the vectors negative
    friend vec3 operator-(const vec3&);
    // Normalizes this vector.
    void normalize();
    static vec3 normalize(const vec3&);
    // Returns the current length of the vector.
    double length();
    // Crosses two vec3's and returns a new vec3 with the result
    static vec3 cross(const vec3&,const vec3&);
    // Dots two vec3's and returns a double with the result
    static double dot(const vec3&,const vec3&);

    // Expands the vector from a vec3 to a vec4 placing the
    // parameter passed in the 4th (w) spot in the vec4
    vec4 expand(double w = 0);

    // get an array of floats representing the data
    std::array<float,3> gl_float_ref() const;

    // Prints the contents of the vector
    void print();
    // Prints the contents of the vector with a newline terminator
    void println();

    double getAngularDist(vec3& v1, vec3& v2);

    static const vec3 unit_x;
    static const vec3 unit_y;
    static const vec3 unit_z;

};
// Operator overloads
bool operator==(const vec3&,const vec3&);
bool operator!=(const vec3&,const vec3&);
vec3 operator+ (const vec3&,const vec3&);
vec3& operator+=(vec3&, const vec3&);
vec3& operator-=(vec3&, const vec3&);
vec3 operator- (const vec3&,const vec3&);
vec3 operator*(const double&,const vec3&);
vec3 operator*(const vec3&,const double&);
vec3 operator/(const vec3&,const double&);
double* operator&(vec3&);

