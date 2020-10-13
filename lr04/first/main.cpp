#include <iostream>
#include "predator.h"

int main()
{
	system("chcp 65001>nul");

	Predator pr("Lowe", Predator::continent_t::Africa, 10, 15);

	std::cout << "Изначальный объект: " << std::endl;
	pr.print();
	std::cout << std::endl;

	std::cout << "Изменена скорость бега: " << std::endl;
	pr.setAverageRunningSpeed(5);
	pr.print();
	std::cout << std::endl;

	std::cout << "Изменена продолжительность жизни: " << std::endl;
	pr.setAverageLifespan(15);
	pr.print();
	std::cout << std::endl;

	std::cout << "Изменено имя объекта: " << std::endl;
	pr.setKind("Puma");
	pr.print();
	std::cout << std::endl;

	return bool(std::cout);
}