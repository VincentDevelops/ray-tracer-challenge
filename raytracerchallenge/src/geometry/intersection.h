#ifndef INTERSECTION_H
#define INTERSECTION_H

struct Sphere;

struct Intersection {
	float t;
	const Sphere* object;

	Intersection(float t_, const Sphere* o_)
		: t(t_), object(o_) {}


};

#endif // !INTERSECTION_H
