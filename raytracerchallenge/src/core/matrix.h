#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>
#include <vector>
#include <cassert>

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

	[[nodiscard]] Matrix identity() const {
		assert(row_size() == col_size());

		Matrix out(row_size(), col_size());
		for (int i = 0; i < row_size(); i++)
			out(i, i) = 1.0f;

		return out;
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

	[[nodiscard]] Matrix operator*(const Matrix& other) const;

	[[nodiscard]] Tuple operator*(const Tuple& t) const;

};

#endif // !MATRIX_H