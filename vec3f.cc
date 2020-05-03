#include "vec3f.hh"
#include "linalg.hh"

#define REDC "\033[91m"
#define GREC "\033[92m"
#define BLUC "\033[94m"
#define YELC "\033[95m"
#define ENDC "\033[0m"

/*****************************************************

    VECTOR

*****************************************************/

/*****************************************************
    VECTOR 3 METHODS
*****************************************************/
const vec3f vec3f::unit_x = vec3f(1.0,0.0,0.0);
const vec3f vec3f::unit_y = vec3f(0.0,1.0,0.0);
const vec3f vec3f::unit_z = vec3f(0.0,0.0,1.0);

vec3f::vec3f(float argx, float argy, float argz){
    x=argx; y=argy; z=argz;
}
vec3f operator-(const vec3f& v){
    return {-v.x,-v.y,-v.z};
}
void vec3f::normalize(){
    float s = sqrt(x*x + y*y + z*z);
    if(s<1e-10){
        x=0.0; y=0.0; z=0.0;
    }
    else{
        x /= s;
        y /= s;
        z /= s;        
    }
}

vec3f vec3f::normalize(const vec3f& v){
    float s = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    vec3f ret;
    if (s<1e-8){
        ret.x=0.0; ret.y=0.0; ret.z=0.0;
    }else{
        ret.x = v.x/s;
        ret.y = v.y/s;
        ret.z = v.z/s;
    }
    return ret;
}

float vec3f::length(){
    return sqrt(x*x + y*y + z*z);
}

vec3f vec3f::cross(const vec3f& v1, const vec3f& v2){
    vec3f rv;
    rv.x = v1.y*v2.z - v1.z*v2.y;
    rv.y = v1.z*v2.x - v1.x*v2.z;
    rv.z = v1.x*v2.y - v1.y*v2.x;
    return rv;
}

float vec3f::dot(const vec3f& v1, const vec3f& v2){
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

float vec3f::getAngularDist(vec3f& v1, vec3f& v2){
	return acos(dot(normalize(v1), normalize(v2)));
}

void vec3f::print(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f", x, y, z);
}

void vec3f::println(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f\n", x, y, z);
}


/*****************************************************
    VECTOR 3 OPERATOR OVERLOADS
*****************************************************/

// Equivalence operator
bool operator==(const vec3f& v1, const vec3f& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return true;
    else
        return false;
}
// Anti-equivalence operator
bool operator!=(const vec3f& v1, const vec3f& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return false;
    else
        return true;
}
vec3f& operator+=(vec3f& a, const vec3f& b){
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
vec3f& operator-=(vec3f& a, const vec3f& b){
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
vec3f operator+(const vec3f& v1, const vec3f&v2){
    vec3f r;
    r.x = v1.x+v2.x;
    r.y = v1.y+v2.y;
    r.z = v1.z+v2.z;
    return r;
}

vec3f operator-(const vec3f& v1, const vec3f& v2){
    vec3f r;
    r.x = v1.x-v2.x;
    r.y = v1.y-v2.y;
    r.z = v1.z-v2.z;
    return r;
}
vec3f operator*(const float& s, const vec3f& v){
    vec3f r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    return r;
}
vec3f operator*(const vec3f& v, const float& s){
    vec3f r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    return r;
}
vec3f operator/(const vec3f& v, const float& s){
    vec3f r;
    r.x = v.x/s;
    r.y = v.y/s;
    r.z = v.z/s;
    return r;
}
float* operator&(vec3f& v){
    return &v.x;
}

float& vec3f::operator[](unsigned int i){
    if(i>2) exit(-1);
    return *(&x+i);
}
