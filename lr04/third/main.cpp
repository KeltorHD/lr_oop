#include <iostream>

#include "task.h"
#include "timer.h"

int main()
{
	system("chcp 1251>nul");

	int choice{ - 1};

	while (choice != 3)
	{
		choice = -1;
		std::cout << "Какое задание следует выполнять?\n"
			"1:Найти слово, стоящее в тексте под определенным номером, и вывести его первую букву\n"
			"2:Вставить в заданную позицию строки другую строку\n"
			"3:Выход\n"
			"Выбор: ";


		while (choice > 3 || choice < 1)
		{
			std::cin >> choice;
			if (choice > 3 || choice < 1)
				std::cout << "Неправильный ввод!" << std::endl;
		}

		Timer timer;

		switch (choice)
		{
		case 1:
			first();
			std::cout << "Задание выполнялось: " << timer.elapsed() * 1000 << " миллисекунд(ы)" << std::endl;
			break;
		case 2:
			second();
			std::cout << "Задание выполнялось: " << timer.elapsed() * 1000 << " миллисекунд(ы)" << std::endl;
			break;
		case 3:
			break;
		}
	}

	return bool(std::cout);
}