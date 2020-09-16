#include "matrix.h"

#include <iostream>

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/

	Matrix a, b;

	std::cin >> a >> b;

	Matrix c = a * b;

	std::cout << a << std::endl << b << std::endl << c;

	return static_cast<bool>(std::cout);
}