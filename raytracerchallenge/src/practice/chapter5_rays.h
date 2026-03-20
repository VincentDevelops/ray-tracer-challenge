#ifndef RAY_CAST
#define RAY_CAST

#include "shapes/sphere.h"
#include "geometry/intersection.h"
#include "geometry/ray.h"
#include "core/matrix.h"
#include "core/tuple.h"
#include "core/canvas.h"
#include <cstddef>

inline void ray_cast() {
	constexpr std::size_t canvas_size = 100;
	constexpr float wall_size = 7.0f;
	constexpr float wall_z = 10.0f;
	
	float pixel_size = wall_size / canvas_size;
	float half = wall_size / 2;

	Canvas canvas(canvas_size, canvas_size);
	Tuple ray_origin = Tuple::point(0.0f, 0.0f, -5.0f);
	Sphere sphere;
	Color red(1.0f, 0.0f, 0.0f);

	for (std::size_t row = 0; row < canvas_size; row++) {
		float world_y = half - (row * pixel_size);

		for (std::size_t col = 0; col < canvas_size; col++) {
			float world_x = -half + (col * pixel_size);
			Tuple wall_point = Tuple::point(world_x, world_y, wall_z);

			Tuple ray_direction = wall_point - ray_origin;
			ray_direction = Tuple::normalize(ray_direction);

			Ray ray(ray_origin, ray_direction);
			std::vector intersections = sphere.intersect(ray);

			if (Intersection::hit(intersections))
				canvas.write_pixel(col, row, red);
		}
	}

	canvas.save_ppm("chapter_5.ppm");

}


#endif // !RAY_CAST
