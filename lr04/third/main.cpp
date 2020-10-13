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
		std::cout << "����� ������� ������� ���������?\n"
			"1:����� �����, ������� � ������ ��� ������������ �������, � ������� ��� ������ �����\n"
			"2:�������� � �������� ������� ������ ������ ������\n"
			"3:�����\n"
			"�����: ";


		while (choice > 3 || choice < 1)
		{
			std::cin >> choice;
			if (choice > 3 || choice < 1)
				std::cout << "������������ ����!" << std::endl;
		}

		Timer timer;

		switch (choice)
		{
		case 1:
			first();
			std::cout << "������� �����������: " << timer.elapsed() * 1000 << " �����������(�)" << std::endl;
			break;
		case 2:
			second();
			std::cout << "������� �����������: " << timer.elapsed() * 1000 << " �����������(�)" << std::endl;
			break;
		case 3:
			break;
		}
	}

	return bool(std::cout);
}