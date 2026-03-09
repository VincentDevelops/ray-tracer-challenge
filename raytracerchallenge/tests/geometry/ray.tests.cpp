#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "geometry/ray.h"
#include "geometry/intersection.h"
#include "shapes/sphere.h"
#include "core/math_utils.h"

TEST_CASE("Creating and querying a ray", "[ray]") {
	Tuple origin = Tuple::point(1.0f, 2.0f, 3.0f);
	Tuple direction = Tuple::vector(4.0f, 5.0f, 6.0f);
	Ray r(origin, direction);

	REQUIRE(r.origin == origin);
	REQUIRE(r.direction == direction);
}

TEST_CASE("Computing a point from a distace", "[ray]") {
	Ray ray(Tuple::point(2.0f, 3.0f, 4.0f), Tuple::vector(1.0f, 0.0f, 0.0f));
	
	REQUIRE(ray.position(0.0f) == Tuple::point(2.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(1.0f) == Tuple::point(3.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(-1.0f) == Tuple::point(1.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(2.5f) == Tuple::point(4.5f, 3.0f, 4.0f));
}

TEST_CASE("A ray intersects a sphere at two points", "[ray][intersection][sphere]") {
	Ray ray(Tuple::point(0.0f, 0.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<Intersection> xs = sphere.intersect(ray);
	
	REQUIRE(xs.size() == 2);
	REQUIRE(rtc::float_equals(xs[0].t, 4.0f));
	REQUIRE(rtc::float_equals(xs[1].t, 6.0f));

}

TEST_CASE("A ray intersects a sphere at a tangent", "[ray]") {
	Ray ray(Tuple::point(0.0f, 1.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<Intersection> xs = sphere.intersect(ray);

	REQUIRE(xs.size() == 2);
	REQUIRE(rtc::float_equals(xs[0].t, 5.0f));
	REQUIRE(rtc::float_equals(xs[1].t, 5.0f));
}

TEST_CASE("A ray misses a sphere", "[ray][intersection][sphere]") {
	Ray ray(Tuple::point(0.0f, 2.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<Intersection> xs = sphere.intersect(ray);

	REQUIRE(xs.size() == 0);
}

TEST_CASE("A ray originates inside a sphere", "[ray][intersection][sphere]") {
	Ray ray(Tuple::point(0.0f, 0.0f, 0.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<Intersection> xs = sphere.intersect(ray);

	REQUIRE(xs.size() == 2);
	REQUIRE(rtc::float_equals(xs[0].t, -1.0f));
	REQUIRE(rtc::float_equals(xs[1].t, 1.0f));
}

TEST_CASE("A sphere is behind a ray", "[ray][intersection][sphere]") {
	Ray ray(Tuple::point(0.0f, 0.0f, 5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<Intersection> xs = sphere.intersect(ray);

	REQUIRE(xs.size() == 2);
	REQUIRE(rtc::float_equals(xs[0].t, -6.0f));
	REQUIRE(rtc::float_equals(xs[1].t, -4.0f));
} 

TEST_CASE("An intersection encapsulates t and object", "[intersection][sphere]") {
	const Sphere* sphere;
	Intersection intersect(3.5f, sphere);

	REQUIRE(rtc::float_equals(intersect.t, 3.5f));
	REQUIRE(intersect.object == sphere);
}
//
//TEST_CASE("Aggregating intersections", "[intersection][sphere]") {
//	Sphere s;
//	Intersection i1(1.0f, s);
//	Intersection i2(2.0f, s);
//	std::vector<Intersection> xs = Intersection::intersections(i1, i2);
//
//	REQUIRE(xs.size() == 2);
//	REQUIRE(xs[0].t == 1.0f);
//	REQUIRE(xs[1].t == 2.0f);
//}
//
//TEST_CASE("Intersect sets the object on the intersection", "[ray][intersection][sphere]") {
//	Ray ray(Tuple::point(0.0f, 0.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
//	Sphere sphere;
//	std::vector<Intersection> xs = sphere.intersect(ray);
//
//	REQUIRE(xs.size() == 2);
//	REQUIRE(xs[0].object == s);
//	REQUIRE(xs[1].object == s);
//}
//
//TEST_CASE("The hit, when all intersectons have positive t", "[intersection][sphere]") {
//	Sphere sphere;
//	Intersection i1(1.0f, sphere);
//	Intersection i2(2.0f, sphere);
//	std::vector<Intersection> xs = Intersection::intersections(i1, i2);
//
//	Intersection i = Intersection::hit(xs);
//	REQUIRE(i == i1);
//}
//
//TEST_CASE("The hit, when some intersections have negative t", "[intersection][sphere]") {
//	Sphere sphere;
//	Intersection i1(-1.0f, s);
//	Intersection i2(1.0f, s);
//	std::vector<Intersection> xs = Intersection::intersections(i1, i2);
//
//	Intersection i = Intersection::hit(cs);
//	REQUIRE(i == i2);
//}
//
//TEST_CASE("The hit, when all intersections have negative t", "[intersection][sphere]") {
//	Sphere sphere;
//	Intersection i1(-2.0f, s);
//	Intersection i2(-1.0f, s);
//	std::vector<Intersection> xs = Intersection::intersections(i1, i2);
//
//	Intersection i = Intersection::hit(cs);
//	REQUIRE(i == std::nullopt);
//}
//
//TEST_CASE("The hit is always the lowest nonnegative intersection", "[intersection][sphere]") {
//	Sphere sphere;
//	Intersection i1(5.0f, sphere);
//	Intersection i2(7.0f, sphere);
//	Intersection i3(-3.0f, sphere);
//	Intersection i4(2.0f, sphere);
//	std::vector<Intersection> xs = Intersection::intersections(i1, i2, i3, i4);
//	
//	Intersection i = Intersection::hit(xs);
//	REQUIRE(i == i4);
//}
//
//TEST_CASE("Translating a ray", "[ray]") {
//	Ray ray(Tuple::point(1.0f, 2.0f, 3.0f), Tuple::vector(0.0f, 1.0f, 0.0f));
//	Matrix matrix = Matrix::translation(3.0f, 4.0f, 5.0f);
//	Ray ray2 = ray.transform(matrix);
//
//	REQUIRE(ray2.origin == Tuple::point(4.0f, 6.0f, 8.0f));
//	REQUIRE(ray2.direction == Tuple::vector(0.0f, 1.0f, 0.0f));
//}
//
//TEST_CASE("Scaling a  ray", "[ray]") {
//	Ray ray(Tuple::point(1.0f, 2.0f, 3.0f), Tuple::vector(0.0f, 1.0f, 0.0f));
//	Matrix matrix = Matrix::scaling(2.0f, 3.0f, 4.0f);
//	Ray ray2 = ray.transform(matrix);
//
//	REQUIRE(ray2.origin == Tuple::point(2.0f, 6.0f, 12.0f));
//	REQUIRE(ray2.direction == Tuple::vector(0.0f, 3.0f, 0.0f));
//}
//
//TEST_CASE("A sphere's default transformation", "[sphere]") {
//	Sphere sphere;
//	REQUIRE(sphere.transform == Matrix::identity(4));
//}
//
//TEST_CASE("Changing a sphere's transformation", ["sphere"]) {
//	Sphere sphere;
//	Matrix trans = Matrix::translation(2.0f, 3.0f, 4.0f);
//	sphere.set_transform(trans);
//
//	REQUIRE(s.transform == trans);
//}
//
//TEST_CASE("Intersecting a scaled sphere with a ray", "[ray]") {
//	Ray ray(Tuple::point(0.0f, 0.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
//	Sphere sphere;
//	sphere.set_transform(Matrix::scaling(2.0f, 2.0f, 2.0f));
//	std::vector<Intersection> xs = spere.intersect(ray);
//
//	REQUIRE(xs.size() == 2);
//	REQUIRE(rtc::float_equals(xs[0].t, 3.0f));
//	REQUIRE(rtc::float_equals(xs[1].t, 7.0f));
//}
//
//TEST_CASE("Intersecting a translated sphere with a ray", "[ray][sphere]") {
//	Ray ray(Tuple::point(0.0f, 0.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
//	Sphere sphere;
//	sphere.set_transform(Matrix::translation(5.0f, 0.0f, 0.0f));
//	std::vector<Intersection> xs = sphere.intersect(ray);
//
//	REQUIRE(xs.size() == 0);
//}