#ifndef SPHERE_H
#define SPHERE_H

#include "core/math_utils.h"
#include "core/matrix.h"

struct Sphere {
private: 
	static int next_id;
	int id;
public:
	Matrix transform = Matrix::identity(4);

};

#endif // !SPHERE_H
