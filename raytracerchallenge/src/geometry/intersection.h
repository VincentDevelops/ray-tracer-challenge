#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "shapes/sphere.h"

struct Intersection {
	float t;
	const Sphere* object;
};

#endif // !INTERSECTION_H
