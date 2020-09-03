#include "operations.h"

int main()
{
	system("chcp 65001>nul"); /*кодировка unicode*/
	
	int* mas{ nullptr };
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
	mas = new int[length];
	
	/*Заполнение массива*/
	input(mas, length);

	/*Сортировка массива*/
	std::sort(mas, mas + length);
	std::cout << "Сортировка. " << std::endl;
	outputScreen(mas, length);

	/*Задание 15: Удалить самую длинную последовательность подряд идущих положительных элементов*/
	individual(mas, length);
	std::cout<< "Удаление самой длинной последовательности положительных элементов. " << std::endl;
	outputScreen(mas, length);

	/*Вывод массива*/
	output(mas, length);

	delete[] mas;

	return static_cast<bool>(std::cout);
}