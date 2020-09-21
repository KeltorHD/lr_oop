#include "matrixMas.h"

#include <iostream>

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/

	int length{};

	/*Ввод кол-ва элементов*/
	std::cout << "Введите кол-во элементов: ";
	while (length <= 0)
	{
		std::cin >> length;
		if (length <= 0)
		{
			std::cout << "Ошибка, число неположительно, введите еще раз: ";
		}
	}

	MatrixMas mtrxMas{static_cast<size_t>(length)};

	std::cout << "Вычисление суммы всех элементов массива: " << std::endl;
	std::cout << mtrxMas.calculateFirst();

	std::cout << "Из элемента с наибольшим определителем вычесть произведение всех матриц, умноженное на этот определитель: " << std::endl;
	std::cout << mtrxMas.calculateSecond();

	return static_cast<bool>(std::cout);
}