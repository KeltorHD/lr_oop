#pragma once

#include "figure.h"

class Line :
	public Figure
{
private:
	double k, b;

public:
	Line(double k, double b)
		: k(k), b(b), Figure("Line") {}

	virtual bool equal(Figure* f)
	{
		Line* eq = dynamic_cast<Line*>(f);
		if (eq)
		{
			if (eq->k == this->k && eq->b == this->b)
				return true;
			return false;
		}
		return false;
	}
	virtual void print() const
	{
		std::cout << "Линия. Уравнение: y = " << k << " * x + " << b;
	}
};