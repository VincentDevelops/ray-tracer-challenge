#include "shapes/sphere.h"
#include "geometry/intersection.h"
#include "geometry/ray.h"
#include "core/tuple.h"
#include <vector>


std::vector<Intersection> Sphere::intersect(Ray ray) {
	//edge case -- ray originates from inside spere 


	// the vector from the sphere's center to the ray origin
	Tuple sphere_to_ray_vector = ray.origin - Tuple::point(0.0f, 0.0f, 0.0f);

	float a = Tuple::dot(ray.direction, ray.direction);
	float b = 2.0f * Tuple::dot(ray.direction, sphere_to_ray_vector);
	float c = Tuple::dot(sphere_to_ray_vector, sphere_to_ray_vector) - 1.0f;

	float discriminant = (b * b) - 4.0f * a * c;

	// ray has missed, no interseections have occured between ray and sphere
	if (discriminant < 0)
		return {};

	float t1 = ((-b - std::sqrt(discriminant)) / (2.0f * a));
	float t2 = ((-b + std::sqrt(discriminant)) / (2.0f * a));

	if (t1 > t2)
		return std::vector<Intersection>{Intersection(t2, this), Intersection(t1, this)};
	else
		return std::vector<Intersection>{Intersection(t1, this), Intersection(t2, this) };
}