#include "core/color.h"


Color::Color(float r_, float g_, float b_)
	: r(r_), g(g_), b(b_) {
}

bool Color::operator==(const Color& other) const {
	return (
		r == other.r &&
		g == other.g &&
		b == other.b
		);
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
