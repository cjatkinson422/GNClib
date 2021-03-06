#pragma once

#include <array>
#include <math.h>
#include <iostream>
#include "vec3.hh"


class quaternion;
class mat4;
class mat3;
class vec4;
class vec3;

#define PI 3.14159265358979323846264

/*********************************************************************
     
     VEC 4 class

*********************************************************************/


class vec4{
public:
    double x;
    double y;
    double z;
    double w;

    double& operator[](unsigned int);
    
    // Default constructor
    vec4() : vec4(0.0,0.0,0.0,0.0){};
    // Standard vector 4 (x,y,z)
    vec4(double,double,double,double);

    // Sets the data to some new value
    void set(std::array<double,4> dat){
        x=dat[0];
        y=dat[1];
        z=dat[2];
        w=dat[3];
    }
    // Gets the data in the form of an array
    std::array<double,4> get() {
       return {x,y,z,w};
    }

    // Normalizes this vector.
    void normalize();
    // Returns the current length of the vector.
    double length();
    // Prints the contents of the vector

    vec3 shrink();

    void print();
    // Prints the contents of the vector with a newline terminator
    void println();

};
// Operator overloads
bool operator==(const vec4&,const vec4&);
bool operator!=(const vec4&,const vec4&);
vec4 operator- (const vec4&,const vec4&);
vec4 operator+ (const vec4&,const vec4&);
vec4& operator+=(vec4&, const vec4&);
vec4& operator-=(vec4&, const vec4&);
vec4 operator* (const double&,const vec4&);
vec4 operator* (const vec4&,const double&);
double* operator&(vec4&);


/*********************************************************************
     
    MAT 3 class

*********************************************************************/


class mat3{
public:
    /**************************************************
        DATA
    **************************************************/
    vec3 x;
    vec3 y;
    vec3 z;
    

    vec3& operator[](unsigned int);

    /**************************************************
        FUNCTIONS
    **************************************************/

   // Orthogonalizes the matrix using the current X vector as the
   // reference direction. Once orthogonalized, normalizes each vector
    void orthonormalize();
    // Does a standard matrix transpose and returns the new transposed matrix
    mat3 transpose();
    // Returns a vector composed of the diagonal elements of the matrix
    vec3 diag();
    // Returns a double equal to the sum of the diagonal elements
    double trace();
    // Prints the contents of the matrix
    void print();
    
    /**************************************************
        CONVERSIONs
    **************************************************/
    
    // Converts the matrix to a quaternion
    // Algorithm source: 
    // http://www.euclideanspace.com/maths/geometry/rotations/conversions/matrixToQuaternion/
    quaternion toQuat();
    // Expands the matrix to a 4x4 using zeros and a 1 in the bottom right (w.w)
    mat4 expand();

    /**************************************************
     * Instantiations
    **************************************************/
   static mat3 zeros();
   static mat3 eye();
   static mat3 ones();

};

// Operator overloads
mat3 operator*(const mat3&,const mat3&);
vec3 operator*(const mat3&,const vec3&);
mat3 operator-(const mat3&,const mat3&);
mat3 operator+(const mat3&,const mat3&);
const double* operator&(const mat3&);


/*********************************************************************
     
     MAT 4 class

*********************************************************************/


class mat4{
public:
    /**************************************************
        DATA
    **************************************************/
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;

    vec4& operator[](unsigned int);


    /**************************************************
        FUNCTIONS
    **************************************************/
    mat4 transpose();

    std::array<float,16> gl_float_ref() const;

    void print();

    /**************************************************
        CONVERSIONS
    **************************************************/
    mat3 shrink();

    /**************************************************
     * Instantiations
    **************************************************/
   static mat4 zeros();
   static mat4 eye();
   static mat4 ones();
};

// Operator overloads
mat4 operator*(const mat4&,const mat4&);
vec4 operator*(const mat4&,const vec4&);
mat4 operator-(const mat4&,const mat4&);
mat4 operator+(const mat4&,const mat4&);



/******************************************************
 * 
 *  NON-CLASS FUNCTIONS
 * 
******************************************************/

// Converts radians to degrees
const double rad2deg(double);

// Converts degrees to radians
const double deg2rad(double);

/******************************************************
 * 
 *  TEMPLATED FUNCTIONS
 * 
******************************************************/
