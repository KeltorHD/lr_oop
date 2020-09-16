#include "matrix.h"

void Matrix::mtrxIndDec(int numb)
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			this->m[i][j] += numb;
		}
	}
}

item Matrix::getDeterminant() const
{
	return 
		+this->m[0][0] * this->m[1][1] * this->m[2][2]
		+ this->m[0][1] * this->m[1][2] * this->m[2][0]
		+ this->m[0][2] * this->m[1][0] * this->m[2][1]
		- this->m[0][2] * this->m[1][1] * this->m[2][0]
		- this->m[0][0] * this->m[1][2] * this->m[2][1]
		- this->m[0][1] * this->m[1][0] * this->m[2][2];
}

void Matrix::setMatrix(const item mas[length][length])
{
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			this->m[i][j] = mas[i][j];
		}
	}
}

Matrix Matrix::operator+(const Matrix& mtrx) const
{
	item tmp[length][length]{};

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			tmp[i][j] = this->m[i][j] + mtrx.m[i][j];
		}
	}
	return Matrix(tmp);
}

Matrix Matrix::operator-(const Matrix& mtrx) const
{
	item tmp[length][length]{};

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			tmp[i][j] = this->m[i][j] - mtrx.m[i][j];
		}
	}
	return Matrix(tmp);
}

Matrix Matrix::operator*(const Matrix& mtrx) const
{
	item tmp[length][length]{};

	for (int i = 0; i < length; i++) /*строки*/
	{
		for (int j = 0; j < length; j++) /*столбцы*/
		{
			for (int r = 0; r < length; r++)
			{
				tmp[i][j] += this->m[i][r] * mtrx.m[r][j];
			}
		}
	}

	return Matrix(tmp);
}

Matrix Matrix::operator*(item numb) const
{
	item tmp[length][length]{};

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			tmp[i][j] = this->m[i][j] * numb;
		}
	}
	return Matrix(tmp);
}

const item* Matrix::operator[](int i)
{
	if (i >= length && i < 0);
		return nullptr;

	return m[i];
}

Matrix& Matrix::operator++()
{
	mtrxIndDec(+1);
	return *this;
}

Matrix& Matrix::operator--()
{
	mtrxIndDec(-1);
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix tmp(*this);
	mtrxIndDec(+1);
	return tmp;
}

Matrix Matrix::operator--(int)
{
	Matrix tmp(*this);
	mtrxIndDec(-1);
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Matrix& mtrx)
{
	os << "M: " << std::endl;
	for (int i = 0; i < Matrix::length; i++)
	{
		for (int j = 0; j < Matrix::length; j++)
		{
			os << mtrx.m[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}

std::istream& operator>>(std::istream& is, Matrix& mtrx)
{
	std::cout << "Ввод матрицы: " << std::endl;
	for (int i = 0; i < Matrix::length; i++)
	{
		for (int j = 0; j < Matrix::length; j++)
		{
			std::cout << "M[" << i << "][" << j << "]= ";
			is >> mtrx.m[i][j];
		}
	}
	return is;
}

Matrix operator*(item numb, Matrix& mtrx)
{
	return Matrix(mtrx * numb);
}
