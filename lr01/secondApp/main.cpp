#include "operations.h"

#include <vector>

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/

	std::vector<int> mas;
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
	mas.resize(length);

	/*Заполнение массива*/
	input(mas);

	/*Сортировка массива*/
	std::sort(mas.begin(), mas.end());
	std::cout << "Сортировка. " << std::endl;
	outputScreen(mas);

	/*Задание 15: Удалить самую длинную последовательность подряд идущих положительных элементов*/
	individual(mas);
	std::cout << "Удаление самой длинной последовательности положительных элементов. " << std::endl;
	outputScreen(mas);

	/*Вывод массива*/
	output(mas);

	return static_cast<bool>(std::cout);
}