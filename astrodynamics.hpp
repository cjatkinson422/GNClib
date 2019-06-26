#include "linalg.hpp"

class KeplerianOrbit{
public:
    // Contained data
    double specific_gravity = 0.0;
    double major_axis = 0.0;
    double eccentricity = 0.0;
    double inclination = 0.0;
    double ascending_node = 0.0;
    double periapse_angle = 0.0;
    double mean_anomaly = 0.0;
    double true_anomaly = 0.0;

    KeplerianOrbit(vec3,vec3,double);
    KeplerianOrbit(double,double,double,double,double,double);


};
