#ifndef INTERSECTION_H
#define INTERSECTION_H

#include <vector>
#include <initializer_list>
#include <optional>

struct Sphere;


struct Intersection {
	float t;
	const Sphere* object;

	Intersection() = default;

	Intersection(float t_, const Sphere* o_)
		: t(t_), object(o_) {}

	bool operator==(const Intersection& other) const{
		return (t == other.t && object == other.object);
	}

	[[nodiscard]] static std::optional<Intersection> hit(const std::vector<Intersection>& xs)  {
		if (xs.empty())
			return std::nullopt;

		Intersection hold = xs[0];

		for (Intersection i : xs) {
			if (i.t < 0)
				continue;

			if (i.t < hold.t || hold.t < 0)
				hold = i;
		}

		if (hold.t < 0)
			return std::nullopt;

		return hold;
	}
};

#endif // !INTERSECTION_H
