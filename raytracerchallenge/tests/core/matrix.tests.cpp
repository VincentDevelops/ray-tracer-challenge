#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "core/matrix.h"

TEST_CASE("Constructing and inspecting a 4x4 matrix") {
	Matrix m(4);
	m(0, 0) = 1.0f;
	m(0, 1) = 2.0f;
	m(0, 2) = 3.0f;
	m(0, 3) = 4.0f;

	m(1, 0) = 5.5f;
	m(1, 1) = 6.5f;
	m(1, 2) = 7.5f;
	m(1, 3) = 8.5f;

	m(2, 0) = 9.0f;
	m(2, 1) = 10.0f;
	m(2, 2) = 11.0f;
	m(2, 3) = 12.0f;

	m(3, 0) = 13.5f;
	m(3, 1) = 14.5f;
	m(3, 2) = 15.5f;
	m(3, 3) = 16.5f;

	REQUIRE(m(0, 0) == 1.0f);
	REQUIRE(m(0, 3) == 4.0f);
	REQUIRE(m(1, 0) == 5.5f);
	REQUIRE(m(1, 2) == 7.5f);
	REQUIRE(m(2, 2) == 11.0f);
	REQUIRE(m(3, 0) == 13.5f);
	REQUIRE(m(3, 2) == 15.5f);

}

TEST_CASE("A 2x2 Matrix ought to be representable") {
	Matrix m(2);
	m(0, 0) = -3.0f;
	m(0, 1) = 5.0f;
	m(1, 0) = 1.0f;
	m(1, 1) = -2.0f;

	REQUIRE(m(0, 0) == -3.0f);
	REQUIRE(m(0, 1) == 5.0f);
	REQUIRE(m(1, 0) == 1.0f);
	REQUIRE(m(1, 1) == -2.0f);
}

TEST_CASE("A 3x3 Matrix ought to be representable") {
	Matrix m(3);
	m(0, 0) = -3.0f;
	m(0, 1) = 5.0f;
	m(0, 2) = 0.0f;
	m(1, 0) = 1.0f;
	m(1, 1) = -2.0f;
	m(2, 1) = -7.0f;
	m(2, 0) = 0.0f;
	m(2, 1) = 1.0f;
	m(2, 2) = 1.0f;

	REQUIRE(m(0, 0) == -3.0f);
	REQUIRE(m(1, 1) == -2.0f);
	REQUIRE(m(2, 2) == 1.0f);
}

TEST_CASE("Matrix Equality with identical matrices") {
	Matrix A(4), B(4);
	A(0, 0) = 1.0f;
	A(0, 1) = 2.0f;
	A(0, 2) = 3.0f;
	A(0, 3) = 4.0f;
	A(1, 0) = 5.0f;
	A(1, 1) = 6.0f;
	A(1, 2) = 7.0f;
	A(1, 3) = 8.0f;
	A(2, 0) = 9.0f;
	A(2, 1) = 8.0f;
	A(2, 2) = 7.0f;
	A(2, 3) = 6.0f;
	A(3, 0) = 5.0f;
	A(3, 1) = 4.0f;
	A(3, 2) = 3.0f;
	A(3, 3) = 2.0f;

	B(0, 0) = 1.0f;
	B(0, 1) = 2.0f;
	B(0, 2) = 3.0f;
	B(0, 3) = 4.0f;
	B(1, 0) = 5.0f;
	B(1, 1) = 6.0f;
	B(1, 2) = 7.0f;
	B(1, 3) = 8.0f;
	B(2, 0) = 9.0f;
	B(2, 1) = 8.0f;
	B(2, 2) = 7.0f;
	B(2, 3) = 6.0f;
	B(3, 0) = 5.0f;
	B(3, 1) = 4.0f;
	B(3, 2) = 3.0f;
	B(3, 3) = 2.0f;
	
	REQUIRE((A == B) == true);
}

