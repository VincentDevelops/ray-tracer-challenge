#include "matrix.h"
#include "matrix.h"
#include "matrix.h"
#include "matrix.h"
#include "matrix.h"
#include "core/matrix.h"
#include "core/tuple.h"

// ================================================
// PRIVATE FUNCTIONS ==============================
// ================================================

// ================================================
// GENERAL FUNCTIONS ==============================
// ================================================

float Matrix::determinant() const {
    assert(row_size() == col_size());

    // Base case
    if (row_size() == 2) {
        return (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
    }

    float det = 0.0f;

    // Expand along first row (row 0)
    for (std::size_t col = 0; col < col_size(); ++col) {
        det += (*this)(0, col) * cofactor(0, col);
    }

    return det;
}

Matrix Matrix::submatrix(std::size_t d_row, std::size_t d_col) const {
    assert(d_row < row_size() && d_col < col_size());

    Matrix out((row_size() - 1), (col_size() - 1));
    std::size_t row = 0;
    std::size_t col = 0;

    for (std::size_t i = 0; i < row_size(); i++) {
        if (i == d_row) {
            continue;
        }

        for (std::size_t j = 0; j < col_size(); j++) {
            if (j == d_col) {
                continue;
            }
            
            out(row, col) = element_at(i, j);

            col++;
        }
        col = 0;
        row++;
    }

    return out;
}

Matrix Matrix::inverse() const
{
    assert(is_invertible());
    assert(row_size() == col_size());

    Matrix out(row_size());
    float cofact = 0.0f;
    float det = determinant();
    

    for (std::size_t row_ = 0; row_ < row_size(); row_++) {
        for (std::size_t col_ = 0; col_ < col_size(); col_++) {
            cofact = cofactor(row_, col_);
            out(col_, row_) = cofact / det;
        }
    }

    return out;
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

Matrix Matrix::translation(const float x, const float y, const float z) {
    Matrix out(4);
    out(0, 0) = 1.0f;
    out(1, 1) = 1.0f;
    out(2, 2) = 1.0f;
    out(3, 3) = 1.0f;

    out(0, 3) = x;
    out(1, 3) = y;
    out(2, 3) = z;

    return out;
}

Matrix Matrix::scaling(const float x, const float y, const float z) {
    Matrix out(4);
    out(0, 0) = x;
    out(1, 1) = y;
    out(2, 2) = z;
    out(3, 3) = 1.0f;

    return out;
}

Matrix Matrix::rotation_x(const float radian)
{
    Matrix out(4);
    out(0, 0) = 1.0f;
    out(1, 1) = std::cos(radian);
    out(1, 2) = -(std::sin(radian));
    out(2, 1) = std::sin(radian);
    out(2, 2) = std::cos(radian);
    out(3, 3) = 1.0f;

    return out;
}

Matrix Matrix::rotation_y(const float radian)
{
    Matrix out(4);
    out(0, 0) = std::cos(radian);
    out(0, 2) = std::sin(radian);
    out(1, 1) = 1.0f;
    out(2, 0) = -(std::sin(radian));
    out(2, 2) = std::cos(radian);
    out(3, 3) = 1.0f;

    return out;
}

Matrix Matrix::rotation_z(const float radian)
{
    Matrix out(4);
    out(0, 0) = std::cos(radian);
    out(0, 1) = -(std::sin(radian));
    out(1, 0) = std::sin(radian);
    out(1, 1) = std::cos(radian);
    out(2, 2) = 1.0f;
    out(3, 3) = 1.0f;

    return out;
}

Matrix Matrix::shearing(const float x_y, const float x_z, const float y_x, const float y_z, const float z_x, const float z_y)
{
    Matrix out(4);
    out(0, 0) = 1.0f;
    out(0, 1) = x_y;
    out(0, 2) = x_z;
    out(1, 0) = y_x;
    out(1, 1) = 1.0f;
    out(1, 2) = y_z;
    out(2, 0) = z_x;
    out(2, 1) = z_y;
    out(2, 2) = 1.0f;
    out(3, 3) = 1.0f;

    return out;
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