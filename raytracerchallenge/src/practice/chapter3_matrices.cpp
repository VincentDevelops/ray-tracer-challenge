#include <iostream>
#include "chapter3_matrices.h"

void invert_identity() {
	Matrix A(4);
	A(0, 0) = 3.0f;
	A(0, 1) = -9.0f;
	A(0, 2) = 7.0f;
	A(0, 3) = 3.0f;

	A(1, 0) = 3.0f;
	A(1, 1) = -8.0f;
	A(1, 2) = 2.0f;
	A(1, 3) = -9.0f;

	A(2, 0) = -4.0f;
	A(2, 1) = 4.0f;
	A(2, 2) = 4.0f;
	A(2, 3) = 1.0f;

	A(3, 0) = -6.0f;
	A(3, 1) = 5.0f;
	A(3, 2) = -1.0f;
	A(3, 3) = 1.0f;

	std::cout << "prior to inversion\n";
	print_matrix(A);
	std::cout << "\n";

	std::cout << "post inversion\n";
	Matrix B = A.identity().inverse();
	print_matrix(B);
	std::cout << "\n";


	Matrix C = A * A.inverse();
	std::cout << "multiplying original matrix by its inverse\n";
	print_matrix(C);
	std::cout << "\n";



}

void print_matrix(const Matrix& m)
{
	for (std::size_t r = 0; r < m.row_size(); r++)
	{
		std::cout << "| ";

		for (std::size_t c = 0; c < m.col_size(); c++)
		{
			float v = m(r, c);

			if (v >= 0) std::cout << " ";
			if (v > -10 && v < 10) std::cout << " ";

			std::cout << v << " ";
		}

		std::cout << "|\n";
	}
}