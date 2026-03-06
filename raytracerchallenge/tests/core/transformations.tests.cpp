#include <catch2/catch_test_macros.hpp>
#include "core/matrix.h"
#include "core/tuple.h"

//TEST_CASE("Multiplying by a translation matrix") {
//	Matrix transform = translation(5, -3, 2);
//	Tuple p = Tuple::point(-3, 4, 5);
//
//	REQUIRE((transform * p) == Tuple::point(2, 1, 7));
//}
//
//TEST_CASE("Multiplying by the inverse of a translation matrix") {
//	Matrix transform = translation(5.0f, -3.0f, 2.0f);
//	Matrix inv = transform.inverse();
//	Tuple p = Tuple::point(-3.0f, 4.0f, 5.0f);
//
//	REQUIRE((inv * p) == Tuple::point(-8.0f, 7.0f, 3.0f));
//}
//
//TEST_CASE("Translation does not affect vectors") {
//	Matrix transform = translation(5.0f, -3.0f, 2.0f);
//	Tuple v = Tuple::vector(-3.0f, 4.0f, 5.0f);
//
//	REQUIRE(transform * v == v);
//}
//
//TEST_CASE("A scaling matrix applied to a point") {
//	Matrix transform = scaling(2.0f, 3.0f, 4.0f);
//	Tuple p = Tuple::point(-4.0f, 6.0f, 8.0f);
//
//	REQUIRE((transform * p) == Tuple::point(-8.0f, 18.0f, 32.0f));
//}
//
//TEST_CASE("A scaling matrix applied to a vector") {
//	Matrix transform = scaling(2.0f, 3.0f, 4.0f);
//	Tuple v = Tuple::vector(-4.0f, 6.0f, 8.0f);
//
//	REQUIRE((transform * v) == Tuple::vector(-8.0f, 18.0f, 32.0f));
//}
//
//TEST_CASE("Multiplying by the inverse of a scaling matrix") {
//	Matrix transform = scaling(2.0f, 3.0f, 4.0f);
//	Matrix inv = transform.inverse();
//	Tuple v = Tuple::vector(-4.0f, 6.0f, 8.0f);
//
//	REQUIRE((inv * v) == Tuple::vector(-2.0f, 2.0f, 2.0f));
//}
//
//TEST_CASE("Reflection is scaling by a negative value") {
//	Matrix transform = scaling(-1.0f, 1.0f, 1.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(-2.0f, 3.0f, 4.0f));
//}
//
//TEST_CASE("Rotating a point around the x axis") {
//	Tuple p = Tuple::point(0.0f, 1.0f, 0.0f);
//	Matrix half_quarter = Matrix::rotation_x(rtc::PI / 4.0f);
//	Matrix full_quarter = Matrix::rotation_x(rtc::PI / 2.0f);
//
//	REQUIRE((half_quarter * p) == Tuple::point(0.0f, std::sqrtf(2.0f) / 2.0f, std::sqrtf(2.0f) / 2.0f));
//	REQUIRE((full_quarter * p) == Tuple::point(0.0f, 0.0f, 1.0f));
//}
//
//TEST_CASE("The inverse of an x-rotation rotates in the opposite direction") {
//	Tuple p = Tuple::point(0.0f, 1.0f, 0.0f);
//	Matrix half_quarter = Matrix::rotation_x(rtc::PI / 4.0f);
//	Matrix inv = half_quarter.inverse();
//
//	REQUIRE((inv * p) == Tuple::point(0.0f, std::sqrtf(2.0f) / 2.0f, -sqrtf(2.0f) / 2.0f);
//}
//
//TEST_CASE("Rotating a point around the y axis") {
//	Tuple p = Tuple::point(0.0f, 0.0f, 1.0f);
//	Matrix half_quarter = Matrix::rotation_y(rtc::PI / 4.0f);
//	Matrix full_quarter = Matrix::rotation_y(rtc::PI / 2.0f);
//
//	REQUIRE((half_quarter * p) == Tuple::point(std::sqrtf(2.0f) / 2.0f, 0.0f, std::sqrtf(2.0f) / 2.0f));
//	REQUIRE((full_quarter * p) == Tuple::point(1.0f, 0.0f, 0.0f));
//}
//
//TEST_CASE("Rotating a point around the z-axis") {
//	Tuple p = Tuple::point(0.0f, 1.0f, 0.0f);
//	Matrix half_quarter = Matrix::rotation_z(rtc::PI / 4.0f);
//	Matrix full_quarter = Matrix::rotation_z(rtc::PI / 2.0f);
//
//	REQUIRE((half_quarter * p) == Tuple::point(-std::sqrtf(2.0f) / 2.0f, std::sqrtf(2.0f) / 2.0f, 0.0f)));
//	REQUIRE((full_quarter * p) == Tuple::point(-1.0f, 0.0f, 0.0f));
//}
//
//TEST_CASE("A shearing transformation moves x in proportion to y") {
//	Matrix transform = Matrix::shearing(1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(5.0f, 3.0f, 4.0f));
//}
//
//TEST_CASE("A shearing transformation moves x in proportion to Z") {
//	Matrix transform = Matrix::shearing(0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(6.0f, 3.0f, 4.0f));
//}
//
//TEST_CASE("A shearing transformation moves y in proportion to x") {
//	Matrix transform = Matrix::shearing(0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(2.0f, 5.0f, 4.0f));
//}
//
//TEST_CASE("A shearing transformation moves y in proportion to z") {
//	Matrix transform = Matrix::shearing(0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(2.0f, 7.0f, 4.0f));
//}
//
//TEST_CASE("A shearing transformation moves z in proportion to x") {
//	Matrix transform = Matrix::shearing(0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(2.0f, 3.0f, 6.0f));
//}
//
//TEST_CASE("A shearing transformation moves z in proportion to y") {
//	Matrix transform = Matrix::shearing(0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f);
//	Tuple p = Tuple::point(2.0f, 3.0f, 4.0f);
//
//	REQUIRE((transform * p) == Tuple::point(2.0f, 3.0f, 7.0f));
//}
//
//TEST_CASE("Individual transformations are applied in sequence") {
//	Tuple p = Tuple::point(1.0f, 0.0f, 1.0f);
//	Matrix A = Matrix::rotation_x(rtc::PI / 2.0f);
//	Matrix B = Matrix::scaling(5.0f, 5.0f, 5.0f);
//	Matrix C = Matrix::translation(10.0f, 5.0f, 7.0f);
//
//	Tuple p2 = A * p;
//	REQUIRE(p2 == Tuple::point(1.0f, -1.0f, 0.0f));
//	
//	Tuple p3 = B * p2;
//	REQUIRE(p3 == Tuple::point(5.0f, -5.0f, 0.0f));
//
//	Tuple p4 = C * p3;
//	REQUIRE(p4 == Tuple::point(15.0f, 0.0f, 7.0f));
//}
//
//TEST_CASE("Chained transformations must be applied in reverse order") {
//	Tuple p = Tuple::point(1.0f, 0.0f, 1.0f);
//	Matrix A = Matrix::rotation_x(rtc::PI / 2.0f);
//	Matrix B = Matrix::scaling(5.0f, 5.0f, 5.0f);
//	Matrix C = Matrix::translation(10.0f, 5.0f, 7.0f);
//
//	Matrix T = C * B * A;
//	REQUIRE((T * p) == Tuple::point(15.0f, 0.0f, 7.0f));
//}