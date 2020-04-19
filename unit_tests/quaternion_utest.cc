#include "quaternion_utest.hh"

#define REDC "\033[91m"
#define GREC "\033[92m"
#define BLUC "\033[94m"
#define YELC "\033[95m"
#define ENDC "\033[0m"

void quaternion_unit_tests(){
    unit_test::zero_rotation();
    unit_test::rotations();
}


void unit_test::rotations(){

    // check a rotation of an x vector about the y axis
    quaternion q1(vec3(0.0, 1.0, 0.0), 90.0, true);
    vec3 v1(1.0, 0.0, 0.0);
    vec3 v2 = q1.rotate(v1);

    // check the result. Rotating an x unit vector by positive 90 degrees
    // about the y axis should result in a vector pointing towards -z
    if( v2 != vec3(0.0, 0.0, -1.0)){
        printf(REDC "ERROR" ENDC ":: Failed quaternion y rotation.\n");
    }

    // Now lets compose that quaternion with another quaternion
    //
    // since we follow the convetion of transformation matrices, the new local rotation should go on
    // the left, thus, q2 * q1 should result in a second rotation in the frame of the first.
    // so since q1 is a 90 degree rotation about y, its x axis points to -z and its z axis now points to x
    // so if we were to add a second rotation about the z (the local z) of positive 90 degrees, an x vector
    // rotated by this total transformation should point in the positive y global direction.

    quaternion q2(vec3(0.0, 0.0, 1.0), 90.0, true);
    quaternion q3 = (q2 * q1);
    q3.normalize();
    vec3 v3 = q3.rotate(v1);

    if(v3 != vec3(0.0, 1.0, 0.0)){
        printf(REDC "ERROR" ENDC ":: Failed quaternion composition check!\n");
        v3.println();
    }
}

void unit_test::zero_rotation(){
    // Checks the quatenion 0 rotation by rotating and x vector by a 0 quaternion
    // Also checks the bracket
    quaternion q1 = {0.0,0.0,0.0,1.0};
    vec3 v1 = {1.0, 0.0, 0.0};

    vec3 v2 = q1.rotate(v1);

    if(v1 != v2){
        printf(REDC "ERROR" ENDC ":: Failed quaternion 0 rotation check!\n");
    }
}

