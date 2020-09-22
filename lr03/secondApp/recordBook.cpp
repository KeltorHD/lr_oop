#include "recordBook.h"

std::ostream& operator<<(std::ostream& os, RecordBook::lesson& les)
{
	switch (les)
	{
	case RecordBook::lesson::inf:
		os << "Информатика";
		break;
	case RecordBook::lesson::math:
		os << "Математика";
		break;
	case RecordBook::lesson::prog:
		os << "Программирование";
		break;
	case RecordBook::lesson::disk:
		os << "Диск. математика";
		break;
	case RecordBook::lesson::hist:
		os << "История";
		break;
	case RecordBook::lesson::os:
		os << "Опер. системы";
		break;
	case RecordBook::lesson::fil:
		os << "Филососфия";
		break;
	case RecordBook::lesson::saod:
		os << "САОД";
		break;
	case RecordBook::lesson::oop:
		os << "ООП";
		break;
	case RecordBook::lesson::fhys:
		os << "Физика";
		break;
	case RecordBook::lesson::sprt:
		os << "ФИЗ-РА";
		break;
	case RecordBook::lesson::bd:
		os << "Базы данных";
		break;
	}
	return os;
}

std::istream& operator>>(std::istream& is, RecordBook::lesson& les)
{
	int tmp{};
	is >> tmp;
	les = static_cast<RecordBook::lesson>(tmp);
	return is;
}

std::istream& operator>>(std::istream& is, RecordBook& rb)
{
	is >> rb.firstName;
	is >> rb.lastName;
	is >> rb.specialty;

	for (size_t i = 0; i < rb.countSemestr; i++)
	{
		size_t length{};
		is >> length;
		rb.semestrMas[i] = new RecordBook::GradeSemestr(length);
		is >> *rb.semestrMas[i];
	}
	return is;
}

RecordBook::RecordBook(size_t countSemestr)
	: countSemestr(countSemestr)
{
	this->semestrMas.resize(countSemestr);
}

RecordBook::~RecordBook()
{
	for (size_t i = 0; i < this->semestrMas.size(); i++)
	{
		delete this->semestrMas[i];
	}
}

RecordBook::RecordBook(const RecordBook& rb)
	: countSemestr(rb.countSemestr)
{
	this->semestrMas.resize(countSemestr);
	for (size_t i = 0; i < this->countSemestr; i++)
	{
		this->semestrMas[i] = new GradeSemestr(*rb.semestrMas[i]);
	}
}

RecordBook::RecordBook(RecordBook&& rb) noexcept
	:countSemestr(rb.countSemestr)
{
	for (size_t i = 0; i < this->countSemestr; i++)
	{
		this->semestrMas[i] = rb.semestrMas[i];
		rb.semestrMas[i] = nullptr;
	}
}

RecordBook& RecordBook::operator=(const RecordBook& rb)
{
	if (&rb == this)
		return *this;

	for (size_t i = 0; i < this->countSemestr; i++)
	{
		delete this->semestrMas[i];
	}
	this->countSemestr = rb.countSemestr;

	for (size_t i = 0; i < this->countSemestr; i++)
	{
		this->semestrMas[i] = new GradeSemestr(*rb.semestrMas[i]);
	}
	
	return *this;
}

RecordBook& RecordBook::operator=(RecordBook&& rb) noexcept
{
	if (&rb == this)
		return *this;

	for (size_t i = 0; i < this->countSemestr; i++)
	{
		delete this->semestrMas[i];
	}
	this->countSemestr = rb.countSemestr;

	for (size_t i = 0; i < this->countSemestr; i++)
	{
		this->semestrMas[i] = rb.semestrMas[i];
		rb.semestrMas[i] = nullptr;
	}
	
	return *this;
}

std::string RecordBook::getInfo() const
{
	std::stringstream ss;
	ss << this->firstName << " " << this->lastName << ", " << this->specialty;
	return ss.str();
}

float RecordBook::getAverageCourse(size_t course) const
{
	if ((course * 2 + 1) < this->countSemestr)
	{
		return static_cast<float>((this->semestrMas[course * 2]->getSumGrade() + this->semestrMas[course * 2 + 1]->getSumGrade()))
			/ static_cast<float>((this->semestrMas[course * 2]->getCountLessons() + this->semestrMas[course * 2 + 1]->getCountLessons()));
	}
	
	return -100.f; /*FAILED*/
}

size_t RecordBook::getCountGrade(size_t course, int grade) const
{
	if ((course * 2 + 1) < this->countSemestr)
	{
		return this->semestrMas[course * 2]->getCountGrade(grade) + this->semestrMas[course * 2 + 1]->getCountGrade(grade);
	}

	return 9999; /*FAILED*/
}

void RecordBook::printGrage(size_t semestr) const
{
	if (semestr < this->countSemestr)
	{
		this->semestrMas[semestr]->printGrade();
	}
	else
	{
		std::cout << "FAILED" << std::endl;
	}
}
