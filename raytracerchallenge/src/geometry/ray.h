#ifndef RAY_H
#define RAY_H

#include "core/tuple.h"
#include "core/matrix.h"
#include "core/math_utils.h"

struct Ray {
	Tuple origin = Tuple::point(0.0f, 0.0f, 0.0f);
	Tuple direction = Tuple::vector(0.0f, 0.0f, 0.0f);

	Ray(Tuple o_, Tuple d_) :
		origin(o_), direction(d_) {}

	Tuple position(float t) {
		return origin + direction * t;
	}




};

#endif // !RAY_H
