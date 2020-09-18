#include "vec3.hh"
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
const vec3 vec3::unit_x = vec3(1.0,0.0,0.0);
const vec3 vec3::unit_y = vec3(0.0,1.0,0.0);
const vec3 vec3::unit_z = vec3(0.0,0.0,1.0);

vec3::vec3(double argx, double argy, double argz){
    x=argx; y=argy; z=argz;
}
vec3 operator-(const vec3& v){
    return {-v.x,-v.y,-v.z};
}
void vec3::normalize(){
    double s = sqrt(x*x + y*y + z*z);
    if(s<1e-10){
        x=0.0; y=0.0; z=0.0;
    }
    else{
        x /= s;
        y /= s;
        z /= s;        
    }
}

vec3 vec3::normalize(const vec3& v){
    double s = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    vec3 ret;
    if (s<1e-8){
        ret.x=0.0; ret.y=0.0; ret.z=0.0;
    }else{
        ret.x = v.x/s;
        ret.y = v.y/s;
        ret.z = v.z/s;
    }
    return ret;
}

double vec3::length(){
    return sqrt(x*x + y*y + z*z);
}

vec3 vec3::cross(const vec3& v1, const vec3& v2){
    vec3 rv;
    rv.x = v1.y*v2.z - v1.z*v2.y;
    rv.y = v1.z*v2.x - v1.x*v2.z;
    rv.z = v1.x*v2.y - v1.y*v2.x;
    return rv;
}

double vec3::dot(const vec3& v1, const vec3& v2){
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

double vec3::getAngularDist(vec3& v1, vec3& v2){
	return acos(dot(normalize(v1), normalize(v2)));
}

void vec3::print(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f", x, y, z);
}

void vec3::println(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f\n", x, y, z);
}

vec4 vec3::expand(double w){
    vec4 v(x,y,z,w);
    return v;
}
std::array<float,3> vec3::gl_float_ref() const{
    return {(float)x, (float)y, (float)z};
}

/*****************************************************
    VECTOR 3 OPERATOR OVERLOADS
*****************************************************/

// Equivalence operator
bool operator==(const vec3& v1, const vec3& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return true;
    else
        return false;
}
// Anti-equivalence operator
bool operator!=(const vec3& v1, const vec3& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6)
        return false;
    else
        return true;
}
vec3& operator+=(vec3& a, const vec3& b){
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
    return a;
}
vec3& operator-=(vec3& a, const vec3& b){
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
    return a;
}
vec3 operator+(const vec3& v1, const vec3&v2){
    vec3 r;
    r.x = v1.x+v2.x;
    r.y = v1.y+v2.y;
    r.z = v1.z+v2.z;
    return r;
}

vec3 operator-(const vec3& v1, const vec3& v2){
    vec3 r;
    r.x = v1.x-v2.x;
    r.y = v1.y-v2.y;
    r.z = v1.z-v2.z;
    return r;
}
vec3 operator*(const double& s, const vec3& v){
    vec3 r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    return r;
}
vec3 operator*(const vec3& v, const double& s){
    vec3 r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    return r;
}
vec3 operator/(const vec3& v, const double& s){
    vec3 r;
    r.x = v.x/s;
    r.y = v.y/s;
    r.z = v.z/s;
    return r;
}
double* operator&(vec3& v){
    return &v.x;
}

double& vec3::operator[](unsigned int i){
    if(i>2) exit(-1);
    return *(&x+i);
}