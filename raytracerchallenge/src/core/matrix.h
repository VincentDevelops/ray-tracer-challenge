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

	constexpr Matrix() = default;
	constexpr Matrix(std::size_t s_) :
		rows(s_), columns(s_)
	{
		grid.resize(s_ * s_);
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


};

#endif // !MATRIX_H