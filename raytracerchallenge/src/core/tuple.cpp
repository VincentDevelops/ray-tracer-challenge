//tuple.cpp

#include "tuple.h"
#include <limits>
#include <cmath>
#include <iostream>


Tuple::Tuple() {
	x = DEFAULT;
	y = DEFAULT;
	z = DEFAULT;
	w = POINT;
}

Tuple::Tuple(float new_x, float new_y, float new_z, 
				float new_w) {
	x = new_x;
	y = new_y;
	z = new_z;
	w = new_w;
}

bool Tuple::is_vector() const {
	return w == VECTOR;
}

bool Tuple::is_point() const {
	return w == POINT;
}


// ================================================
// STATIC FUNCTIONS ===============================
// ================================================

// returns a point tuple
Tuple Tuple::point(float new_x, 
							float new_y, float new_z) {
	return Tuple(new_x, new_y, new_z, Tuple::POINT);
}

Tuple Tuple::point() {
	return Tuple(Tuple::DEFAULT, Tuple::DEFAULT, Tuple::DEFAULT, Tuple::POINT);
}

// returns a vector tuple
Tuple Tuple::vector(float new_x,
							float new_y, float new_z) {
	return Tuple(new_x, new_y, new_z, Tuple::VECTOR);
}

Tuple Tuple::vector() {
	return Tuple(Tuple::DEFAULT, Tuple::DEFAULT, Tuple::DEFAULT, Tuple::VECTOR);
}

Tuple Tuple::normalize(const Tuple& vector) {
	if (!vector.is_vector())
		throw std::logic_error("normalize error: non-vector tuple passed");

	const float magnitude = Tuple::magnitude(vector);

	if (std::fabs(magnitude) < Tuple::EPSILON)
		throw std::logic_error("normalize error: zero vector passed");

	return Tuple::vector(
		vector.x / magnitude,
		vector.y / magnitude,
		vector.z / magnitude
	);
}

Tuple Tuple::cross(const Tuple& vector1, const Tuple& vector2) {
	if (!vector1.is_vector() || !vector2.is_vector())
		throw std::logic_error("dot error: non-vector tuple passed");

	float new_x = vector1.y * vector2.z - vector1.z * vector2.y;
	float new_y = vector1.z * vector2.x - vector1.x * vector2.z;
	float new_z = vector1.x * vector2.y - vector1.y * vector2.x;

	return Tuple::vector(new_x, new_y, new_z);
}

float Tuple::magnitude(const Tuple& vector) {
	
	if (!vector.is_vector())
		throw std::logic_error("magnitude error: non-vector tuple passed");
	
	float magnitude = 0;

	float x_sqrd = vector.x * vector.x;
	float y_sqrd = vector.y * vector.y;
	float z_sqrd = vector.z * vector.z;
	float sum		= x_sqrd + y_sqrd + z_sqrd;
	magnitude		= std::sqrt(sum);

	return magnitude;
}

float Tuple::dot(const Tuple& vector1, const Tuple& vector2) {
	if (!vector1.is_vector() || !vector2.is_vector())
		throw std::logic_error("dot error: non-vector tuple passed");

	return
		vector1.x * vector2.x +
		vector1.y * vector2.y +
		vector1.z * vector2.z;
}



// ================================================
// OPERATOR OVERLOADS =============================
// ================================================


// returns true if each value is within marginal equality
//  of approximately epsilon
bool Tuple::operator==(const Tuple& tuple) const {

	if (std::fabs(x - tuple.x) > Tuple::EPSILON)
		return false;
	if (std::fabs(y - tuple.y) > Tuple::EPSILON)
		return false;
	if (std::fabs(z - tuple.z) > Tuple::EPSILON)
		return false;
	if (std::fabs(w - tuple.w) > Tuple::EPSILON)
		return false;

	return true;
}

// need to account for proper calculations
// review page 7
Tuple Tuple::operator+(const Tuple& tuple) const {
	float new_x = x + tuple.x;
	float new_y = y + tuple.y;
	float new_z = z + tuple.z;
	float new_w = w + tuple.w;

	if (new_w == Tuple::VECTOR)
		return Tuple::vector(new_x, new_y, new_z);
	if (new_w == Tuple::POINT)
		return Tuple::point(new_x, new_y, new_z);


	throw std::logic_error("operator+ error: Invalid Tuple addition (point + point)");
}

// need to account for proper calculations
// review page 7
Tuple Tuple::operator-(const Tuple& tuple) const {

	float new_x = x - tuple.x;
	float new_y = y - tuple.y;
	float new_z = z - tuple.z;
	float new_w = w - tuple.w;

	if (new_w == 0.0f)
		return Tuple::vector(new_x, new_y, new_z);
	if (new_w == 1.0f)
		return Tuple::point(new_x, new_y, new_z);	

	// new_w is < 0
	throw std::logic_error("operator- error: Invalid Tuple subtraction (vector - point)");
}

Tuple Tuple::operator-() const {
	return Tuple(-x, -y, -z, -w);
}

Tuple Tuple::operator*(const float& scaler) const {
	float new_x = x * scaler;
	float new_y = y * scaler;
	float new_z = z * scaler;
	float new_w = w * scaler;

	return Tuple(new_x, new_y, new_z, new_w);
}

Tuple Tuple::operator/(const float& scaler) const {
	if (scaler == 0.0f)
		throw std::logic_error("operator/ error: cannot divide by zero");

	float new_x = x / scaler;
	float new_y = y / scaler;
	float new_z = z / scaler;
	float new_w = w / scaler;

	return Tuple(new_x, new_y, new_z, new_w);

}