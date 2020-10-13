#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <cstdint>
#include <cstring>

class Animal
{
public:
	enum class continent_t
	{
		Eurasia,
		Africa,
		North_America,
		South_America,
		Australia,
		Antarctica,
		none
	};
private:
	char* kind;
	continent_t continent;
	uint8_t average_lifespan;

public:
	Animal();
	Animal(const char* kind, continent_t continent, uint8_t average_lifespan);
	Animal(const Animal& a);
	Animal(Animal&& a) noexcept;
	virtual ~Animal();

	Animal& operator=(const Animal& a);
	Animal& operator=(Animal&& a) noexcept;

	const char* getKind() const { return this->kind; }
	const continent_t& getContinent() const { return this->continent; }
	const uint8_t& getAveraveLifespan() const { return this->average_lifespan; }

	char* get() { return this->kind; };

	void setKind(const char* kind) { delete[] this->kind; this->kind = new char[std::strlen(kind) + 1]; std::strcpy(this->kind, kind); }
	void setContinent(const continent_t& continent) { this->continent = continent; }
	void setAverageLifespan(const uint8_t& ls) { this->average_lifespan = ls; }

	virtual void print() const;

	friend std::ostream& operator<<(std::ostream& os, const Animal::continent_t& continent);
};