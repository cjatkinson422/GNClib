#include "linalg.hpp"

vec3::vec3(double argx, double argy, double argz){
    this->xyz = {argx,argy,argz};
}
vec3::vec3(const vec3& ref){
    this->x = ref.x;
    this->y = ref.y;
    this->z = ref.z;
}

void vec3::normalize(){
    double s = sqrt(x*x + y*y + z*z);
    if(s<1e-8){
        x=0.0; y=0.0; z=0.0;
    }
    else{
        x /= s;
        y /= s;
        z /= s;        
    }
}

double vec3::length(){
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::cross(vec3& v1, vec3& v2){
    vec3 rv;
    rv.x = v1.y*v2.z - v1.z*v2.y;
    rv.y = v1.z*v2.x - v1.x*v2.z;
    rv.z = v1.x*v2.y - v1.y*v2.x;
    return rv;
}

double vec3::dot(vec3& v1, vec3& v2){
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

void vec3::print(){
    printf("x: %f, y: %f, z: %f", x, y, z);
}

void vec3::println(){
    printf("x: %f, y: %f, z: %f\n", x, y, z);
}

/*****************************************************
    OPERATOR OVERLOADS
*****************************************************/
// Equivalence operator
bool operator==(vec3& v1, vec3& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return true;
    else
        return false;
}
// Anti-equivalence operator
bool operator!=(vec3& v1, vec3& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return false;
    else
        return true;
}
// Copy assignment operator for a vec3 reference
vec3& vec3::operator=(vec3& vr){
    this->x = vr.x;
    this->y = vr.y;
    this->z = vr.z;
    return *this;
}
// Copy assignment operator for a constant vec3 reference
vec3& vec3::operator=(const vec3& vr){
    this->x = vr.x;
    this->y = vr.y;
    this->z = vr.z;
    return *this;
}
