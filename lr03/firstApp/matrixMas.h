#pragma once

#include "matrix.h"

class MatrixMas
{
private:
	std::shared_ptr<Matrix[]> mas;
	size_t length;

public:
	MatrixMas(size_t length)
		: length(length), mas(new Matrix[length]) 
	{
		this->input();
	};
	~MatrixMas() {};

	MatrixMas(const MatrixMas&) = delete;
	MatrixMas& operator=(const MatrixMas&) = delete;

	/*methods*/
	void input();

	/*вычисление суммы всех элементов массива*/
	Matrix calculateFirst();

	/*Из элемента с наибольшим определителем вычесть произведение всех матриц, умноженное на этот определитель*/
	Matrix calculateSecond();
};