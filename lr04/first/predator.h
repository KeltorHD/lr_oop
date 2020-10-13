#pragma once

#include "animal.h"

class Predator :
	public Animal
{
private:
	uint8_t average_running_speed;

public:
	Predator() 
		: Animal(), average_running_speed(0) {}
	Predator(const char* kind, continent_t continent, uint8_t average_lifespan, uint8_t average_running_speed)
		: Animal(kind, continent, average_lifespan), average_running_speed(average_running_speed) {}

	const uint8_t& getAverageRunningSpeed() const { return this->average_running_speed; }

	void setAverageRunningSpeed(const uint8_t& average_running_speed) { this->average_running_speed = average_running_speed; }

	virtual void print() const;
};