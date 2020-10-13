#pragma once

#include "figure.h"

class Rectangle :
	public Figure
{
private:
	double x, y;
	double w, h;

public:
	Rectangle(double x, double y, double w, double h)
		: x(x), y(y), w(w),h(h), Figure("Rectangle") {}

	virtual bool equal(Figure* f)
	{
		Rectangle* eq = dynamic_cast<Rectangle*>(f);
		if (eq)
		{
			if (eq->x == this->x && eq->y == this->y && eq->w == this->w && eq->h == this->h)
				return true;
			return false;
		}
		return false;
	}
	virtual void print() const
	{
		std::cout << "Прямоугольник. Положение: (" << x << ";" << y << "). Ширина-высота: (" << w << "; " << h << ")";
	}
};

