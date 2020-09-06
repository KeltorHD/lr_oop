#include "operations.h"

void input(std::shared_ptr<int[]>& mas, int length)
{
	int sw{ -1 };

	while (sw <= 0 || sw >= 3)
	{
		std::cout << "Как заполнить массив? (1 - с клавиатуры, 2 - рандомно в диапазоне): ";
		std::cin >> sw;
		switch (sw)
		{
		case 1:
			inputHand(mas, length);
			break;
		case 2:
			inputRand(mas, length);
			break;
		}
	}
}

void inputHand(std::shared_ptr<int[]>& mas, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Элемент " << i << ": ";
		std::cin >> mas[i];
	}
}

void inputRand(std::shared_ptr<int[]>& mas, int length)
{
	int left{ 2 }, right{ 1 };

	while (left > right)
	{
		std::cout << "Введите левую границу:";
		std::cin >> left;
		std::cout << "Введите правую границу:";
		std::cin >> right;

		if (left > right)
		{
			std::cout << "Левая граница больше правой!" << std::endl;
		}
	}

	for (int i = 0; i < length; i++)
	{
		mas[i] = rand() % (right - left + 1) + left;
	}
}

void outputScreen(const std::shared_ptr<int[]>& mas, int length)
{
	std::cout << "Массив: ";
	for (int i = 0; i < length; i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "." << std::endl;
}
