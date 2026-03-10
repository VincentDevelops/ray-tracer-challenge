#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>

struct Sphere;


struct Intersection {
	float t;
	const Sphere* object;

	Intersection(float t_, Sphere* o_)
		: t(t_), object(o_) {}

	
	static std::vector<Intersection> intersections(auto&...);
};

#endif // !INTERSECTION_H
