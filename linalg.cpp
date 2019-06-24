#include "linalg.hpp"

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

vec3::vec3(double argx, double argy, double argz){
    x=argx; y=argy; z=argz;
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
void operator+=(vec3& lhs, const vec3& rhs){
    lhs.x += rhs.x;
    lhs.y += rhs.y;
    lhs.z += rhs.z;
}
void operator-=(vec3& lhs, const vec3& rhs){
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
    lhs.z -= rhs.z;
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

/*****************************************************
    VECTOR 4 METHODS
*****************************************************/

vec4::vec4(double argx, double argy, double argz, double argw){
    x=argx; y=argy; z=argz; w=argw;
}

void vec4::normalize(){
    double s = sqrt(x*x + y*y + z*z + w*w);
    if(s<1e-8){
        x=0.0; y=0.0; z=0.0; w=0.0;
    }
    else{
        x /= s;
        y /= s;
        z /= s;        
        w /= s;
    }
}

double vec4::length(){
    return sqrt(x*x + y*y + z*z + w*w);
}

vec3 vec4::shrink(){
    return vec3(x,y,z);
}

void vec4::print(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f, " YELC "w:" ENDC " %f", x, y, z, w);
}

void vec4::println(){
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f, " YELC "w:" ENDC " %f\n", x, y, z, w);
}

/*****************************************************
    VECTOR 4 OPERATOR OVERLOADS
*****************************************************/

// Equivalence operator
bool operator==(const vec4& v1, const vec4& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6 && abs(v1.w-v2.w) < 1e-6)
        return true;
    else
        return false;
}
// Anti-equivalence operator
bool operator!=(const vec4& v1, const vec4& v2){
    if (abs(v1.x-v2.x) < 1e-6 && abs(v1.y-v2.y) < 1e-6 && abs(v1.z-v2.z) < 1e-6 && abs(v1.w-v2.w) < 1e-6)
        return false;
    else
        return true;
}

vec4 operator+(const vec4& v1, const vec4&v2){
    vec4 r;
    r.x = v1.x+v2.x;
    r.y = v1.y+v2.y;
    r.z = v1.z+v2.z;
    r.w = v1.w+v2.w;
    return r;
}

vec4 operator-(const vec4& v1, const vec4& v2){
    vec4 r;
    r.x = v1.x-v2.x;
    r.y = v1.y-v2.y;
    r.z = v1.z-v2.z;
    r.w = v1.w-v2.w;
    return r;
}
vec4 operator*(const double& s, const vec4& v){
    vec4 r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    r.w = v.w*s;
    return r;
}
vec4 operator*(const vec4& v, const double& s){
    vec4 r;
    r.x = v.x*s;
    r.y = v.y*s;
    r.z = v.z*s;
    r.w = v.w*s;
    return r;
}
/********************************************************
 
        MATRIX

*********************************************************/

/********************************************************
    MATRIX 3 METHODS
*********************************************************/
mat3::mat3(double def, bool identity){
    if(identity){
        x = vec3(def,0.0,0.0);
        y = vec3(0.0,def,0.0);
        z = vec3(0.0,0.0,def);
    }else{
        x = vec3(def,def,def);
        y = vec3(def,def,def);
        z = vec3(def,def,def);
    }
}
inline mat3 mat3::eye3(){
    mat3 m = mat3(1.0,true);
    return m;
}

void mat3::orthonormalize(){
    z = vec3::cross(x,y);
    y = vec3::cross(z,x);
    x.normalize();
    y.normalize();
    z.normalize();
}

mat3 mat3::transpose(){
    mat3 r;
    r.x.x = x.x;
    r.x.y = y.x;
    r.x.z = z.x;
    r.y.x = x.y;
    r.y.y = y.y;
    r.y.z = z.y;
    r.z.x = x.z;
    r.z.y = y.z;
    r.z.z = z.z;
    return r;
}

vec3 mat3::diag(){
    vec3 t;
    t.x = x.x;
    t.y = y.y;
    t.z = z.z;
    return t;
}

double mat3::trace(){
    return x.x+y.y+z.z;
}

quaternion mat3::toQuat(){
    this->orthonormalize();
    quaternion q;

    double t = this->trace();
    if(t > 0){
        double S = sqrt(t+1.0)*2.0;
        q.s = 0.25 * S;
        q.v.x = (z.y-y.z)/S;
        q.v.y = (x.z-z.x)/S;
        q.v.z = (y.x-x.y)/S;
    }else if (x.x > y.y && x.x > z.z){
        double S = sqrt(1.0+ x.x-y.y-z.z)*2.0;
        q.s = (z.y-y.z)/S;
        q.v.x = 0.25*S;
        q.v.y = (x.y+y.x)/S;
        q.v.z = (x.z+z.x)/S;
    }else if (y.y>z.z){
        double S = sqrt(1.0 + y.y - x.x - z.z) * 2.0;
        q.s = (x.z - z.x)/S;
        q.v.x = (x.y + y.x)/S;
        q.v.y = 0.25 * S;
        q.v.z = (y.z + z.y)/S;
    }else{
        double S = sqrt(1.0 + z.z - x.x - y.y)*2.0;
        q.s = (y.x - x.y)/S;
        q.v.x = (x.z+z.x)/S;
        q.v.y = (y.z+z.y)/S;
        q.v.z = 0.25 * S;
    }

    q.normalize();
    return q;
}

mat4 mat3::expand(){
    mat4 r;
    r.x = x.expand(0);
    r.y = y.expand(0);
    r.z = z.expand(0);
    r.w = vec4(0,0,0,1);
    return r;
}

void mat3::print(){
    printf(REDC "xx:"  ENDC " %f, " GREC "xy:" ENDC " %f, " BLUC "xz:" ENDC " %f\n", x.x, x.y, x.z);
    printf(REDC "yx:"  ENDC " %f, " GREC "yy:" ENDC " %f, " BLUC "yz:" ENDC " %f\n", y.x, y.y, y.z);
    printf(REDC "zx:"  ENDC " %f, " GREC "zy:" ENDC " %f, " BLUC "zz:" ENDC " %f\n", z.x, z.y, z.z);
}

/********************************************************
    MATRIX 3 OPERATOR OVERLOADS
*********************************************************/

mat3 operator*(const mat3& m1, const mat3& m2){
    mat3 r;

    r.x.x = m1.x.x*m2.x.x + m1.x.y*m2.y.x + m1.x.z*m2.z.x;
    r.x.y = m1.x.x*m2.x.y + m1.x.y*m2.y.y + m1.x.z*m2.z.y;
    r.x.z = m1.x.x*m2.x.z + m1.x.y*m2.y.z + m1.x.z*m2.z.z;

    r.y.x = m1.y.x*m2.x.x + m1.y.y*m2.y.x + m1.y.z*m2.z.x;
    r.y.y = m1.y.x*m2.x.y + m1.y.y*m2.y.y + m1.y.z*m2.z.y;
    r.y.z = m1.y.x*m2.x.z + m1.y.y*m2.y.z + m1.y.z*m2.z.z;

    r.y.x = m1.z.x*m2.x.x + m1.z.y*m2.y.x + m1.z.z*m2.z.x;
    r.y.y = m1.z.x*m2.x.y + m1.z.y*m2.y.y + m1.z.z*m2.z.y;
    r.y.z = m1.z.x*m2.x.z + m1.z.y*m2.y.z + m1.z.z*m2.z.z;

    return r;
}

vec3 operator*(const mat3& m, const vec3& v){
    vec3 r;
    r.x = m.x.x*v.x + m.x.y*v.y + m.x.z*v.z;
    r.y = m.y.x*v.x + m.y.y*v.y + m.y.z*v.z;
    r.z = m.z.x*v.x + m.z.y*v.y + m.z.z*v.z;
    return r;
}

mat3 operator-(const mat3& m1, const mat3& m2){
    mat3 mr;
    mr.x = m1.x - m2.x;
    mr.y = m1.y - m2.y;
    mr.z = m1.z - m2.z;
    return mr;
}

mat3 operator+(const mat3& m1, const mat3& m2){
    mat3 mr;
    mr.x = m1.x+m2.x;
    mr.y = m1.y+m2.y;
    mr.z = m2.z+m2.z;
    return mr;
}

/********************************************************
    MATRIX 4 METHODS
*********************************************************/
mat4::mat4(double def, bool identity){
    if(identity){
        x = vec4(def,0.0,0.0,0.0);
        y = vec4(0.0,def,0.0,0.0);
        z = vec4(0.0,0.0,def,0.0);
        w = vec4(0.0,0.0,0.0,def);
    }else{
        x = vec4(def,def,def,def);
        y = vec4(def,def,def,def);
        z = vec4(def,def,def,def);
        w = vec4(def,def,def,def);
    }
}

inline mat4 mat4::TransMat(vec3 dir){
    mat4 m = mat4(1.0,true);
    m.x.w = dir.x;
    m.y.w = dir.y;
    m.z.w = dir.z;
    return m;
}
inline mat4 mat4::ScaleMat(double scale){
    return mat4(scale, true);
}
inline mat4 mat4::eye4(){
    mat4 m = mat4(1.0,true);
    return m;
}

mat4 mat4::transpose(){
    mat4 r;
    r.x.x = x.x;
    r.x.y = y.x;
    r.x.z = z.x;
    r.x.w = w.x;

    r.y.x = x.y;
    r.y.y = y.y;
    r.y.z = z.y;
    r.y.w = w.y;

    r.z.x = x.z;
    r.z.y = y.z;
    r.z.z = z.z;
    r.z.w = w.z;

    r.w.x = x.w;
    r.w.y = y.w;
    r.w.z = z.w;
    r.w.w = w.w;
    return r;
}

mat3 mat4::shrink(){
    mat3 r;
    r.x = x.shrink();
    r.y = y.shrink();
    r.z = z.shrink();
    return r;
}

/********************************************************
    MATRIX OPERATOR OVERLOADS
*********************************************************/

mat4 operator*(const mat4& m1, const mat4& m2){
    mat4 r;

    r.x.x = m1.x.x*m2.x.x + m1.x.y*m2.y.x + m1.x.z*m2.z.x + m1.x.w*m2.w.x;
    r.x.y = m1.x.x*m2.x.y + m1.x.y*m2.y.y + m1.x.z*m2.z.y + m1.x.w*m2.w.y;
    r.x.z = m1.x.x*m2.x.z + m1.x.y*m2.y.z + m1.x.z*m2.z.z + m1.x.w*m2.w.z;
    r.x.w = m1.x.x*m2.x.w + m1.x.y*m2.y.w + m1.x.z*m2.z.w + m1.x.w*m2.w.w;

    r.y.x = m1.y.x*m2.x.x + m1.y.y*m2.y.x + m1.y.z*m2.z.x + m1.y.w*m2.w.x;
    r.y.y = m1.y.x*m2.x.y + m1.y.y*m2.y.y + m1.y.z*m2.z.y + m1.y.w*m2.w.y;
    r.y.z = m1.y.x*m2.x.z + m1.y.y*m2.y.z + m1.y.z*m2.z.z + m1.y.w*m2.w.z;
    r.y.w = m1.y.x*m2.x.w + m1.y.y*m2.y.w + m1.y.z*m2.z.w + m1.y.w*m2.w.w;

    r.z.x = m1.z.x*m2.x.x + m1.z.y*m2.y.x + m1.z.z*m2.z.x + m1.z.w*m2.w.x;
    r.z.y = m1.z.x*m2.x.y + m1.z.y*m2.y.y + m1.z.z*m2.z.y + m1.z.w*m2.w.y;
    r.z.z = m1.z.x*m2.x.z + m1.z.y*m2.y.z + m1.z.z*m2.z.z + m1.z.w*m2.w.z;
    r.z.w = m1.z.x*m2.x.w + m1.z.y*m2.y.w + m1.z.z*m2.z.w + m1.z.w*m2.w.w;

    r.w.x = m1.w.x*m2.x.x + m1.w.y*m2.y.x + m1.w.z*m2.z.x + m1.w.w*m2.w.x;
    r.w.y = m1.w.x*m2.x.y + m1.w.y*m2.y.y + m1.w.z*m2.z.y + m1.w.w*m2.w.y;
    r.w.z = m1.w.x*m2.x.z + m1.w.y*m2.y.z + m1.w.z*m2.z.z + m1.w.w*m2.w.z;
    r.w.w = m1.w.x*m2.x.w + m1.w.y*m2.y.w + m1.w.z*m2.z.w + m1.w.w*m2.w.w;

    return r;
}

vec4 operator*(const mat4& m, const vec4& v){
    vec4 r;
    r.x = m.x.x*v.x + m.x.y*v.y + m.x.z*v.z + m.x.w*v.w;
    r.y = m.y.x*v.x + m.y.y*v.y + m.y.z*v.z + m.y.w*v.w;
    r.z = m.z.x*v.x + m.z.y*v.y + m.z.z*v.z + m.z.w*v.w;
    r.w = m.w.x*v.x + m.w.y*v.y + m.w.z*v.z + m.w.w*v.w;
    return r;
}

mat4 operator-(const mat4& m1, const mat4& m2){
    mat4 mr;
    mr.x = m1.x - m2.x;
    mr.y = m1.y - m2.y;
    mr.z = m1.z - m2.z;
    mr.w = m1.w - m2.w;
    return mr;
}

mat4 operator+(const mat4& m1, const mat4& m2){
    mat4 mr;
    mr.x = m1.x+m2.x;
    mr.y = m1.y+m2.y;
    mr.z = m2.z+m2.z;
    mr.w = m1.w+m2.w;
    return mr;
}

/*****************************************************
 
    QUATERNION METHODS

*****************************************************/

quaternion::quaternion(double s, double x, double y, double z){
    this->s = s;
    this->v.x = x;
    this->v.y = y;
    this->v.z = z;
}

quaternion::quaternion(const vec3& vec, double angle, bool degrees){
    if(degrees)
        angle = deg2rad(angle);
    
    angle /= 2.0;
    s = cos(angle);
    v = vec*sin(angle);
}

void quaternion::normalize(){
    double val = sqrt(s*s + v.x*v.x + v.y*v.y + v.z*v.z);
    s/=val;
    v.x/=val;
    v.y/=val;
    v.z/=val;
}

// Rotate a vector using the quaternion
vec3 quaternion::rotate (const vec3& to_rotate)const{
    return 2.0*vec3::dot(v,to_rotate)*v + (s*s - vec3::dot(v,v))*to_rotate + 2.0*s*vec3::cross(v,to_rotate);
}

mat3 quaternion::toMat3(){
    this->normalize();
    mat3 r;
    r.x.x = 1.0 - 2.0*v.y*v.y - 2.0*v.z*v.z;
    r.x.y = 2.0*v.x*v.y - 2.0*v.z*s;
    r.x.z = 2.0*v.x*v.z + 2.0*v.y*s;

    r.y.x = 2.0*v.x*v.y + 2.0*v.z*s;
    r.y.y = 1.0 - 2.0*v.x*v.x - 2.0*v.z*v.z;
    r.y.z = 2.0*v.y*v.z - 2.0*v.x*s;

    r.z.x = 2.0*v.x*v.z - 2.0*v.y*s;
    r.z.y = 2.0*v.y*v.z + 2.0*v.x*s;
    r.z.z = 1.0 - 2.0*v.x*v.x - 2.0*v.y*v.y;

    r.orthonormalize();
    return r;
}

void quaternion::print()const{
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f, " YELC "w:" ENDC " %f", v.x, v.y, v.z, s);
}

void quaternion::println()const{
    printf(REDC "x:"  ENDC " %f, " GREC "y:" ENDC " %f, " BLUC "z:" ENDC " %f, " YELC "s:" ENDC " %f\n", v.x, v.y, v.z, s);
}

bool quaternion::testEquivalence(const quaternion& q1, const quaternion& q2){
    vec3 v_base(1.0,1.0,1.0);
    vec3 v_rot1 = q1.rotate(v_base);
    vec3 v_rot2 = q2.rotate(v_base);
    return (v_rot1 == v_rot2);
}

/*****************************************************
    QUATERNION OPERATOR OVERLOADS
*****************************************************/

quaternion operator*(const quaternion& q1, const quaternion q2){
    quaternion r;
    r.s = q1.s*q2.s - vec3::dot(q1.v,q2.v);
    r.v = q1.s*q2.v + q2.s*q1.v - vec3::cross(q2.v,q1.v);
    return r;
}

/******************************************************
 * 
 *  NON-CLASS FUNCTIONS
 * 
******************************************************/

const double rad2deg(double rad){
    return rad*180.0 / PI;
}

const double deg2rad(double deg){
    return deg * PI / 180.0;
}
