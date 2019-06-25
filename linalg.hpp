#pragma once

#include <array>
#include <math.h>
#include <iostream>

#define PI 3.14159265358979323846264

class vec3;
class vec3f;
class vec4;
class mat3;
class mat4;
class quaternion;

class vec3{
public:
    double x;
    double y;
    double z;
    
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

    // Gets the data in the form of a std::array
    std::array<double,3> get() {
       return {x,y,z};
    }

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

    // Prints the contents of the vector
    void print();
    // Prints the contents of the vector with a newline terminator
    void println();

};
// Operator overloads
bool operator==(const vec3&,const vec3&);
bool operator!=(const vec3&,const vec3&);
vec3 operator+ (const vec3&,const vec3&);
vec3 operator- (const vec3&,const vec3&);
void operator+=(vec3&,const vec3&);
void operator-=(vec3&,const vec3&);
vec3 operator* (const double&,const vec3&);
vec3 operator* (const vec3&,const double&);

class vec4{
public:
    double x;
    double y;
    double z;
    double w;
    
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
    // Gets the data in the form of a pointer
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
vec4 operator* (const double&,const vec4&);
vec4 operator* (const vec4&,const double&);


class mat3{
public:
    /**************************************************
        DATA
    **************************************************/
    vec3 x;
    vec3 y;
    vec3 z;
    
    /**************************************************
        FUNCTIONS
    **************************************************/
    
    mat3(double init = 0.0, bool identity = false);
    static mat3 eye3();

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
    // Please verify and make sure I didnt make any typos @AndrewMalatak
    quaternion toQuat();
    // Expands the matrix to a 4x4 using zeros and a 1 in the bottom right (w.w)
    mat4 expand();

};

// Operator overloads
mat3 operator*(const mat3&,const mat3&);
vec3 operator*(const mat3&,const vec3&);
mat3 operator-(const mat3&,const mat3&);
mat3 operator+(const mat3&,const mat3&);


class mat4{
public:
    /**************************************************
        DATA
    **************************************************/
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;

    mat4(double init = 0.0, bool identity = false);

    static mat4 TransMat(vec3);
    static mat4 ScaleMat(double);
    static mat4 eye4();
    /**************************************************
        FUNCTIONS
    **************************************************/
    mat4 transpose();

    void print();

    /**************************************************
        CONVERSIONS
    **************************************************/
    mat3 shrink();
};

// Operator overloads
mat4 operator*(const mat4&,const mat4&);
vec4 operator*(const mat4&,const vec4&);
mat4 operator-(const mat4&,const mat4&);
mat4 operator+(const mat4&,const mat4&);


class quaternion{
public:
    double s = 1.0;
    vec3 v;


    // Default constructor 
    quaternion() : quaternion(0.0,0.0,0.0,1.0){};

    // Axis angle constructor
    quaternion(const vec3&, double, bool degrees = false);

    // Quaternion constructor
    // Format is (S,Vx,Vy,Vz)
    quaternion(double,double,double,double);

    // Normalize the quaternion
    void normalize();

    // Rotate a vector using the quaternion
    vec3 rotate (const vec3& to_rotate) const;

    // Converts the quaternion to a 3x3 matrix
    // Algorith source:
    // https://www.euclideanspace.com/maths/geometry/rotations/conversions/quaternionToMatrix/index.htm
    // Please verify and make sure I didnt make any typos @AndrewMalatak
    mat3 toMat3();

    // Prints the contents of the quaternion
    void print() const;

    // Prints the contents of the quaternion with a newline terminator
    void println() const;

    // Tests the equivalence of two quaternions by rotating a vector (1,1,1)
    // using the two quaternions and then checks if the rotated vectors are the same
    static bool testEquivalence(const quaternion&, const quaternion&);
};

quaternion operator*(const quaternion&, const quaternion&);

/******************************************************
 * 
 *  NON-CLASS FUNCTIONS
 * 
******************************************************/

// Converts radians to degrees
const double rad2deg(double);

// Converts degrees to radians
const double deg2rad(double);
