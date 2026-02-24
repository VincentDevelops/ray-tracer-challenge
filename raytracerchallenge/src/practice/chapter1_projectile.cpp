#include "core/tuple.h"
#include "core/canvas.h"
#include <iostream>
#include "chapter1_projectile.h"


// Chapter 1 Putting It Together
// - a projectile has a position (point) and velocity (vector)
//- an environment has gravity (vector) and wind (vector)
//- tick(environment, projectile) returns a new projectile
//	and represents the giveen projectile after one unit of time
//	passes. unit is arbitrary at this point.


// Chapter 2 putting it together
// use the projectile to draw onto a ppm file


void chapter1_projectile() {
	
	Projectile proj(Tuple::point(0.0f, 1.0f, 0.0f),
		Tuple::normalize(Tuple::vector(0.5f, 1.2f, 0.0f) * 20.25));

	Environment env(Tuple::vector(0.0f, -0.1f, 0.0f), 
		Tuple::vector(-0.01f, 0.0f, 0.0f));

	Canvas canvas(900, 950);
	Color color(1.0, 0.0, 0.0);

	int i = 0;
	float scale = 100.0f;

	while (proj.position.y > 0) {
		proj = tick(env, proj);

		int x = (int)(proj.position.x * scale);
		int y = canvas.height - 1 - (int)(proj.position.y * scale);

		if (x >= 0 && x < canvas.width && y >= 0 && y < canvas.height) {
			canvas.write_pixel(x, y, color);
			canvas.write_pixel(x + 1, y, color);
			canvas.write_pixel(x - 1, y, color);
			canvas.write_pixel(x, y + 1, color);
			canvas.write_pixel(x, y - 1, color);
		}
	}

	canvas.save_ppm("test_1.ppm");

}

Projectile tick(Environment env, Projectile proj) {

	Projectile projectile = proj;
	Environment environment = env;

	projectile.position = proj.position + proj.velocity;
	projectile.velocity = proj.velocity + env.gravity + env.wind;

	return projectile;
}

