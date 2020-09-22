#include "recordBook.h"

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

std::string RecordBook::getInfo()
{
	std::stringstream ss;
	ss << this->firstName << " " << this->lastName << ", " << this->specialty;
	return ss.str();
}
