#include "dynamics.hh"


mat4 GNC::cross_matrix(vec3 v){
    return mat4({
        { 0.0,  v.z, -v.y, v.x},
        {-v.z,  0.0,  v.x, v.y},
        { v.y, -v.x,  0.0, v.z},
        {-v.x, -v.y, -v.z, 0.0}
    });
}