//tuple.h

#ifndef TUPLE_H
#define TUPLE_H

struct Tuple {

private:
	static constexpr float VECTOR	= 0.0f;
	static constexpr float POINT	= 1.0f;
	static constexpr float DEFAULT	= 0.0f;
	static constexpr float EPSILON	= 0.000001f;

public:


	float x;
	float y;
	float z;
	float w;

	// Constructor for a Tuple point at (0,0,0)
	Tuple();

	// Constructor for a Tuple at (x,y,z) and wither point
	//  or vector with w (1 - point / 0 - vector)
	Tuple(float new_x, float new_y, float new_z, float new_w);
	


	// returns true if Tuple is a vector
	bool is_vector() const;

	// returns true if Tuple is a point
	bool is_point() const;



	// ================================================
	// STATIC FUNCTIONS ===============================
	// ================================================

	// returns a point Tuple at coordinates (x,y,z)
	static Tuple point(float new_x, float new_y, float new_z);
	
	// retuns a point Tuple at default coordinates
	static Tuple point();
	
	// returns a vector Tuple with attributes (x,y,z)
	static Tuple vector(float new_x, float new_y, float new_z);
	
	// returns a vector Tuple with default attributes
	static Tuple vector();

	static Tuple normalize(const Tuple& vector);

	// returns the cross product of two vectors
	//  logic error thrown if at least one is not a vector
	static Tuple cross(const Tuple& vector1, const Tuple& vector2);
	
	// returns the magnitude of a vector - vector tuple required
	static float magnitude(const Tuple &vector);

	// returns the dot product of two vectors
	//  logic error thrown if at least one is not a vector
	static float dot(const Tuple& vector1, const Tuple& vector2);
	

	// ================================================
	// OPERATOR OVERLOADS =============================
	// ================================================

	// returns true if this object has equal attributes
	//  to other
	bool operator==(const Tuple& other) const;

	// returns a Tuple with added attributes of calling
	//  Tuple and other could be either vector or point
	Tuple operator+(const Tuple& other) const;
	
	// returns a Tuple with subtracted attributes of calling
	//  Tuple and other, could be either vector or point
	Tuple operator-(const Tuple& other) const;

	// returns a negated tuple
	Tuple operator-() const;

	// returns a scaled vector through multiplication
	Tuple operator*(const float& scaler) const;

	// returns a scaled vector through division
	Tuple operator/(const float& scler) const;

	
};

#endif // !1
