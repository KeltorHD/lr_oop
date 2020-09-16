#pragma once

#include <iostream>

typedef double item;

class Matrix
{
private:
	static const int length = 3;
	item m[length][length]{};

	/*method*/
	void mtrxIndDec(int numb);

public:
	Matrix() {};
	Matrix(const item mas[length][length]) { this->setMatrix(mas); };

	/*get*/
	item getDeterminant() const;

	/*set*/
	void setMatrix(const item mas[length][length]);

	/*operators*/
	Matrix operator+(const Matrix& mtrx) const;
	Matrix operator-(const Matrix& mtrx) const;
	Matrix operator*(const Matrix& mtrx) const;
	Matrix operator*(item numb) const;
	const item* operator[](int i);

	Matrix& operator++(); /*prefix*/
	Matrix& operator--(); /*prefix*/
	Matrix operator++(int); /*postfix*/
	Matrix operator--(int); /*postfix*/

	/*operator input/output*/
	friend std::ostream& operator<<(std::ostream& os, const Matrix& mtrx);
	friend std::istream& operator>>(std::istream& is, Matrix& mtrx);

	friend Matrix operator*(item numb, Matrix& mtrx);
};