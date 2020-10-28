#pragma once

#include <iostream>

template <typename item>
class Matrix
{
public:
	Matrix(size_t row, size_t col);
	Matrix(const item** mas, size_t row, size_t col);
	Matrix(const Matrix& mtrx);
	Matrix(Matrix&& mtrx);
	~Matrix();

	Matrix& operator=(const Matrix& mtrx);
	Matrix& operator=(Matrix&& mtrx);

	/*get*/
	size_t get_row() const;
	size_t get_col() const;

	/*operators*/
	Matrix operator+(const Matrix& mtrx) const throw();
	Matrix& operator+=(const Matrix& mtrx) throw();
	Matrix operator-(const Matrix& mtrx) const throw();
	Matrix& operator-=(const Matrix& mtrx) throw();
	Matrix operator*(const Matrix& mtrx) const throw();
	Matrix& operator*=(const Matrix& mtrx) throw();
	const item* operator[](int i) const;
	item* operator[](int i);

	/*operator input/output*/
	template<typename _item>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<_item>& mtrx);
	template<typename _item>
	friend std::istream& operator>>(std::istream& is, Matrix<_item>& mtrx);

private:
	size_t row;
	size_t col;
	item** m;

	void clear();
};

template<typename item>
inline Matrix<item>::Matrix(size_t row, size_t col)
	: row(row), col(col)
{
	this->m = new item * [row];
	for (size_t i = 0; i < row; i++)
	{
		this->m[i] = new item[col];
	}
}

template<typename item>
inline Matrix<item>::Matrix(const item** mas, size_t row, size_t col)
	: row(row), col(col)
{
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
		for (size_t j = 0; j < this->col; j++)
		{
			this->m[i][j] = mas[i][j];
		}
	}
}

template<typename item>
inline Matrix<item>::Matrix(const Matrix& mtrx)
	: row(mtrx.row), col(mtrx.col)
{
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
		for (size_t j = 0; j < this->col; j++)
		{
			this->m[i][j] = mtrx[i][j];
		}
	}
}

template<typename item>
inline Matrix<item>::Matrix(Matrix&& mtrx)
	: row(mtrx.row), col(mtrx.col)
{
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
		for (size_t j = 0; j < this->col; j++)
		{
			this->m[i][j] = mtrx[i][j];
			mtrx[i][j] = item{};
		}
	}
}

template<typename item>
inline Matrix<item>::~Matrix()
{
	this->clear();
}

template<typename item>
inline Matrix<item>& Matrix<item>::operator=(const Matrix& mtrx)
{
	this->clear();

	this->row = mtrx.row;
	this->col = mtrx.col;
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
		for (size_t j = 0; j < this->col; j++)
		{
			this->m[i][j] = mtrx[i][j];
		}
	}
}

template<typename item>
inline Matrix<item>& Matrix<item>::operator=(Matrix&& mtrx)
{
	this->clear();

	this->row = mtrx.row;
	this->col = mtrx.col;
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
		for (size_t j = 0; j < this->col; j++)
		{
			this->m[i][j] = mtrx[i][j];
			mtrx[i][j] = item{};
		}
	}
}

template<typename item>
inline size_t Matrix<item>::get_row() const
{
	return this->row;
}

template<typename item>
inline size_t Matrix<item>::get_col() const
{
	return this->col;
}

template<typename item>
inline Matrix<item> Matrix<item>::operator+(const Matrix& mtrx) const throw()
{
	if (this->row != mtrx.row || this->col != mtrx.col)
		throw "Размеры матриц не равны!";

	Matrix<item> tmp(this->row, this->col);

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			tmp[i][j] = this->m[i][j] + mtrx.m[i][j];
		}
	}
	return tmp;
}

template<typename item>
inline Matrix<item>& Matrix<item>::operator+=(const Matrix& mtrx)
{
	if (this->row != mtrx.row || this->col != mtrx.col)
		throw "Размеры матриц не равны!";

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->m[i][j] += mtrx.m[i][j];
		}
	}
	return *this;
}

template<typename item>
inline Matrix<item> Matrix<item>::operator-(const Matrix& mtrx) const
{
	if (this->row != mtrx.row || this->col != mtrx.col)
		throw "Размеры матриц не равны!";

	Matrix<item> tmp(this->row, this->col);

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			tmp[i][j] = this->m[i][j] - mtrx.m[i][j];
		}
	}
	return tmp;
}

template<typename item>
inline Matrix<item>& Matrix<item>::operator-=(const Matrix& mtrx)
{
	if (this->row != mtrx.row || this->col != mtrx.col)
		throw "Размеры матриц не равны!";

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < this->col; j++)
		{
			this->m[i][j] -= mtrx.m[i][j];
		}
	}
	return *this;
}

template<typename item>
inline Matrix<item> Matrix<item>::operator*(const Matrix& mtrx) const
{
	if (this->row != mtrx.col || this->col != mtrx.row)
		throw "Размеры матриц не могут быть перемножены!";

	Matrix<item> tmp(this->row, mtrx.col);

	for (int i = 0; i < this->row; i++)
	{
		for (int j = 0; j < mtrx.col; j++)
		{
			tmp[i][j] = 0;
			for (size_t k = 0; k < this->col; k++)
			{
				tmp[i][j] += this->m[i][k] * mtrx.m[k][j];
			}
		}
	}
	return tmp;
}

template<typename item>
inline Matrix<item>& Matrix<item>::operator*=(const Matrix& mtrx)
{
	if (this->row != mtrx.col || this->col != mtrx.row)
		throw "Размеры матриц не могут быть перемножены!";

	Matrix<item> tmp(*this);
	this->clear();

	this->row = tmp.row;
	this->col = mtrx.col;
	this->m = new item * [this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->m[i] = new item[this->col];
	}

	for (int i = 0; i < tmp.row; i++)
	{
		for (int j = 0; j < mtrx.col; j++)
		{
			this->m[i][j] = 0;
			for (size_t k = 0; k < this->col; k++)
			{
				this->m[i][j] += this->m[i][k] * mtrx.m[k][j];
			}
		}
	}
	return *this;
}

template<typename item>
inline const item* Matrix<item>::operator[](int i) const
{
	return this->m[i];
}

template<typename item>
inline item* Matrix<item>::operator[](int i)
{
	return this->m[i];
}

template<typename item>
inline void Matrix<item>::clear()
{
	for (size_t i = 0; i < this->row; i++)
	{
		delete[] this->m[i];
	}
	delete[] this->m;
}

template<typename _item>
inline std::ostream& operator<<(std::ostream& os, const Matrix<_item>& mtrx)
{
	for (int i = 0; i < mtrx.row; i++)
	{
		for (int j = 0; j < mtrx.col; j++)
		{
			os << mtrx.m[i][j] << "\t";
		}
		os << std::endl;
	}
	return os;
}

template<typename _item>
inline std::istream& operator>>(std::istream& is, Matrix<_item>& mtrx)
{
	//std::cout << "Ввод матрицы: " << std::endl;
	for (int i = 0; i < mtrx.row; i++)
	{
		for (int j = 0; j < mtrx.col; j++)
		{
			//std::cout << "M[" << i << "][" << j << "]= ";
			is >> mtrx.m[i][j];
		}
	}
	return is;
}
