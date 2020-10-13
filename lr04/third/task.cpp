#include "task.h"

void first()
{
	std::ifstream ifs("data.txt");
	if (ifs.is_open())
	{
		std::vector<std::string> mas;
		{
			std::string tmp;
			while (std::getline(ifs, tmp))
				mas.push_back(tmp);
		}
		for (auto& i : mas)
		{
			std::cout << "Строка:\n" << i << std::endl;
		}
		
		size_t line{};
		size_t number{};

		std::cout << "Выберите номер строки(с нуля): ";
		std::cin >> line;
		while (line >= mas.size())
		{
			std::cout << "Такой строки нет!" << std::endl;

			std::cout << "Выберите номер строки(с нуля): ";
			std::cin >> line;
		}

		std::vector<std::string> words;
		{
			std::stringstream ss(mas[line]);
			std::string tmp;
			while (ss >> tmp)
			{
				if (tmp != "." || tmp != "," || tmp != "?" || tmp != "!")
					words.push_back(tmp);
			}
		}

		std::cout << "Выберите номер слова(с нуля): ";
		std::cin >> number;
		while (number >= words.size())
		{
			std::cout << "Такого слова нет!" << std::endl;

			std::cout << "Выберите номер слова(с нуля): ";
			std::cin >> number;
		}
		
		std::cout << "Первая буква слова: " << words[number][0] << std::endl;
	}
	else
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
	}
}

void second()
{
	std::ifstream ifs("data.txt");
	if (ifs.is_open())
	{
		std::vector<std::string> mas;
		{
			std::string tmp;
			while (std::getline(ifs, tmp))
				mas.push_back(tmp);
		}
		for (auto& i : mas)
		{
			std::cout << "Строка:\n" << i << std::endl;
		}

		size_t line{};
		size_t copy_line{};
		size_t number{};

		std::cout << "Выберите номер строки, в которую нужно вставить другую строку(с нуля): ";
		std::cin >> line;
		while (line >= mas.size())
		{
			std::cout << "Такой строки нет!" << std::endl;

			std::cout << "Выберите номер строки, в которую нужно вставить другую строку(с нуля): ";
			std::cin >> line;
		}

		std::cout << "Выберите позицию в строке, с которой вставлять другую строку(с нуля): ";
		std::cin >> number;
		while (number >= mas[line].size())
		{
			std::cout << "Такой позиции нет!" << std::endl;

			std::cout << "Выберите позицию в строке, с которой вставлять другую строку(с нуля): ";
			std::cin >> number;
		}

		std::cout << "Выберите номер строки, которую нужно скопировать(с нуля): ";
		std::cin >> copy_line;
		while (copy_line >= mas.size() || copy_line == line)
		{
			std::cout << "Такой строки нет!" << std::endl;

			std::cout << "Выберите номер строки, которую нужно скопировать(с нуля): ";
			std::cin >> copy_line;
		}

		std::string result = mas[line].substr(0, number) + mas[copy_line] + mas[line].substr(number);
		std::cout << "Результат:\n" << result << std::endl;
	}
	else
	{
		std::cout << "Не удалось открыть файл!" << std::endl;
	}
}
