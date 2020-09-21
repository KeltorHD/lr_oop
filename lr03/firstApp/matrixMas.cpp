#include "matrixMas.h"

void MatrixMas::input()
{
	for (size_t i = 0; i < this->length; i++)
	{
		std::cin >> this->mas[i];
		std::cout << std::endl;
	}
}

Matrix MatrixMas::calculateFirst()
{
	/*вычисление суммы всех элементов массива*/
	Matrix result(this->mas[0]);

	for (size_t i = 1; i < this->length; i++)
	{
		result += this->mas[i];
	}

	return result;
}

Matrix MatrixMas::calculateSecond()
{
	/*Из элемента с наибольшим определителем вычесть произведение всех матриц, умноженное на этот определитель*/
	Matrix result{};

	size_t max_pos_mtrx{};
	item max_determinant{ this->mas[0].getDeterminant() };

	item det{};
	for (size_t i = 0; i < this->length; i++) /*нахождение максимального определителя*/
	{
		det = this->mas[i].getDeterminant();
		if (det > max_determinant)
		{
			max_determinant = det;
			max_pos_mtrx = i;
		}
	}

	std::shared_ptr<Matrix*[]> withoutMax{ new Matrix*[length-1]};
	size_t counter{};
	for (size_t i = 0; i < this->length; i++) /*массив без матрицы с макс опред*/
	{
		if (i == max_pos_mtrx) continue;

		withoutMax[counter] = &(this->mas[i]);
		counter++;
	}

	Matrix multip{ *withoutMax[0] };
	for (size_t i = 1; i < this->length - 1; i++) /*нахождение произведения*/
	{
		multip *= *withoutMax[i];
	}

	multip *= max_determinant;

	return this->mas[max_pos_mtrx] - multip;
}
