#include "core/matrix.h"
#include "core/tuple.h"

float Matrix::determinant_2x2(const Matrix& matrix) {
    return (matrix(0, 0) * matrix(1, 1)) - (matrix(0, 1) * matrix(1, 0));
}


// ================================================
// STATIC FUNCTIONS ===============================
// ================================================


Matrix Matrix::transpose(const Matrix matrix) {
    Matrix out(matrix.columns, matrix.rows);

    // Block size: tuneable. 16 or 32 are common good defaults for floats
    constexpr std::size_t BLOCK = 32;

    const std::size_t ROWS = matrix.rows;
    const std::size_t COLS = matrix.columns;

    // Blocked transpose for better cache locality on large matrices
    for (std::size_t r0 = 0; r0 < ROWS; r0 += BLOCK) {
        const std::size_t rowMax = std::min(r0 + BLOCK, ROWS);

        for (std::size_t c0 = 0; c0 < COLS; c0 += BLOCK) {
            const std::size_t colMax = std::min(c0 + BLOCK, COLS);

            for (std::size_t row = r0; row < rowMax; ++row) {
                const std::size_t srcBase = row * COLS;

                for (std::size_t col = c0; col < colMax; ++col) {
                    // out(col, row) = matrix(row, col)
                    out.grid[col * out.columns + row] = matrix.grid[srcBase + col];
                }
            }
        }
    }

    return out;
}

float Matrix::determinant() {
    assert(row_size() == col_size());

    switch (row_size()) {
    case 2:
        return determinant_2x2(*this);
    }
}


// ================================================
// OPERATOR OVERLOADS =============================
// ================================================


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