TEST_CASE("Matrix equality with different matrices") {
	Matrix A(4), B(4);
	A(0, 0) = 1.0f;
	A(0, 1) = 2.0f;
	A(0, 2) = 1.0f;
	A(0, 3) = 4.0f;

	A(1, 0) = 5.0f;
	A(1, 1) = 6.0f;
	A(1, 2) = 4.0f;
	A(1, 3) = 8.0f;
	
	A(2, 0) = 5.0f;
	A(2, 1) = 8.0f;
	A(2, 2) = 7.0f;
	A(2, 3) = 6.0f;

	A(3, 0) = 4.0f;
	A(3, 1) = 4.0f;
	A(3, 2) = 3.0f;
	A(3, 3) = 2.0f;

	B(0, 0) = 1.0f;
	B(0, 1) = 2.0f;
	B(0, 2) = 3.0f;
	B(0, 3) = 4.0f;

	B(1, 0) = 5.0f;
	B(1, 1) = 6.0f;
	B(1, 2) = 7.0f;
	B(1, 3) = 8.0f;
	
	B(2, 0) = 9.0f;
	B(2, 1) = 8.0f;
	B(2, 2) = 7.0f;
	B(2, 3) = 6.0f;
	
	B(3, 0) = 5.0f;
	B(3, 1) = 4.0f;
	B(3, 2) = 3.0f;
	B(3, 3) = 2.0f;

	REQUIRE((A != B) == true);
}

TEST_CASE("Multiplying two matrices") {
	Matrix A(4), B(4);
	A(0, 0) = 1.0f;
	A(0, 1) = 2.0f;
	A(0, 2) = 3.0f;
	A(0, 3) = 4.0f;

	A(1, 0) = 5.0f;
	A(1, 1) = 6.0f;
	A(1, 2) = 7.0f;
	A(1, 3) = 8.0f;

	A(2, 0) = 9.0f;
	A(2, 1) = 8.0f;
	A(2, 2) = 7.0f;
	A(2, 3) = 6.0f;

	A(3, 0) = 5.0f;
	A(3, 1) = 4.0f;
	A(3, 2) = 3.0f;
	A(3, 3) = 2.0f;

	B(0, 0) = -2.0f;
	B(0, 1) = 1.0f;
	B(0, 2) = 2.0f;
	B(0, 3) = 3.0f;

	B(1, 0) = 3.0f;
	B(1, 1) = 2.0f;
	B(1, 2) = 1.0f;
	B(1, 3) = -1.0f;

	B(2, 0) = 4.0f;
	B(2, 1) = 3.0f;
	B(2, 2) = 6.0f;
	B(2, 3) = 5.0f;

	B(3, 0) = 1.0f;
	B(3, 1) = 2.0f;
	B(3, 2) = 7.0f;
	B(3, 3) = 8.0f;

	Matrix C = A * B;
	REQUIRE(C(0, 0) == 20.0f);
	REQUIRE(C(0, 1) == 22.0f);
	REQUIRE(C(0, 2) == 50.0f);
	REQUIRE(C(0, 3) == 48.0f);
	
	REQUIRE(C(1, 0) == 44.0f);
	REQUIRE(C(1, 1) == 54.0f);
	REQUIRE(C(1, 2) == 114.0f);
	REQUIRE(C(1, 3) == 108.0f);

	REQUIRE(C(2, 0) == 40.0f);
	REQUIRE(C(2, 1) == 58.0f);
	REQUIRE(C(2, 2) == 110.0f);
	REQUIRE(C(2, 3) == 102.0f);

	REQUIRE(C(3, 0) == 16.0f);
	REQUIRE(C(3, 1) == 26.0f);
	REQUIRE(C(3, 2) == 46.0f);
	REQUIRE(C(3, 3) == 42.0f);

}

