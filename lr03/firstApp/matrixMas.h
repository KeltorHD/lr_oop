#pragma once

#include "matrix.h"

class MatrixMas
{
private:
	std::unique_ptr<Matrix[]> mas;
	size_t length;

public:
	MatrixMas(size_t length);
};