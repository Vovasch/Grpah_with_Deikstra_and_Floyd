#include<iostream>
#include<list>
#include<utility>
#include<vector>

#pragma once

using namespace std;

template <typename T>

class Matrix {
protected:

	vector<vector<T>> matrix;
	int strings;
	int comumns;

public:

	Matrix(int strings, int columns);

	void Push_Value(T value, int string, int column);

	T Get_Value(int string, int column);


};

template<typename T>
Matrix<T>::Matrix(int strings, int columns)
{
	this->strings = strings;
	this->comumns = columns;

}

template<typename T>
void Matrix<T>::Push_Value(T value, int string, int column)
{
	matrix[string][column] = value;
}

template<typename T>
T Matrix<T>::Get_Value(int string, int column)
{
	return this->matrix[string][column];
}