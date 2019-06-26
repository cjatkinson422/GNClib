#include "astrodynamics.hpp"

KeplerianOrbit::KeplerianOrbit(vec3 position, vec3 velocity, double mu){
    
	double r = position.length();
	double v = velocity.length();

	vec3 h = vec3::cross(position, velocity);
	vec3 n = vec3::normalize(vec3::cross(vec3( 0.0,0.0,1.0 ), h));
	vec3 ebar = vec3::cross(velocity, h) * (1.0 / mu) - vec3::normalize(position);

	double a = -mu / (2.0*((v*v) / 2.0 - mu / r));
	double e = ebar.length();

	double omega = atan2(n.y, n.x);
	double i = acos(h.z / h.length());
	double w = acos(vec3::dot(n, vec3::normalize(ebar)));
	
	if (ebar.z < 0)
		w = 2 * PI - w;

	double nu = acos(vec3::dot(position, ebar) / (r*e));

	if (vec3::dot(position, velocity) < 0)
		nu = 2*PI-nu;
    
    specific_gravity = mu;
    major_axis = a;
    eccentricity = e;
    inclination = i;
    ascending_node = omega;
    periapse_angle = w;
    true_anomaly = nu;
    //TODO: add mean anomaly definition here when method for calculating it is done
}
