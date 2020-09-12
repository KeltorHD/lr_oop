#include "abiturient.h"

std::ostream& operator<<(std::ostream& os, const Abiturient& abitur)
{
	return (os << abitur.name << ", " << abitur.adress);
}

std::ostream& operator<<(std::ostream& os, const Abiturient* abitur)
{
	return os << *abitur;
}

std::ostream& operator<<(std::ostream& os, const Abiturient::lesson& lesson)
{
	switch (lesson)
	{
	case Abiturient::lesson::inf:
		os << "Информатика";
		break;
	case Abiturient::lesson::math:
		os << "Математика";
		break;
	case Abiturient::lesson::russ:
		os << "Русский";
		break;
	case Abiturient::lesson::phis:
		os << "Физика";
		break;
	}
	return os;
}

int Abiturient::getSumScore() const
{
	int sum{ 0 };
	for (size_t j = 0; j < size_t(Abiturient::lesson::count); j++)
	{
		sum += this->scores[j];
	}
	return sum;
}
