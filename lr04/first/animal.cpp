#include "animal.h"

Animal::Animal()
{
	this->kind = new char[5] {"none"};
	this->continent = continent_t::none;
	this->average_lifespan = 0;
}

Animal::Animal(const char* kind, continent_t continent, uint8_t average_lifespan)
	:continent(continent), average_lifespan(average_lifespan)
{
	this->kind = new char[std::strlen(kind) + 1]; 
	std::strcpy(this->kind, kind);
}

Animal::Animal(const Animal& a)
	: continent(a.continent), average_lifespan(a.average_lifespan)
{
	this->kind = new char[std::strlen(a.kind) + 1];
	std::strcpy(this->kind, a.kind);
}

Animal::Animal(Animal&& a) noexcept
	: continent(a.continent), average_lifespan(a.average_lifespan), kind(a.kind)
{
	a.continent = continent_t::none;
	a.kind = new char[5] {"none"};
	a.average_lifespan = 0;
}

Animal::~Animal()
{
	delete this->kind;
}

Animal& Animal::operator=(const Animal& a)
{
	if (&a == this)
		return *this;

	delete[] this->kind;
	this->kind = new char[std::strlen(a.kind) + 1];
	std::strcpy(this->kind, a.kind);

	this->continent = a.continent;
	this->average_lifespan = a.average_lifespan;

	return *this;
}

Animal& Animal::operator=(Animal&& a)noexcept
{
	if (&a == this)
		return *this;

	delete[] this->kind;
	this->kind = a.kind;

	this->continent = a.continent;
	this->average_lifespan = a.average_lifespan;

	a.continent = continent_t::none;
	a.kind = new char[5] {"none"};
	a.average_lifespan = 0;

	return *this;
}

void Animal::print() const
{
	std::cout << "Существо вида: " << this->kind << ", континент: " << this->continent << ", ср. продолж. жизни: " << unsigned(this->average_lifespan);
}

std::ostream& operator<<(std::ostream& os, const Animal::continent_t& continent)
{
	switch (continent)
	{
	case Animal::continent_t::Africa:
		os << "Африка";
		break;
	case Animal::continent_t::Antarctica:
		os << "Антарктида";
		break;
	case Animal::continent_t::Australia:
		os << "Австралия";
		break;
	case Animal::continent_t::Eurasia:
		os << "Евразия";
		break;
	case Animal::continent_t::none:
		os << "Нет материка";
		break;
	case Animal::continent_t::North_America:
		os << "Сев. Америка";
		break;
	case Animal::continent_t::South_America:
		os << "Южн. Америка";
		break;
	}
	return os;
}
