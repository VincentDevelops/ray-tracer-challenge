#include <catch2/catch_test_macros.hpp>
#include <vector>
#include "geometry/ray.h"
#include "geometry/intersection.h"
#include "shapes/sphere.h"

TEST_CASE("Creating and querying a ray") {
	Tuple origin = Tuple::point(1.0f, 2.0f, 3.0f);
	Tuple direction = Tuple::vector(4.0f, 5.0f, 6.0f);
	Ray r(origin, direction);

	REQUIRE(r.origin == origin);
	REQUIRE(r.direction == direction);
}

TEST_CASE("Computing a point from a distace") {
	Ray ray(Tuple::point(2.0f, 3.0f, 4.0f), Tuple::vector(1.0f, 0.0f, 0.0f));
	
	REQUIRE(ray.position(0.0f) == Tuple::point(2.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(1.0f) == Tuple::point(2.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(-1.0f) == Tuple::point(1.0f, 3.0f, 4.0f));
	REQUIRE(ray.position(2.0f) == Tuple::point(4.5f, 3.0f, 4.0f));

}

TEST_CASE("A ray intersects a sphere at two points") {
	Ray ray(Tuple::point(0.0f, 0.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<float> xs = sphere.intersect(ray);
	
	REQUIRE(xs.size() == 2);
	REQUIRE(xs[0] == 5.0f);
	REQUIRE(xs[1] == 5.0f);

}

TEST_CASE("A ray misses a sphere") {
	Ray ray(Tuple::point(0.0f, 2.0f, -5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<float> xs = sphere.intersects(ray);

	REQUIRE(xs.size() == 0);
}

TEST_CASE("A ray originates inside a sphere") {
	Ray ray(Tuple::point(0.0f, 0.0f, 0.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<float> xs = sphere.intersects(ray);

	REQUIRE(xs.size() == 2);
	REQUIRE(xs[0] == -1.0f);
	REQUIRE(xs[1] == 1.0f);
}

TEST_CASE("A sphere is behind a ray") {
	Ray ray(Tuple::point(0.0f, 0.0f, 5.0f), Tuple::vector(0.0f, 0.0f, 1.0f));
	Sphere sphere;
	std::vector<float> xs = sphere.intersects(ray);

	REQUIRE(xs.size() == 2);
	REQUIRE(xs[0] == -6.0f);
	REQUIRE(xs[1] == -4.0f);
}

TEST_CASE("An intersection encapsulates t and object") {
	Sphere s;
	Intersection i(3.5f, s);

	REQUIRE(i.t = 3.5f);
	REQUIRE(i.object == s);
}

TEST_CASE("Aggregating intersections") {
	Sphere s;
	Intersection i1(1.0f, s);
	Intersection i2(2.0f, s);
	std::vector<Intersection> xs = Intersection::intersections(i1, i2);

	REQUIRE(xs.size() == 2);
	REQUIRE(xs[0].t == 1.0f);
	REQUIRE(xs[1].t == 2.0f);
}