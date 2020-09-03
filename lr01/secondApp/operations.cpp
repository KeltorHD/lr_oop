#include "operations.h"

void input(std::vector<int>& mas)
{
	int sw{ -1 };
	std::string file;

	while (sw <= 0 || sw >= 4)
	{
		std::cout << "Как заполнить массив? (1 - с клавиатуры, 2 - из файла, 3 - рандомно в диапазоне): ";
		std::cin >> sw;
		switch (sw)
		{
		case 1:
			inputHand(mas);
			break;
		case 2:
			std::cout << "Введите название файла вместе с расширением: ";
			std::cin >> file;
			inputFile(mas, file);
			outputScreen(mas);
			break;
		case 3:
			inputRand(mas);
			outputScreen(mas);
			break;
		}
	}
}

void inputHand(std::vector<int>& mas)
{
	for (size_t i = 0; i < mas.size(); i++)
	{
		std::cout << "Элемент " << i << ": ";
		std::cin >> mas[i];
	}
}

void inputRand(std::vector<int>& mas)
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

	for (size_t i = 0; i < mas.size(); i++)
	{
		mas[i] = rand() % (right - left + 1) + left;
	}
}

void inputFile(std::vector<int>& mas, std::string& str)
{
	std::ifstream fin;
	fin.open(str);
	bool isError{ false };

	if (fin.is_open())
	{
		for (size_t i = 0; i < mas.size(); i++)
		{
			if (!(fin >> mas[i]))
			{
				isError = true;
				std::cout << "Ошибка при вводе, ввод из консоли. " << std::endl;
				break;
			}
		}
	}
	else
	{
		std::cout << "Не удается открыть файл, ввод из консоли. " << std::endl;
		isError = true;
	}

	fin.close();

	if (isError)
	{
		inputHand(mas);
	}
}

void individual(std::vector<int>& mas)
{
	int minus{ 0 };
	for (size_t i = 0; i < mas.size(); i++)
	{
		if (mas[i] <= 0)
		{
			minus++;
		}
		else
		{
			break;
		}
	}

	if (minus)
	{
		mas.erase(mas.begin() + minus, mas.end());
		mas.resize(minus);
	}
}

void output(std::vector<int>& mas)
{
	int ch{ 0 };
	std::cout << "Опции вывода массива (1-не выводить, 2-вывести в файл): ";
	std::cin >> ch;

	while (ch <= 0 || ch >= 3)
	{
		std::cout << "Ошибка, еще раз(1-не выводить, 2-вывести в файл): ";
		std::cin >> ch;
	}

	if (ch == 2)
	{
		std::string file;
		std::cout << "Введите название файла вместе с расширением: ";
		std::cin >> file;

		outputFile(mas, file);
	}
}

void outputScreen(std::vector<int>& mas)
{
	std::cout << "Массив: ";
	for (size_t i = 0; i < mas.size(); i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "." << std::endl;
}

void outputFile(std::vector<int>& mas, std::string& str)
{
	std::ofstream fout;
	fout.open(str);

	if (fout.is_open())
	{
		for (size_t i = 0; i < mas.size(); i++)
		{
			if (!(fout << mas[i] << std::endl))
			{
				std::cout << "Ошибка при выводе в файл. " << std::endl;
				break;
			}
		}
		std::cout << "Успешно выведено в " << str << std::endl;
	}
	else
	{
		std::cout << "Не удается записать информацию в файл. " << std::endl;
	}

	fout.close();
}
