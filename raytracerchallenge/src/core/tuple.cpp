//tuple.cpp

#include "tuple.h"
#include <limits>
#include <cmath>


Tuple::Tuple() {
	x = 0;
	y = 0;
	z = 0;
	w = 1;
}

Tuple::Tuple(float new_x, float new_y, float new_z, 
				float new_w) {
	x = new_x;
	y = new_y;
	z = new_z;
	w = new_w;
}

// sets tuple as a vector if true is passed
Tuple::Tuple(bool new_w) {
	if (new_w == false)
		w = 1.0;
	else
		w = 0.0;

	x = 0.0;
	y = 0.0;
	z = 0.0;
}

bool Tuple::is_vector() const {
	return w == 0.0f;
}

bool Tuple::is_point() const {
	return w == 1.0f;
}

// returns a point tuple
Tuple Tuple::point(float new_x, 
							float new_y, float new_z) {
	return Tuple(new_x, new_y, new_z, 1.0f);
}

Tuple Tuple::point() {
	return Tuple(0.0f, 0.0f, 0.0f, 1.0f);
}

// returns a vector tuple
Tuple Tuple::vector(float new_x,
							float new_y, float new_z) {
	return Tuple(new_x, new_y, new_z, 0.0f);
}

Tuple Tuple::vector() {
	return Tuple(0.0f, 0.0f, 0.0f, 0.0f);
}

// returns true if each value is within marginal equality
bool Tuple::operator==(const Tuple& tuple) const {

	if (std::fabs(x - tuple.x) < std::numeric_limits<double>::epsilon())
		return false;
	if (std::fabs(y - tuple.y) < std::numeric_limits<double>::epsilon())
		return false;
	if (std::fabs(z - tuple.z) < std::numeric_limits<double>::epsilon())
		return false;
	if (w != tuple.w)
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

	if (new_w >= 2)
		return NULL;

	return Tuple(new_x, new_y, new_z, new_w);
}

// need to account for proper calculations
// review page 7
Tuple Tuple::operator-(const Tuple& tuple) const {
	float new_x = x - tuple.x;
	float new_y = y - tuple.y;
	float new_z = z - tuple.z;
	float new_w = w - tuple.w;

	if (new_w == 0)
		return Tuple::vector(new_x, new_y, new_z);
	else if (new_w == 1)
		return Tuple::point(new_x, new_y, new_z);
	else
		return NULL;

	
}
