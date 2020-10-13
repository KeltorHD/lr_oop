#pragma once

#include <iostream>
#include <string>

class Figure
{
private:
	std::string type;

public:
	Figure(std::string type)
		:type(type){}
	virtual ~Figure() {}

	virtual bool equal(Figure* f) = 0;
	virtual void print() const = 0;
	const std::string& getType() const { return this->type; }
};