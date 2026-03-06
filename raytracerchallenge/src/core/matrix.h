#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>
#include <cassert>
#include "core/math_utils.h"

struct Tuple;

struct Matrix {

private:
	std::size_t rows = 0;
	std::size_t columns = 0;
	std::vector<float> grid;

public:

	explicit Matrix() = default;

	explicit Matrix(std::size_t s_) :
		rows(s_), columns(s_)
	{
		grid.resize(s_ * s_);
	}

	explicit Matrix(std::size_t r, std::size_t c) :
		rows(r), columns(c) {
		grid.resize(r * c);
	}

	// ================================================
	// GENERAL FUNCTIONS ==============================
	// ================================================


	// returns the size of the vector the matrix
	// is stored in
	[[nodiscard]] std::size_t size() const {
		return rows * columns;
	}

	// returns the number of rows in the matrix
	[[nodiscard]] std::size_t row_size() const {
		return rows;
	}

	// returns the number of columns in the matrix
	[[nodiscard]] std::size_t col_size() const {
		return columns;
	}

	// returns element at a specific coordinate
	[[nodiscard]] float element_at(std::size_t row, std::size_t column) const {
		return grid[row * columns + column];
	}

	// returns the element at element in grid
	// does not account for specific row/column
	[[nodiscard]] float element_at(std::size_t index) const {
		return grid.at(index);
	}

	// returns the determinant of a matrix
	// currently only supports a 2x2 matrix
	// | a b |  determinant = ad - bc
	// | c d |
	[[nodiscard]] float determinant() const;

	// Returns the determinant of the submatrix at (row, col)
	[[nodiscard]] float minor(std::size_t row_, std::size_t col_) const {
		return submatrix(row_, col_).determinant();
	}

	// returns a positive or negative minor depending on included (rol, col) used
	// ex | + - + |
	//    | - = - |  if a coordinate lies in a (-) the minor will be negative
	//	  | + - + |
	[[nodiscard]] float cofactor(std::size_t row_, std::size_t col_) const {
		float m = minor(row_, col_);
		return ((row_ + col_) % 2 == 0) ? m : -m;
	}

	[[nodiscard]] bool is_invertible() const {
		return (determinant() != 0);
	}

	// fills matrix with 1's diagonally from top left to bottom right
	//  all other elements are left with 0.0f
	[[nodiscard]] Matrix identity() const {
		assert(row_size() == col_size());

		Matrix out(row_size(), col_size());
		for (std::size_t diagonal = 0; diagonal < row_size(); diagonal++)
			out(diagonal, diagonal) = 1.0f;

		return out; 
	}

	// returns a new matrix with deleted row and deleted column specified 
	// in calling argument.
	// will always produce a new matrix of size (row - 1) * (col - 1)
	[[nodiscard]] Matrix submatrix(std::size_t d_row, std::size_t d_col) const;

	[[nodiscard]] Matrix inverse() const;

	// ================================================
	// STATIC FUNCTIONS ===============================
	// ================================================

	// Turns the first row into a column, the second row into a second
	// column, and so forth.
	[[nodiscard]] static Matrix transpose(const Matrix matrix);
	
	// Returns a 4x4 translation matrix in the form
	// |1 0 0 x |
	// |0 1 0 y |
	// |0 0 1 z |
	// |0 0 0 1 |
	[[nodiscard]] static Matrix translation(const float x, const float y, const float z);
	
	// when applied to an object centered at origin, it will scale all points on the object
	// to be larger if scale value is more than 1, or smaller if less than 1.
	// Can also reflect a point by scaling the x component by -1
	// Returns a 4x4 matrix in form
	// |x 0 0 0 |
	// |0 y 0 0 |
	// |0 0 z 0 |
	// |0 0 0 1 |
	[[nodiscard]] static Matrix scaling(const float x, const float y, const float z);

	// ================================================
	// OPERATOR OVERLOADS =============================
	// ================================================

	// retrieves true if every value in the matrix at index i
	// is the same between two matricees of the same 
	// row and column size.
	bool operator==(const Matrix& other) const {
		if (row_size() != other.row_size() || col_size() != other.col_size())
			return false;

		for (std::size_t i = 0; i < static_cast<std::size_t>(grid.size()); i++)
			if (!rtc::float_equals(grid.at(i), other.element_at(i)))
				return false;

		return true;
	}

	// allows to modify value at specific (row, column)
	[[nodiscard]] float& operator()(std::size_t row, std::size_t col) {
		return grid[row * columns +col];
	}

	// retrieves value at (row,column)
	[[nodiscard]] const float& operator()(std::size_t row, std::size_t col) const {
		return grid[row * columns + col];
	}

	// Multiplication of two matricies, product of which is returned as a new matrix.
	// Allows for the multiplication of two matricees of any size 
	// so long as the row size of the left matrix is the same value as 
	// the column size of the right matrix.
	[[nodiscard]] Matrix operator*(const Matrix& other) const;

	// returns the product of a Tuple and Matrix, returning a Tuple.
	// This can only be done with a 4x4 matrix.
	[[nodiscard]] Tuple operator*(const Tuple& t) const;

};

#endif // !MATRIX_H