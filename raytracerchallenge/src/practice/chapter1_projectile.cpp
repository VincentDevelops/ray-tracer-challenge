#include "core/tuple.h"
#include <iostream>

// Chapter 1 Putting It Together
// - a projectile has a position (point) and velocity (vector)
//- an environment has gravity (vector) and wind (vector)
//- tick(environment, projectile) returns a new projectile
//	and represents the giveen projectile after one unit of time
//	passes. unit is arbitrary at this point.


#include "chapter1_projectile.h"

void chapter1_projectile() {
	
	Projectile proj(Tuple::point(0.0f, 1.0f, 0.0f),
		Tuple::normalize(Tuple::vector(1.0f, 1.0f, 0.0f)));

	Environment env(Tuple::vector(0.0f, -0.1f, 0.0f), 
		Tuple::vector(-0.01f, 0.0f, 0.0f));

	int i = 0;
	while (proj.position.y > 0) {
		proj = tick(env, proj);
		std::cout << "run: " << i << std::endl;
		std::cout << "x: ";
		std::cout << proj.position.x << std::endl;

		std::cout << "y: ";
		std::cout << proj.position.y << std::endl;

		std::cout << "z: ";
		std::cout << proj.position.z << std::endl;
		std::cout << "\n" << std::endl;
		i++;

		proj.velocity.x *= 1.5;
		proj.velocity.z *= 1.2;

	}


}

Projectile tick(Environment env, Projectile proj) {

	Projectile projectile = proj;
	Environment environment = env;

	projectile.position = proj.position + proj.velocity;
	projectile.velocity = proj.velocity + env.gravity + env.wind;

	return projectile;
}

