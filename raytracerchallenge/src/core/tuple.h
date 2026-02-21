//tuple.h

#ifndef TUPLE_H
#define TUPLE_H

struct Tuple {

private:
	const int VECTOR	= 0;
	const int POINT		= 1;

public:


	float x;
	float y;
	float z;
	float w;

	Tuple();
	Tuple(float new_x, float new_y, float new_z, float new_w);
	Tuple(bool new_w);

	bool is_vector() const;
	bool is_point() const;

	static Tuple point(float new_x, float new_y, float new_z);
	static Tuple point();
	static Tuple vector(float new_x, float new_y, float new_z);
	static Tuple vector();

	bool operator==(const Tuple& other) const;
	Tuple operator+(const Tuple& other) const;
	Tuple operator-(const Tuple& other) const;
};

#endif // !1
