#include "operations.h"

void input(int* mas, int length)
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
			inputHand(mas, length);
			break;
		case 2:
			std::cout << "Введите название файла вместе с расширением: ";
			std::cin >> file;
			inputFile(mas, length, file);
			outputScreen(mas, length);
			break;
		case 3:
			inputRand(mas, length);
			outputScreen(mas, length);
			break;
		}
	}
}

void inputHand(int* mas, int length)
{
	for (int i = 0; i < length; i++)
	{
		std::cout << "Элемент " << i << ": ";
		std::cin >> mas[i];
	}
}

void inputRand(int* mas, int length)
{
	int left{2}, right{1};

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

void inputFile(int* mas, int length, std::string& str)
{
	std::ifstream fin;
	fin.open(str);
	bool isError{ false };

	if (fin.is_open())
	{
		for (int i = 0; i < length; i++)
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
		inputHand(mas, length);
	}
}

void individual(int*& mas, int& length)
{
	int minus{ 0 };
	for (int i = 0; i < length; i++)
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
		int* tmp = new int[minus];
		for (int i = 0; i < minus; i++)
		{
			tmp[i] = mas[i];
		}
		
		delete mas;
		length = minus;
		mas = tmp;
	}
}

void output(int* mas, int length)
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

		outputFile(mas, length, file);
	}
}

void outputScreen(int* mas, int length)
{
	std::cout << "Массив: ";
	for (int i = 0; i < length; i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "." << std::endl;
}

void outputFile(int* mas, int length, std::string& str)
{
	std::ofstream fout;
	fout.open(str);

	if (fout.is_open())
	{
		for (int i = 0; i < length; i++)
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
