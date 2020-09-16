#include "cuttingMethod.h"

#include <iostream>

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/

	double x0{}, x1{};
	CuttingMethod method([](double x) {return cos(x) - x + 1; });
	std::cout << "Введите начальное приближение: ";
	std::cin >> x0;
	
	std::cout << "Введите второе приближение: ";
	std::cin >> x1;

	std::cout << std::endl;

	std::cout.setf(std::ios::scientific);
	std::cout << "Найденный корень: " << method.computation(x0, x1) << std::endl;

	return static_cast<bool>(std::cout);
}