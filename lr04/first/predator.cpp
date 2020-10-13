#include "predator.h"

void Predator::print() const
{
	std::cout << "Хищник. ";
	Animal::print();
	std::cout << ", скорость бега: " << unsigned(this->average_running_speed);
}