TEST_CASE("A matrix multiplied by a Tuple") {
	Matrix A(4);
	Tuple b(1, 2, 3, 1);

	A(0, 0) = 1.0f;
	A(0, 1) = 2.0f;
	A(0, 2) = 3.0f;
	A(0, 3) = 4.0f;

	A(1, 0) = 2.0f;
	A(1, 1) = 4.0f;
	A(1, 2) = 4.0f;
	A(1, 3) = 2.0f;

	A(2, 0) = 8.0f;
	A(2, 1) = 6.0f;
	A(2, 2) = 4.0f;
	A(2, 3) = 1.0f;

	A(3, 0) = 0.0f;
	A(3, 1) = 0.0f;
	A(3, 2) = 0.0f;
	A(3, 3) = 1.0f;

	REQUIRE((A * b) == Tuple(18, 24, 33, 1));
}
//
//TEST_CASE("Multiplying a matrix by the identiy matrix") {
//	Matrix A(4);
//	A(0, 0) = 1.0f;
//	A(0, 1) = 2.0f;
//	A(0, 2) = 3.0f;
//	A(0, 3) = 4.0f;
//
//	A(1, 0) = 5.0f;
//	A(1, 1) = 6.0f;
//	A(1, 2) = 7.0f;
//	A(1, 3) = 8.0f;
//
//	A(2, 0) = 9.0f;
//	A(2, 1) = 8.0f;
//	A(2, 2) = 7.0f;
//	A(2, 3) = 6.0f;
//
//	A(3, 0) = 5.0f;
//	A(3, 1) = 4.0f;
//	A(3, 2) = 3.0f;
//	A(3, 3) = 2.0f;
//
//	REQUIRE(A * A.identity_matrix() == A);
//}
//
//TEST_CASE("Multiplying the identiy matrix by a tuple") {
//	Matrix A(4);
//	Tuple tuple(1, 2, 3, 4);
//	A(0, 0) = 1.0f;
//	A(0, 1) = 2.0f;
//	A(0, 2) = 3.0f;
//	A(0, 3) = 4.0f;
//
//	A(1, 0) = 5.0f;
//	A(1, 1) = 6.0f;
//	A(1, 2) = 7.0f;
//	A(1, 3) = 8.0f;
//
//	A(2, 0) = 9.0f;
//	A(2, 1) = 8.0f;
//	A(2, 2) = 7.0f;
//	A(2, 3) = 6.0f;
//
//	A(3, 0) = 5.0f;
//	A(3, 1) = 4.0f;
//	A(3, 2) = 3.0f;
//	A(3, 3) = 2.0f;
//
//	REQUIRE(A.identiy_matrix() * tuple == tuple);
//}
//
//TEST_CASE("Transposing a matrix") {
//	Matrix A(4);
//	A(0, 0) = 0.0f;
//	A(0, 1) = 9.0f;
//	A(0, 2) = 3.0f;
//	A(0, 3) = 0.0f;
//
//	A(1, 0) = 9.0f;
//	A(1, 1) = 8.0f;
//	A(1, 2) = 0.0f;
//	A(1, 3) = 8.0f;
//
//	A(2, 0) = 1.0f;
//	A(2, 1) = 8.0f;
//	A(2, 2) = 5.0f;
//	A(2, 3) = 3.0f;
//
//	A(3, 0) = 0.0f;
//	A(3, 1) = 0.0f;
//	A(3, 2) = 5.0f;
//	A(3, 3) = 8.0f;
//
//	Matrix C = Matrix::transpose(A);
//	REQUIRE(C(0, 0) == 0.0f);
//	REQUIRE(C(0, 1) == 9.0f);
//	REQUIRE(C(0, 2) == 1.0f);
//	REQUIRE(C(0, 3) == 0.0f);
//
//	REQUIRE(C(1, 0) == 9.0f);
//	REQUIRE(C(1, 1) == 8.0f);
//	REQUIRE(C(1, 2) == 8.0f);
//	REQUIRE(C(1, 3) == 0.0f);
//
//	REQUIRE(C(2, 0) == 3.0f);
//	REQUIRE(C(2, 1) == 0.0f);
//	REQUIRE(C(2, 2) == 5.0f);
//	REQUIRE(C(2, 3) == 5.0f);
//
//	REQUIRE(C(3, 0) == 0.0f);
//	REQUIRE(C(3, 1) == 8.0f);
//	REQUIRE(C(3, 2) == 3.0f);
//	REQUIRE(C(3, 3) == 8.0f);
//}
//
////TEST_CASE("Transposing the identity matrix") {
////
////}
//
//TEST_CASE("Calculating the determinant of a 2x2 matrix") {
//	Matrix A(2);
//	A(0, 0) = 1.0f;
//	A(0, 1) = 5.0f;
//	A(1, 0) = -3.0f;
//	A(1, 1) = 2.0f;
//
//	REQUIRE(Matrix::determinant(A) == 17.0f);
//}
//
//TEST_CASE("A submatrix of 3x3 matrix is a 2x2 matrix") {
//	Matrix A(3);
//	A(0, 0) = 1.0f;
//	A(0, 1) = 5.0f;
//	A(0, 2) = 0.0f;
//
//	A(1, 0) = -3.0f;
//	A(1, 1) = 2.0f;
//	A(1, 2) = 7.0f;
//	
//	A(2, 0) = 0.0f;
//	A(2, 1) = 6.0f;
//	A(2, 2) = -3.0f;
//
//	Matrix B = Matrix::submatrix(A, 0, 2);
//	REQUIRE(B(0, 0) == -3.0f);
//	REQUIRE(B(0, 1) == 2.0f);
//	REQUIRE(B(1, 0) == 0.0f);
//	REQUIRE(B(1, 1) == 6.0f);
//}
//
//TEST_CASE("A submatrix of a 4x4 matrix is a 3x3 matrix") {
//	Matrix A(4);
//	A(0, 0) = -6.0f;
//	A(0, 1) = 1.0f;
//	A(0, 2) = 1.0f;
//	A(0, 3) = 6.0f;
//
//	A(1, 0) = -8.0f;
//	A(1, 1) = 5.0f;
//	A(1, 2) = 8.0f;
//	A(1, 3) = 6.0f;
//
//	A(2, 0) = -1.0f;
//	A(2, 1) = 0.0f;
//	A(2, 2) = 8.0f;
//	A(2, 3) = 2.0f;
//
//	A(3, 0) = -7.0f;
//	A(3, 1) = 1.0f;
//	A(3, 2) = -1.0f;
//	A(3, 3) = 1.0f;
//
//	Matrix B = Matrix::submatrix(A, 2, 1);
//	REQUIRE(B(0, 0) == -6.0f);
//	REQUIRE(B(0, 1) == 1.0f);
//	REQUIRE(B(0, 2) == 6.0f);
//
//	REQUIRE(B(1, 0) == -8.0);
//	REQUIRE(B(1, 1) == 8.0f);
//	REQUIRE(B(1, 2) == 6.0f);
//
//	REQUIRE(B(2, 0) == -7.0f);
//	REQUIRE(B(2, 1) == -1.0f);
//	REQUIRE(B(2, 2) == 1.0f);
//}
//
//TEST_CASE("Calculating a minor of a 3x3 matrix") {
//	Matrix A(3);
//	A(0, 0) = 3.0f;
//	A(0, 1) = 5.0f;
//	A(0, 2) = 0.0f;
//
//	A(1, 0) = 2.0f;
//	A(1, 1) = -1.0f;
//	A(1, 2) = -7.0f;
//
//	A(2, 0) = 6.0f;
//	A(2, 1) = -1.0f;
//	A(2, 2) = 5.0f;
//
//	Matrix B = Matrix::submatrix(A, 1, 0);
//
//	REQUIRE(Matrix::determinant(B) == 25);
//	REQUIRE(Matrix::minor(A, 1, 0) == 25);
//}
//
//TEST_CASE("Calculating a cofacctor of a 3x3 matrix") {
//	Matrix A(3);
//	A(0, 0) = 3.0f;
//	A(0, 1) = 5.0f;
//	A(0, 2) = 0.0f;
//
//	A(1, 0) = 2.0f;
//	A(1, 1) = -1.0f;
//	A(1, 2) = -7.0f;
//
//	A(2, 0) = 6.0f;
//	A(2, 1) = -1.0f;
//	A(2, 2) = 5.0f;
//
//	REQUIRE(Matrix::minor(A, 0, 0)		== -12.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 0)	== -12.0f);
//	REQUIRE(Matrix::minor(A, 1, 0)		== 25.0f);
//	REQUIRE(Matrix::cofactor(A, 1, 0)	== -25.0f);
//}
//
//TEST_CASE("Calculating a determinant of a 3x3 matrix") {
//	Matrix A(3);
//	A(0, 0) = 1.0f;
//	A(0, 1) = 2.0f;
//	A(0, 2) = 6.0f;
//
//	A(1, 0) = -5.0f;
//	A(1, 1) = 8.0f;
//	A(1, 2) = -4.0f;
//
//	A(2, 0) = 2.0f;
//	A(2, 1) = 6.0f;
//	A(2, 2) = 4.0f;
//
//	REQUIRE(Matrix::cofactor(A, 0, 0) == 56.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 1) == 12.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 2) == -46.0f);
//	REQUIRE(Matrix::determinant(A) == -196.0f);
//}
//
//TEST_CASE("Calculating the determinant of a 4x4 matrix") {
//	Matrix A(4);
//	A(0, 0) = -2.0f;
//	A(0, 1) = -8.0f;
//	A(0, 2) = 3.0f;
//	A(0, 3) = 5.0f;
//
//	A(1, 0) = -3.0f;
//	A(1, 1) = 1.0f;
//	A(1, 2) = 7.0f;
//	A(1, 3) = 3.0f;
//
//	A(2, 0) = 1.0f;
//	A(2, 1) = 2.0f;
//	A(2, 2) = -9.0f;
//	A(2, 3) = 6.0f;
//
//	A(3, 0) = -6.0f;
//	A(3, 1) = 7.0f;
//	A(3, 2) = 7.0f;
//	A(3, 3) = -9.0f;
//
//	REQUIRE(Matrix::cofactor(A, 0, 0) == 690.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 1) == 447.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 2) == 210.0f);
//	REQUIRE(Matrix::cofactor(A, 0, 3) == 51.0f);
//	REQUIRE(Matrix::determinant(A) == -4071.0f);
//}
//
//TEST_CASE("Testing an invertible matrix for invertibility") {
//	Matrix A(4);
//	A(0, 0) = 6.0f;
//	A(0, 1) = 4.0f;
//	A(0, 2) = 4.0f;
//	A(0, 3) = 4.0f;
//
//	A(1, 0) = 5.0f;
//	A(1, 1) = 5.0f;
//	A(1, 2) = 7.0f;
//	A(1, 3) = 6.0f;
//
//	A(2, 0) = 4.0f;
//	A(2, 1) = -9.0f;
//	A(2, 2) = 3.0f;
//	A(2, 3) = -7.0f;
//
//	A(3, 0) = 9.0f;
//	A(3, 1) = 1.0f;
//	A(3, 2) = 7.0f;
//	A(3, 3) = -6.0f;
//
//	REQUIRE(Matrix::determinant(A) = -2120.0f);
//	REQUIRE(A.is_invertible() == true);
//}
//
//TEST_CASE("Testing a noninvertible matrix for invertibility") {
//	Matrix A(4);
//	A(0, 0) = -4.0f;
//	A(0, 1) = 2.0f;
//	A(0, 2) = -2.0f;
//	A(0, 3) = -3.0f;
//
//	A(1, 0) = 9.0f;
//	A(1, 1) = 6.0f;
//	A(1, 2) = 2.0f;
//	A(1, 3) = 6.0f;
//
//	A(2, 0) = 0.0f;
//	A(2, 1) = -5.0f;
//	A(2, 2) = 1.0f;
//	A(2, 3) = -5.0f;
//
//	A(3, 0) = 0.0f;
//	A(3, 1) = 0.0f;
//	A(3, 2) = 0.0f;
//	A(3, 3) = 0.0f;
//
//	REQUIRE(Matrix::determinant(A) == 0);
//	REQUIRE(A.is_invertible() == false);
//}
//
//TEST_CASE("Calculating the inverse of a matrix") {
//	Matrix A(4);
//	A(0, 0) = -5.0f;
//	A(0, 1) = 2.0f;
//	A(0, 2) = 6.0f;
//	A(0, 3) = -8.0f;
//
//	A(1, 0) = 1.0f;
//	A(1, 1) = -5.0f;
//	A(1, 2) = 1.0f;
//	A(1, 3) = 8.0f;
//
//	A(2, 0) = 7.0f;
//	A(2, 1) = 7.0f;
//	A(2, 2) = -6.0f;
//	A(2, 3) = -7.0f;
//
//	A(3, 0) = 1.0f;
//	A(3, 1) = -3.0f;
//	A(3, 2) = 7.0f;
//	A(3, 3) = 4.0f;
//
//	Matrix B = Matrix::inverse(A);
//
//	REQUIRE(Matrix::determinant(A) == 532);
//	REQUIRE(Matrix::cofactor(A, 2, 3) == -160);
//	REQUIRE(B(3, 2) == (-160 / 532));
//	REQUIRE(Matrix::cofactor(A, 3, 2) == 105);
//	REQUIRE(B(2, 3) == (105 / 532));
//
//	REQUIRE(B(0, 0) == 0.21805f);
//	REQUIRE(B(0, 1) == 0.45113f);
//	REQUIRE(B(0, 2) == 0.24060f);
//	REQUIRE(B(0, 3) == -0.04511f);
//	
//	REQUIRE(B(1, 0) == -0.80827f);
//	REQUIRE(B(1, 1) == -1.45677f);
//	REQUIRE(B(1, 2) == -0.44361f);
//	REQUIRE(B(1, 3) == 0.52068f);
//
//	REQUIRE(B(2, 0) == -0.07895f);
//	REQUIRE(B(2, 1) == -0.22368f);
//	REQUIRE(B(2, 2) == -0.05263f);
//	REQUIRE(B(2, 3) == 0.19737f);
//
//	REQUIRE(B(3, 0) == -0.52256f);
//	REQUIRE(B(3, 1) == -0.81391f);
//	REQUIRE(B(3, 2) == -0.30075f);
//	REQUIRE(B(3, 3) == 0.30639f);
//}
//
//TEST_CASE("Calculating the inverse of another matrix") {
//	Matrix A(4);
//	A(0, 0) = 8.0f;
//	A(0, 1) = -5.0f;
//	A(0, 2) = 9.0f;
//	A(0, 3) = 2.0f;
//
//	A(1, 0) = 7.0f;
//	A(1, 1) = 5.0f;
//	A(1, 2) = 6.0f;
//	A(1, 3) = 1.0f;
//
//	A(2, 0) = -6.0f;
//	A(2, 1) = 0.0f;
//	A(2, 2) = 9.0f;
//	A(2, 3) = 6.0f;
//
//	A(3, 0) = -3.0f;
//	A(3, 1) = 0.0f;
//	A(3, 2) = -9.0f;
//	A(3, 3) = -4.0f;
//
//	Matrix B = Matrix::inverse(A);
//	REQUIRE(B(0, 0) == -0.15385f);
//	REQUIRE(B(0, 1) == -0.15385f);
//	REQUIRE(B(0, 2) == -0.28205f);
//	REQUIRE(B(0, 3) == -0.53846f);
//
//	REQUIRE(B(1, 0) == -0.07692f);
//	REQUIRE(B(1, 1) == 0.12308f);
//	REQUIRE(B(1, 2) == 0.02564f);
//	REQUIRE(B(1, 3) == 0.03077f);
//
//	REQUIRE(B(2, 0) == 0.35897f);
//	REQUIRE(B(2, 1) == 0.35897f);
//	REQUIRE(B(2, 2) == 0.43590f);
//	REQUIRE(B(2, 3) == 0.92308f);
//
//	REQUIRE(B(3, 0) == -0.69231f);
//	REQUIRE(B(3, 1) == -0.69231f);
//	REQUIRE(B(3, 2) == -0.76923f);
//	REQUIRE(B(3, 3) == -1.92308f);
//}
//
//TEST_CASE("Calculating the inverse of a third matrix") {
//	Matrix A(4);
//	A(0, 0) = 9.0f;
//	A(0, 1) = 3.0f;
//	A(0, 2) = 0.0f;
//	A(0, 3) = 9.0f;
//
//	A(1, 0) = -5.0f;
//	A(1, 1) = -2.0f;
//	A(1, 2) = -6.0f;
//	A(1, 3) = -3.0f;
//
//	A(2, 0) = -4.0f;
//	A(2, 1) = 9.0f;
//	A(2, 2) = 6.0f;
//	A(2, 3) = 4.0f;
//
//	A(3, 0) = -7.0f;
//	A(3, 1) = 6.0f;
//	A(3, 2) = 6.0f;
//	A(3, 3) = 2.0f;
//
//	Matrix B = Matrix::inverse(A);
//	REQUIRE(B(0, 0) == -0.04074f);
//	REQUIRE(B(0, 1) == -0.07778f);
//	REQUIRE(B(0, 2) == 0.14444f);
//	REQUIRE(B(0, 3) == -0.22222f);
//
//	REQUIRE(B(1, 0) == -0.07778f);
//	REQUIRE(B(1, 1) == 0.03333f);
//	REQUIRE(B(1, 2) == 0.36667f);
//	REQUIRE(B(1, 3) == -0.33333f);
//
//	REQUIRE(B(2, 0) == -0.02901f);
//	REQUIRE(B(2, 1) == -0.14630f);
//	REQUIRE(B(2, 2) == -0.10926f);
//	REQUIRE(B(2, 3) == 0.12963f);
//
//	REQUIRE(B(3, 0) == 0.17778f);
//	REQUIRE(B(3, 1) == 0.06667f);
//	REQUIRE(B(3, 2) == -0.26667f);
//	REQUIRE(B(3, 3) == 0.33333f);
//}
//
//TEST_CASE("Multiplying a product by its inverse") {
//	Matrix A(4);
//	A(0, 0) = 3.0f;
//	A(0, 1) = -9.0f;
//	A(0, 2) = 7.0f;
//	A(0, 3) = 3.0f;
//
//	A(1, 0) = 3.0f;
//	A(1, 1) = -8.0f;
//	A(1, 2) = 2.0f;
//	A(1, 3) = -9.0f;
//
//	A(2, 0) = -4.0f;
//	A(2, 1) = 4.0f;
//	A(2, 2) = 4.0f;
//	A(2, 3) = 1.0f;
//
//	A(3, 0) = -6.0f;
//	A(3, 1) = 5.0f;
//	A(3, 2) = -1.0f;
//	A(3, 3) = 1.0f;
//
//	Matrix B(4);
//	B(0, 0) = 8.0f;
//	B(0, 1) = 2.0f;
//	B(0, 2) = 2.0f;
//	B(0, 3) = 2.0f;
//
//	B(1, 0) = 3.0f;
//	B(1, 1) = -1.0f;
//	B(1, 2) = 7.0f;
//	B(1, 3) = 0.0f;
//
//	B(2, 0) = 7.0f;
//	B(2, 1) = 0.0f;
//	B(2, 2) = 5.0f;
//	B(2, 3) = 4.0f;
//
//	B(3, 0) = 6.0f;
//	B(3, 1) = -2.0f;
//	B(3, 2) = 0.0f;
//	B(3, 3) = 5.0f;
//
//	Matrix C = A * B;
//	
//	REQUIRE((C * Matrix::inverse(B)) == A);
//}