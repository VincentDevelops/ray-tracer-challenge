//tuple.h

#ifndef TUPLE_H
#define TUPLE_H

#include "core/constants.h"
#include "core/math_utils.h"

struct Tuple {

private:
	static constexpr float VECTOR = 0.0f;
	static constexpr float POINT = 1.0f;
	static constexpr float DEFAULT = 0.0f;

public:


	float x = DEFAULT;
	float y = DEFAULT;
	float z = DEFAULT;
	float w = POINT;

	// Constructor for a Tuple point at (0,0,0)
	constexpr Tuple() = default;

	// Constructor for a Tuple at (x,y,z) and wither point
	//  or vector with w (1 - point / 0 - vector)
	constexpr Tuple(float x_, float y_, float z_, float w_)
		: x(x_), y(y_), z(z_), w(w_) {}
	
	

	// returns true if Tuple is a vector
	constexpr bool is_vector() const {
		return w == VECTOR;
	}

	// returns true if Tuple is a point
	constexpr bool is_point() const {
		return w == POINT;
	}



	// ================================================
	// STATIC FUNCTIONS ===============================
	// ================================================

	// returns a point Tuple at coordinates (x,y,z)
	constexpr static Tuple point(float new_x, float new_y, float new_z) {
		return Tuple(new_x, new_y, new_z, POINT);
	}
	
	// retuns a point Tuple at default coordinates
	constexpr static Tuple point() {
		return Tuple(DEFAULT, DEFAULT, DEFAULT, POINT);
	}
	
	// returns a vector Tuple with attributes (x,y,z)
	constexpr static Tuple vector(float new_x, float new_y, float new_z) {
		return Tuple(new_x, new_y, new_z, Tuple::VECTOR);
	}
	
	// returns a vector Tuple with default attributes
	constexpr static Tuple vector() {
		return Tuple(DEFAULT, DEFAULT, DEFAULT, VECTOR);
	}

	[[nodiscard]] static Tuple normalize(const Tuple& vector);

	// returns the cross product of two vectors
	//  logic error thrown if at least one is not a vector
	[[nodiscard]] constexpr static Tuple cross(const Tuple& vector1, const Tuple& vector2) {

		float new_x = vector1.y * vector2.z - vector1.z * vector2.y;
		float new_y = vector1.z * vector2.x - vector1.x * vector2.z;
		float new_z = vector1.x * vector2.y - vector1.y * vector2.x;

		return Tuple::vector(new_x, new_y, new_z);
	}
	
	// returns the magnitude of a vector - vector tuple required
	[[nodiscard]] static float magnitude(const Tuple &vector);

	// returns the dot product of two vectors
	//  logic error thrown if at least one is not a vector
	[[nodiscard]] constexpr static float dot(const Tuple& vector1, const Tuple& vector2) {

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
	[[nodiscard]] bool operator==(const Tuple& other) const {
		return rtc::float_equals(x, other.x) && rtc::float_equals(y, other.y) && rtc::float_equals(z, other.z) && rtc::float_equals(w, other.w);
	}

	// returns a Tuple with added attributes of calling
	//  Tuple and other could be either vector or point
	[[nodiscard]] constexpr Tuple operator+(const Tuple& other) const {
		return Tuple(x + other.x, y + other.y, z + other.z, w + other.w);
	}
	
	// returns a Tuple with subtracted attributes of calling
	//  Tuple and other, could be either vector or point
	[[nodiscard]] constexpr Tuple operator-(const Tuple& other) const {
		return Tuple(x - other.x, y - other.y, z - other.z, w - other.w);
	}

	// returns a negated tuple
	[[nodiscard]] constexpr Tuple operator-() const {
		return Tuple(-x, -y, -z, -w);
	}


	// returns a scaled vector through multiplication
	[[nodiscard]] constexpr Tuple operator*(float scaler) const {
		float new_x = x * scaler;
		float new_y = y * scaler;
		float new_z = z * scaler;
		float new_w = w * scaler;

		return Tuple(new_x, new_y, new_z, new_w);
	}

	// returns a scaled vector through division
	[[nodiscard]] constexpr Tuple operator/(float scaler) const {

		float new_x = x / scaler;
		float new_y = y / scaler;
		float new_z = z / scaler;
		float new_w = w / scaler;

		return Tuple(new_x, new_y, new_z, new_w);

	}

	
};

#endif // !1
