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
			std::cout << "������:\n" << i << std::endl;
		}
		
		size_t line{};
		size_t number{};

		std::cout << "�������� ����� ������(� ����): ";
		std::cin >> line;
		while (line >= mas.size())
		{
			std::cout << "����� ������ ���!" << std::endl;

			std::cout << "�������� ����� ������(� ����): ";
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

		std::cout << "�������� ����� �����(� ����): ";
		std::cin >> number;
		while (number >= words.size())
		{
			std::cout << "������ ����� ���!" << std::endl;

			std::cout << "�������� ����� �����(� ����): ";
			std::cin >> number;
		}
		
		std::cout << "������ ����� �����: " << words[number][0] << std::endl;
	}
	else
	{
		std::cout << "�� ������� ������� ����!" << std::endl;
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
			std::cout << "������:\n" << i << std::endl;
		}

		size_t line{};
		size_t copy_line{};
		size_t number{};

		std::cout << "�������� ����� ������, � ������� ����� �������� ������ ������(� ����): ";
		std::cin >> line;
		while (line >= mas.size())
		{
			std::cout << "����� ������ ���!" << std::endl;

			std::cout << "�������� ����� ������, � ������� ����� �������� ������ ������(� ����): ";
			std::cin >> line;
		}

		std::cout << "�������� ������� � ������, � ������� ��������� ������ ������(� ����): ";
		std::cin >> number;
		while (number >= mas[line].size())
		{
			std::cout << "����� ������� ���!" << std::endl;

			std::cout << "�������� ������� � ������, � ������� ��������� ������ ������(� ����): ";
			std::cin >> number;
		}

		std::cout << "�������� ����� ������, ������� ����� �����������(� ����): ";
		std::cin >> copy_line;
		while (copy_line >= mas.size() || copy_line == line)
		{
			std::cout << "����� ������ ���!" << std::endl;

			std::cout << "�������� ����� ������, ������� ����� �����������(� ����): ";
			std::cin >> copy_line;
		}

		std::string result = mas[line].substr(0, number) + mas[copy_line] + mas[line].substr(number);
		std::cout << "���������:\n" << result << std::endl;
	}
	else
	{
		std::cout << "�� ������� ������� ����!" << std::endl;
	}
}
