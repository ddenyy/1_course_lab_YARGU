// лабораторная работа №6 студента группы пми-13БО Осипова Дениса
#include "Header.h"
#include "interface.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	int size_matrix;
	vector<vector<double>> Matrix;
	vector<vector<double>> Result;
	menu(Matrix, Result, size_matrix);
}

