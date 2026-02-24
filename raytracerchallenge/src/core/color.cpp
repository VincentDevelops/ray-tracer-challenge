#include "core/color.h"
#include <limits>
#include <cmath>
#include <iostream>


Color::Color(float r_, float g_, float b_)
	: r(r_), g(g_), b(b_) {
}

int Color::to_ppm(float v) {
	if (v < 0.0f) v = 0.0f;
	if (v > 1.0f) v =  1.0f;
	// addition of 0.5 to round up if >.5
	return static_cast<int>(v * 255 + 0.5f);
}


bool Color::operator==(const Color& other) const {
	if (std::fabs(r - other.r) > Color::EPSILON)
		return false;
	if (std::fabs(g - other.g) > Color::EPSILON)
		return false;
	if (std::fabs(b - other.b) > Color::EPSILON)
		return false;

	return true;
}

Color Color::operator+(const Color& other) const {
	return Color(
		r + other.r,
		g + other.g,
		b + other.b
	);
}

Color Color::operator-(const Color& other) const {
	return Color(
		r - other.r,
		g - other.g,
		b - other.b
	);
}

Color Color::operator*(const Color& other) const {
	return Color(
		r * other.r,
		g * other.g,
		b * other.b
	);
}

Color Color::operator*(const float& scaler) const {
	return Color(
		r * scaler,
		g * scaler,
		b * scaler
	);
}
