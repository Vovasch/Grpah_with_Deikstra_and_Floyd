#include<iostream>
#include<list>
#include<utility>
#include<vector>

#pragma once

using namespace std;

template <typename T>

class Matrix {
protected:

	T** matrix;
	int strings;
	int columns;

public:

	Matrix(int strings, int columns);

	Matrix(const Matrix& matrix);

	void Push_Value(T value, int string, int column);

	inline T Get_Value(int string, int column) const
	{
		return this->matrix[string][column];
	}

	void operator=(const Matrix& matrix);


};

template<typename T>
Matrix<T>::Matrix(int strings, int columns)
{
	this->strings = strings;
	this->columns = columns;

	this->matrix = new T*[strings];

	for (int i = 0; i < strings; i++)
	{
		this->matrix[i] = new T[columns];
	}
}

template<typename T>
inline Matrix<T>::Matrix(const Matrix& matrix)
{
	this->strings = matrix.strings;
	this->columns = matrix.columns;

	this->matrix = new T * [this->strings];

	for (int i = 0; i < this->strings; i++)
		this->matrix[i] = new T[this->columns];


	for (int i = 0; i < this->strings; i++)
	{
		for (int e = 0; e < this->columns; e++)
		{
			this->matrix[i][e] = matrix.Get_Value(i, e);
		}
	}

}

template<typename T>
void Matrix<T>::Push_Value(T value, int string, int column)
{
	matrix[string][column] = value;
}

template<typename T>
inline void Matrix<T>::operator=(const Matrix& matrix)
{
	this->strings = matrix.strings;
	this->columns = matrix.columns;

	this->matrix = new T * [strings];

	for (int i = 0; i < strings; i++)
	{
		this->matrix[i] = new T[columns];
		for (int e = 0; e < this->columns; e++)
		{
			this->matrix[i][e] = matrix.Get_Value(i, e);
		}
	}

}

//template<typename T>
//T Matrix<T>::Get_Value(int string, int column)
//{
//	return this->matrix[string][column];
//}