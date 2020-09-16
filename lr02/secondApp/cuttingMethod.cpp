#include "cuttingMethod.h"

double CuttingMethod::computation(double x0, double x1)
{
	double tmp{};
    while (fabs(x1 - x0) > this->accuracy) /* Выбран останов |x[n]-x[n+1]|<accuracy */
    {  
        tmp = x1;
        x1 = x1 - (x1 - x0) * this->func(x1) / (this->func(x1) - this->func(x0));
        x0 = tmp;
    }
    return x1;
}
