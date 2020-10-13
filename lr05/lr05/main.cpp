#include <iostream>
#include <vector>
#include <algorithm>

#include "circle.h"
#include "rectangle.h"
#include "line.h"

int main()
{
	system("chcp 65001>nul");

	std::vector<Figure*> mas;

	size_t length{};
	std::cout << "Введите количество фигур: ";
	std::cin >> length;

	for (size_t i = 0; i < length; i++)
	{
		int x{}, y{}, w{}, h{}, r{}, k{}, b{};
		int choice{ -1 };
		std::cout << "Введите тип фигуры: 1-круг, 2-прямоугольник, 3-линия\n Ваш выбор: ";

		while (choice > 3 || choice < 1)
		{
			std::cin >> choice;
			if (choice > 3 || choice < 1)
				std::cout << "Неправильный ввод!" << std::endl;
		}

		switch (choice)
		{
		case 1:
			std::cout << "x: "; std::cin >> x;
			std::cout << "y: "; std::cin >> y;
			std::cout << "r: "; std::cin >> r;
			mas.push_back(new Circle(x, y, r));
			break;
		case 2:
			std::cout << "x: "; std::cin >> x;
			std::cout << "y: "; std::cin >> y;
			std::cout << "w: "; std::cin >> w;
			std::cout << "h: "; std::cin >> h;
			mas.push_back(new Rectangle(x, y, w, h));
			break;
		case 3:
			std::cout << "k: "; std::cin >> k;
			std::cout << "b: "; std::cin >> b;
			mas.push_back(new Line(k, b));
			break;
		}
	}

	std::cout << "Введенные фигуры:" << std::endl;
	for (auto& i : mas)
	{
		i->print();
		std::cout << std::endl;
	}

	std::vector<Figure*> dublicate;
	/*задание*/
	for (auto& i : mas)
	{
		for (auto& j : mas)
		{
			if (&i != &j && i->getType() == j->getType() && i->equal(j) 
				&& std::find(dublicate.begin(), dublicate.end(), i) == dublicate.end()
				&& std::find(dublicate.begin(), dublicate.end(), j) == dublicate.end())
			{
				std::cout << "Найден повторяющийся элемент: ";
				i->print();
				std::cout << std::endl;
				dublicate.push_back(i);
				dublicate.push_back(j);
			}
		}
	}

	for (auto& i : mas)
		delete i;

	return bool(std::cout);
}