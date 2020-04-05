#include "quaternion.hh"

#define REDC "\033[91m"
#define GREC "\033[92m"
#define BLUC "\033[94m"
#define YELC "\033[95m"
#define ENDC "\033[0m"


/*****************************************************
 
    QUATERNION METHODS

*****************************************************/

quaternion::quaternion(double s, double x, double y, double z){
    this->s = s;
    this->v.x = x;
    this->v.y = y;
    this->v.z = z;
}
quaternion::quaternion(const vec4& vec){
    this->s = vec.w;
    this->v.x = vec.x;
    this->v.y = vec.y;
    this->v.z = vec.z;

}

quaternion::quaternion(const vec3& vec, double angle, bool degrees){
    if(degrees)
        angle = deg2rad(angle);
    
    angle /= 2.0;
    s = cos(angle);
    v = vec*sin(angle);
    this->normalize();
}

void quaternion::normalize(){
    double val = sqrt(s*s + v.x*v.x + v.y*v.y + v.z*v.z);
    if(val > 1.0e-8){
        s/=val;
        v.x/=val;
        v.y/=val;
        v.z/=val;
    }
    else{
        s = 1.0;
        v.x = 0.0;
        v.y = 0.0;
        v.z = 0.0;
    }
}

quaternion quaternion::conj(){
    return {s,-v.x,-v.y,-v.z};
}

// Rotate a vector using the quaternion
vec3 quaternion::rotate (const vec3& to_rotate)const{
    return 2.0*vec3::dot(v,to_rotate)*v + (s*s - vec3::dot(v,v))*to_rotate + 2.0*s*vec3::cross(v,to_rotate);
}

mat3 quaternion::toMat3()const{
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

quaternion operator*(const quaternion& q1, const quaternion& q2){
    quaternion r;
    r.s = q1.s*q2.s - vec3::dot(q1.v,q2.v);
    r.v = q1.s*q2.v + q2.s*q1.v - vec3::cross(q1.v,q2.v);
    return r;
}
bool operator==(quaternion& q1, quaternion& q2){
    return quaternion::testEquivalence(q1, q2);
}

quaternion operator*(const mat4& m, const quaternion& v){
    quaternion r;
    r.v.x = m.x.x*v.v.x + m.x.y*v.v.y + m.x.z*v.v.z + m.x.w*v.s;
    r.v.y = m.y.x*v.v.x + m.y.y*v.v.y + m.y.z*v.v.z + m.y.w*v.s;
    r.v.z = m.z.x*v.v.x + m.z.y*v.v.y + m.z.z*v.v.z + m.z.w*v.s;
    r.s   = m.w.x*v.v.x + m.w.y*v.v.y + m.w.z*v.v.z + m.w.w*v.s;
    return r;
}

quaternion operator*(const double& s, const quaternion& v){
    quaternion r;
    r.v.x = v.v.x*s;
    r.v.y = v.v.y*s;
    r.v.z = v.v.z*s;
    r.s = v.s*s;
    return r;
}
quaternion operator*(const quaternion& v, const double& s){
    quaternion r;
    r.v.x = v.v.x*s;
    r.v.y = v.v.y*s;
    r.v.z = v.v.z*s;
    r.s = v.s*s;
    return r;
}

quaternion& operator+=(quaternion& a, const quaternion& b){
    a.v.x += b.v.x;
    a.v.y += b.v.y;
    a.v.z += b.v.z;
    a.s += b.s;
    return a;
}
quaternion& operator-=(quaternion& a, const quaternion& b){
    a.v.x -= b.v.x;
    a.v.y -= b.v.y;
    a.v.z -= b.v.z;
    a.s -= b.s;
    return a;
}