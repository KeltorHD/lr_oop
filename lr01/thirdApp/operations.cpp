#include "operations.h"

void input(std::shared_ptr<int[]>& mas, int length)
{
	int sw{ -1 };

	while (sw <= 0 || sw >= 3)
	{
		std::cout << "��� ��������� ������? (1 - � ����������, 2 - �������� � ���������): ";
		std::cin >> sw;
		switch (sw)
		{
		case 1:
			inputHand(mas, length);
			break;
		case 2:
			inputRand(mas, length);
			outputScreen(mas, length);
			break;
		}
	}
}

void inputHand(std::shared_ptr<int[]>& mas, int length)
{
}

void inputRand(std::shared_ptr<int[]>& mas, int length)
{
}

void outputScreen(const std::shared_ptr<int[]>& mas, int length)
{
	std::cout << "������: ";
	for (int i = 0; i < length; i++)
	{
		std::cout << mas[i] << " ";
	}
	std::cout << "." << std::endl;
}
