#include "m_use.h"

void first(std::ifstream& ifs)
{
	/*ввод матриц*/
	size_t r{}, c{};
	ifs >> r >> c;
	/*тип - int*/
	Matrix<int> a(r, c);
	ifs >> a;

	ifs >> r >> c;
	Matrix<int> b(r, c);
	ifs >> b;

	std::cout << "Матрица A:" << std::endl << a << std::endl;
	std::cout << "Матрица B:" << std::endl << b << std::endl;

	std::cout << "Сумма матриц: " << std::endl;
	std::cout << a + b << std::endl;
}

void second(std::ifstream& ifs)
{
	/*ввод матриц*/
	size_t r{}, c{};
	ifs >> r >> c;
	/*тип - int*/
	Matrix<int> a(r, c);
	ifs >> a;

	ifs >> r >> c;
	Matrix<int> b(r, c);
	ifs >> b;

	std::cout << "Матрица A:" << std::endl << a << std::endl;
	std::cout << "Матрица B:" << std::endl << b << std::endl;

	std::cout << "Произведение матриц: " << std::endl;
	std::cout << a * b << std::endl;
}
