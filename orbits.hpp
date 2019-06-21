#include "linalg.hpp"

class keplerianOrbit{
public:
    // Contained data
    double major_axis = 0.0;
    double eccentricity = 0.0;
    double inclination = 0.0;
    double ascending_node = 0.0;
    double periapse_angle = 0.0;
    double mean_anomaly = 0.0;
    double true_anomaly = 0.0;

    keplerianOrbit(vec3,vec3);
    keplerianOrbit(double,double,double,double,double,double);

};
