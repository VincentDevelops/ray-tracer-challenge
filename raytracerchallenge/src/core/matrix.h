#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>
#include <cassert>
#include "tuple.h"

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

	[[nodiscard]] std::size_t size() const {
		return rows * columns;
	}

	[[nodiscard]] std::size_t row_size() const {
		return rows;
	}

	[[nodiscard]] std::size_t col_size() const {
		return columns;
	}

	[[nodiscard]] float element_at(std::size_t row, std::size_t column) const {
		return grid[row * columns + column];
	}

	[[nodiscard]] float element_at(std::size_t index) const {
		return grid.at(index);
	}

	// ================================================
	// OPERATOR OVERLOADS =============================
	// ================================================

	bool operator==(const Matrix& other) const {

		if (size() != other.size())
			return false;

		for (std::size_t i = 0; i < static_cast<std::size_t>(grid.size()); i++)
			if (grid.at(i) != other.element_at(i))
				return false;

		return true;
	}

	float& operator()(std::size_t row, std::size_t col) {
		return grid[row * columns +col];
	}

	const float& operator()(std::size_t row, std::size_t col) const {
		return grid[row * columns + col];
	}

	[[nodiscard]] Matrix operator*(const Matrix& other) const {
		assert(col_size()  == other.row_size());
		Matrix out(row_size(), other.col_size());

		for (std::size_t r = 0; r < rows; ++r) {
			for (std::size_t c = 0; c < other.columns; ++c) {
				float sum = 0.0f;
				for (std::size_t k = 0; k < columns; ++k) {
					sum += (*this)(r, k) * other(k, c);
				}
				out(r, c) = sum;
			}
		}
		return out;
	}

	[[nodiscard]] Tuple operator*(const Tuple& t) const {
		assert(row_size() == 4 && col_size() == 4);

		return Tuple(
			(*this)(0, 0) * t.x + (*this)(0, 1) * t.y + (*this)(0, 2) * t.z + (*this)(0, 3) * t.w,
			(*this)(1, 0) * t.x + (*this)(1, 1) * t.y + (*this)(1, 2) * t.z + (*this)(1, 3) * t.w,
			(*this)(2, 0) * t.x + (*this)(2, 1) * t.y + (*this)(2, 2) * t.z + (*this)(2, 3) * t.w,
			(*this)(3, 0) * t.x + (*this)(3, 1) * t.y + (*this)(3, 2) * t.z + (*this)(3, 3) * t.w
		);
	}

};

#endif // !MATRIX_H