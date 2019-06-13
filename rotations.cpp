#include "rotations.hpp"

quaternion::quaternion(double s, double x, double y, double z){
    this->s = s;
    this->v.x = x;
    this->v.y = y;
    this->v.z = z;
}

void quaternion::normalize(){
    double val = sqrt(s*s + v.x*v.x + v.y*v.y + v.z*v.z);
    s/=val;
    v.x/=val;
    v.y/=val;
    v.z/=val;
}

void quaternion::print(){
    printf("x: %f, y: %f, z: %f, s: %f", v.x, v.y, v.z, s);
}

void quaternion::println(){
    printf("x: %f, y: %f, z: %f, s: %f\n", v.x, v.y, v.z, s);
}
