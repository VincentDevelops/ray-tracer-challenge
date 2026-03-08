#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "geometry/sphere.h"

struct Intersection {
	float t;
	const Sphere* object;
};

#endif // !INTERSECTION_H
