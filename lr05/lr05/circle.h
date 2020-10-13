#pragma once

#include "figure.h"

class Circle :
	public Figure
{
private:
	double x, y;
	double r;

public:
	Circle(double x, double y, double r)
		: x(x),y(y),r(r), Figure("Circle"){}

	virtual bool equal(Figure* f)
	{
		Circle* eq = dynamic_cast<Circle*>(f);
		if (eq)
		{
			if (eq->x == this->x && eq->y == this->y && eq->r == this->r)
				return true;
			return false;
		}
		return false;
	}
	virtual void print() const
	{
		std::cout << "Круг. Положение: (" << x << ";" << y << "). Радиус: " << r; 
	}
};