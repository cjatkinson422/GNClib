#include <iostream>
#include "linalg.hpp"
#include "rotations.hpp"

int main(){
    vec3 v1= vec3(1,0,4);
    vec3 v2= vec3(3,1,0);
    bool fail = false;

    if(vec3::dot(v1,v2) != 3){
        printf("ERROR:: Failed vec3::dot value!\n"); 
        fail = true;
    }
    if(vec3::dot(v1,v2) != vec3::dot(v2,v1)){
        printf("ERROR:: Failed vec3::dot commutative!\n");
        fail = true;
    }

    vec3 v3 = vec3::cross(v1,v2);
    v1.xyz = {-4,12,1};
    if(v3!=v1){
        printf("ERROR:: Failed cross product equality!\n");
        fail = true;
    }

    vec3 v4(1,1,1);
    vec3 v5(2,2,2);
    vec3 v6 = v4;
    v4.x=3;
    if(v4.x==v6.x){
        printf("ERROR:: Failed assignment operator test 1!\n");
        fail = true;
    }
    v4.xyz = v5.xyz;
    v5.xyz = v4.xyz;
    v5.x = 5;
    v4.x = 6;
    if(v5.x!=5 || v4.x!=6){
        printf("ERROR:: Failed assignment operator test 2!\n");
        fail = true;
    }

    if(!fail){
        printf("Passed all unit tests!\n");
    }

    return 0;    
}
