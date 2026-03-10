#ifndef SPHERE_H
#define SPHERE_H

#include "geometry/ray.h"
#include "core/matrix.h"
#include "geometry/intersection.h"
#include "core/math_utils.h"
#include "core/tuple.h"

struct Sphere {
	Tuple center = Tuple::point(0.0f, 0.0f, 0.0f);

	Matrix transform = Matrix::identity(4);

	std::size_t radius = 1.0f;
	

	constexpr Sphere() = default;

	constexpr Sphere(Matrix& trans) :
		transform(trans) {}\

	[[nodiscard]] constexpr void set_transform(const Matrix& trans) {
		transform = trans;
	}

	[[nodiscard]] std::vector<Intersection> intersect(Ray ray);



};

#endif // !SPHERE_H
