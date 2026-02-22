struct Environment {
	Tuple gravity;
	Tuple wind;

	Environment(Tuple grav, Tuple wnd) {
		gravity = grav;
		wind = wnd;
	}
};

struct Projectile {
	Tuple position;
	Tuple velocity;

	Projectile(Tuple pnt, Tuple vel) {
		position = pnt;
		velocity = vel;
	}

};

void chapter1_projectile();

Projectile tick(Environment env, Projectile proj);

