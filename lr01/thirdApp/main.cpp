#include "operations.h"

#include <ctime>
#include <iostream>

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/
	//srand(time(0));
	/*
	15.	Изменять массив по следующему правилу:
	в первую ячейку помещать модуль разности между значениями первой и второй ячеек,
	во вторую – модуль разности между значениями второй и третьей ячеек, и т. д. 
	В последнюю ячейку помещать модуль разности между значениями последней и первой ячеек. 
	Если выполнять такие преобразования многократно, то можно ли в конечном итоге свести все элементы массива к нулю?
	*/

	int length{ -1 };
	int counterTransform{ -1 };

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
	/*Ввод кол-ва преобразований*/
	std::cout << "Введите кол-во преобразований: ";
	while (counterTransform <= 0)
	{
		std::cin >> counterTransform;
		if (counterTransform <= 0)
		{
			std::cout << "Ошибка, число неположительно, введите еще раз: ";
		}
	}
	
	std::shared_ptr<int[]> mas{ new int[length] };

	/*заполнение массива рандомно*/
	input(mas, length);
	outputScreen(mas, length);

	/*выполнение задания*/
	for (int i = 0; i < counterTransform; i++) /*количество преобразований массива*/
	{
		for (int j = 0; j < length; j++) /*однократное изменение массива*/
		{
			if (j != length - 1)
			{
				mas[j] = abs(mas[j] - mas[j + 1]);
			}
			else
			{
				mas[j] = abs(mas[0] - mas[j]);
			}
		}
	}
	std::cout << "Массив после преобразований: " << std::endl;
	outputScreen(mas, length);

	return static_cast<bool>(std::cout);
}