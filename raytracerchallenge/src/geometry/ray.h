#ifndef RAY_H
#define RAY_H

#include "core/tuple.h"
#include "core/matrix.h"
#include "core/math_utils.h"


struct Ray {
	Tuple origin = Tuple::point(0.0f, 0.0f, 0.0f);
	Tuple direction = Tuple::vector(0.0f, 0.0f, 0.0f);

	constexpr Ray() = default;

	constexpr Ray(Tuple o_, Tuple d_) :
		origin(o_), direction(d_) {}

	[[nodiscard]] Tuple position(const float t) const {
		return origin + direction * t;
	}

	[[nodiscard]] Ray transform(const Matrix& translation) const {
		return Ray(
			translation * origin,
			translation * direction
		);
	}

	[[nodiscard]] Ray scaling(const Matrix& scaler) const {
		return Ray(
			scaler * origin,
			scaler * direction
		);
	}

};

#endif // !RAY_H
