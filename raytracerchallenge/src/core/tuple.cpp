//tuple.cpp

#include "tuple.h"
#include <stdexcept>
#include <cmath>

// ================================================
// STATIC FUNCTIONS ===============================
// ================================================

[[nodiscard]] Tuple Tuple::normalize(const Tuple& vector) {
	if (!vector.is_vector())
		throw std::logic_error("normalize error: non-vector tuple passed");

	const float magnitude = Tuple::magnitude(vector);

	if (std::fabs(magnitude) < rtc::EPSILON)
		throw std::logic_error("normalize error: zero vector passed");

	return Tuple::vector(
		vector.x / magnitude,
		vector.y / magnitude,
		vector.z / magnitude
	);
}

[[nodiscard]] float Tuple::magnitude(const Tuple& vector) {
	
	if (!vector.is_vector())
		throw std::logic_error("magnitude error: non-vector tuple passed");
	
	float magnitude = 0;

	float x_sqrd	= vector.x * vector.x;
	float y_sqrd	= vector.y * vector.y;
	float z_sqrd	= vector.z * vector.z;
	float sum		= x_sqrd + y_sqrd + z_sqrd;
	magnitude		= std::sqrt(sum);

	return magnitude;
}



// ================================================
// OPERATOR OVERLOADS =============================
// ================================================


