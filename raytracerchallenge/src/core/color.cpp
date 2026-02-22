#include "core/color.h"
#include <limits>
#include <cmath>
#include <iostream>


Color::Color(float r_, float g_, float b_)
	: r(r_), g(g_), b(b_) {
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
