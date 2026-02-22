#ifndef RTC_COLOR_H
#define RTC_COLOR_H

struct Color {
private:
	static constexpr float BLACK = 0.0f;
	static constexpr float WHITE = 1.0f;

public: 

	float r = 0.0f;
	float g = 0.0f;
	float b = 0.0f;

	Color() = default;
	Color(float r_, float g_, float b_);

	// ================================================
	// OPERATOR OVERLOADS =============================
	// ================================================

	bool operator==(const Color& other) const;

	Color operator+(const Color& other) const;

	Color operator-(const Color& other) const;

	Color operator*(const Color& scaler) const;

	Color operator*(const float& scaler) const;




};

#endif // !RTC_COLOR_H
