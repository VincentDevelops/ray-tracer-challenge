#include "core/matrix.h"
#include "core/tuple.h"

Tuple Matrix::operator*(const Tuple& t) const {
	assert(row_size() == 4 && col_size() == 4);

	return Tuple(
		(*this)(0, 0) * t.x + (*this)(0, 1) * t.y + (*this)(0, 2) * t.z + (*this)(0, 3) * t.w,
		(*this)(1, 0) * t.x + (*this)(1, 1) * t.y + (*this)(1, 2) * t.z + (*this)(1, 3) * t.w,
		(*this)(2, 0) * t.x + (*this)(2, 1) * t.y + (*this)(2, 2) * t.z + (*this)(2, 3) * t.w,
		(*this)(3, 0) * t.x + (*this)(3, 1) * t.y + (*this)(3, 2) * t.z + (*this)(3, 3) * t.w
	);
}

Matrix Matrix::operator*(const Matrix& other) const {
	assert(col_size() == other.row_size());
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