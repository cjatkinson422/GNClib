#include <iostream>
#include <ctime>
#include "linalg.hpp"


#define REDC "\033[91m"
#define GREC "\033[92m"
#define ENDC "\033[0m"


int main(){
    vec3 v1= vec3(1,0,4);
    vec3 v2= vec3(3,1,0);
    bool fail = false;

    if(vec3::dot(v1,v2) != 3){
        printf(REDC "ERROR" ENDC ":: Failed vec3::dot value!\n"); 
        fail = true;
    }
    if(vec3::dot(v1,v2) != vec3::dot(v2,v1)){
        printf(REDC "ERROR" ENDC ":: Failed vec3::dot commutative!\n");
        fail = true;
    }

    vec3 v3 = vec3::cross(v1,v2);
    v1.set({-4,12,1});
    if(v3!=v1){
        printf(REDC "ERROR" ENDC ":: Failed cross product equality!\n");
        fail = true;
    }

    vec3 v4(1,1,1);
    vec3 v5(2,2,2);
    vec3 v6 = v4;
    v4.x=3;
    if(v4.x==v6.x){
        printf(REDC "ERROR" ENDC ":: Failed assignment operator test 1!\n");
        fail = true;
    }
    v4=v5;
    v5=v4;
    v5.x = 5;
    v4.x = 6;
    if(v5.x!=5 || v4.x!=6){
        printf(REDC "ERROR" ENDC ":: Failed assignment operator test 2!\n");
        fail = true;
    }

    if( sizeof(double)*3 != sizeof(v5) ){
        printf(REDC "ERROR" ENDC ":: Failed vector memory size check!\n");
        fail = true;
    }


    v1.x = 1.0;
    v1.y = 0.0;
    v1.z = 0.0;

    for(double i = 0.0; i < 720.0; ++i){
        quaternion q1(v1,i,true);
        mat3 M = q1.toMat3();
        quaternion q2 = M.toQuat();

        if(!quaternion::testEquivalence(q1,q2)){
            printf(REDC "ERROR" ENDC ":: Failed X quaternion to DCM and DCM to quaternion check!%f\n",i);
            fail = true;
            break;
        }
    }

    v1.x = 0.0;
    v1.y = 1.0;
    v1.z = 0.0;

    for(double i = 0.0; i < 720.0; ++i){
        quaternion q1(v1,i,true);
        mat3 M = q1.toMat3();
        quaternion q2 = M.toQuat();

        if(!quaternion::testEquivalence(q1,q2)){
            printf(REDC "ERROR" ENDC ":: Failed Y quaternion to DCM and DCM to quaternion check! %f\n", i);
            fail = true;
            break;
        }
    }

    v1.x = 0.0;
    v1.y = 0.0;
    v1.z = 1.0;

    for(double i = 0.0; i < 720.0; ++i){
        quaternion q1(v1,i,true);
        mat3 M = q1.toMat3();
        quaternion q2 = M.toQuat();

        if(!quaternion::testEquivalence(q1,q2)){
            printf(REDC "ERROR" ENDC ":: Failed Z quaternion to DCM and DCM to quaternion check! %f\n",i);
            fail = true;
            break;
        }
    }

    v1.x = 1.0;
    v1.y = -4.0;
    v1.z = -7.0;
    v1.normalize();

    for(double i = 0.0; i < 720.0; ++i){
        quaternion q1(v1,i,true);
        mat3 M = q1.toMat3();
        quaternion q2 = M.toQuat();

        if(!quaternion::testEquivalence(q1,q2)){
            printf(REDC "ERROR" ENDC ":: Failed composite quaternion to DCM and DCM to quaternion check! %f\n",i);
            fail = true;
            break;
        }
    }
    double d = 102385098220.9235235;
    clock_t time = clock();
    for (unsigned long int i = 0; i < 1000000; ++i){
        float f = (float)d;
    }
    time = clock() - time;
    double t = (double)time / CLOCKS_PER_SEC;
    printf("1,000,000 float casts took %lf seconds \n", t);

    // Print to screen if all unit tests successful
    if(!fail){
        printf(GREC "Passed all unit tests!\n" ENDC);
    }
    return 0;
}
