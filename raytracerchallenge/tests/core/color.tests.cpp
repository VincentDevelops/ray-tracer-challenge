#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "core/color.h"

TEST_CASE("Color(r_, g_, b_) constructor check") {
	Color c(-0.5f, 0.4f, 1.7f);
	REQUIRE(c.r == -0.5f);
	REQUIRE(c.g == 0.4f);
	REQUIRE(c.b == 1.7f);
}

TEST_CASE("Adding Colors") {
	Color c1(0.9f, 0.6f, 0.75f);
	Color c2(0.7f, 0.1f, 0.25f);

	REQUIRE(Color(1.6f, 0.7f, 1.0f) == c1 + c2);
}

TEST_CASE("Subtracting Colors") {
	Color c1(0.9f, 0.6f, 0.75f);
	Color c2(0.7f, 0.1f, 0.25f);

	REQUIRE(Color(0.2f, 0.5f, 0.5f) == c1 - c2);
}

TEST_CASE("Multiplying a color by a scaler") {
	Color c(0.2f, 0.3f, 0.4f);

	REQUIRE(
		Color(0.4f, 0.6f, 0.8f) == c * 2
	);
}

TEST_CASE("Multiplying Colors") {
	Color c1(1.0f, 0.2f, 0.4f);
	Color c2(0.9f, 1.0f, 0.1f);
	Color c3(0.9f, 0.2f, 0.04f);

	REQUIRE(
		 c3 == c1 * c2
	);
}