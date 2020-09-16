#pragma once

#include <cmath>

class CuttingMethod
{
public:
	typedef double (*function_t)(double);

private:
	function_t func;
	double accuracy;
	
public:
	CuttingMethod(function_t func, double accuracy = 1e-6)
		: func(func), accuracy(accuracy) {};

	void setFunc(function_t func) { this->func = func; }
	
	/*x0 - начальное приближение, x1 - второе приближение*/
	double computation(double x0, double x1);
	
};

