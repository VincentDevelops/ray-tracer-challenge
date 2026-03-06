#ifndef RTC_COLOR_H
#define RTC_COLOR_H

#include <cmath>
#include "core/math_utils.h"
#include "core/constants.h"

struct Color {
private:
	static constexpr float BLACK = 0.0f;
	static constexpr float WHITE = 1.0f;

public: 

	float r = BLACK;
	float g = BLACK;
	float b = BLACK;

	constexpr Color() = default;
	constexpr Color(float r_, float g_, float b_)
		: r(r_), g(g_), b(b_) {
	}
	// ================================================
	// STATIC FUNCTIONS ===============================
	// ================================================

	// return a clamped version of v to round up or down
	[[nodiscard]] static int to_ppm(float v) {
		if (v < 0.0f) v = 0.0f;
		if (v > 1.0f) v = 1.0f;
		// addition of 0.5 to round up if >.5
		return static_cast<int>(v * 255 + 0.5f);
	}


	// ================================================
	// OPERATOR OVERLOADS =============================
	// ================================================

	[[nodiscard]] bool operator==(const Color& other) const {
		return rtc::float_equals(r, other.r) && rtc::float_equals(g, other.g) && rtc::float_equals(b, other.b);
	}

	[[nodiscard]] constexpr Color operator+(const Color& other) const {
		return Color(
			r + other.r,
			g + other.g,
			b + other.b
		);
	}

	[[nodiscard]] constexpr Color operator-(const Color& other) const {
		return Color(
			r - other.r,
			g - other.g,
			b - other.b
		);
	}

	[[nodiscard]] constexpr Color operator*(const Color& other) const {
		return Color(
			r * other.r,
			g * other.g,
			b * other.b
		);
	}

	[[nodiscard]] constexpr Color operator*(float scaler) const {
		return Color(
			r * scaler,
			g * scaler,
			b * scaler
		);
	}

};

#endif // !RTC_COLOR_H
