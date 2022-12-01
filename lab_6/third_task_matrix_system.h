#pragma once
#include "Header.h"
#include "Base_operation_matrix.h"
#include "scanf_write_matrix_1.h"


void count_matrix_system() {
	int size_free_matrix_first;
	int size_free_matrix_second;

	vector<vector<double>> free_Matrix_first_system;
	vector<vector<double>> free_Matrix_second_system;
	vector<vector<double>> Answer_X;
	vector<vector<double>> Answer_Y;

	scanf_matrix_file("input_for_third_1.txt", size_free_matrix_first, free_Matrix_first_system);
	scanf_matrix_file("input_for_third_2.txt", size_free_matrix_second, free_Matrix_second_system);

	init_matrix(size_free_matrix_first, Answer_X);
	init_matrix(size_free_matrix_second, Answer_Y);


	cout << "Изначальная система -> \n";
	cout << "| 3X - 2Y = \n";
	write_matrix_console(free_Matrix_first_system);

	cout << "| 2X + 3Y = \n";
	write_matrix_console(free_Matrix_second_system);

	cout << '\n';

	cout << "умножим первую систему на 3/2 \n";
	cout << "| 4,5X - 3Y \n";
	mylty_elem_matrix(1.5, free_Matrix_first_system, free_Matrix_first_system);
	write_matrix_console(free_Matrix_first_system);
	cout << "| 2X + 3Y = \n";
	write_matrix_console(free_Matrix_second_system);

	cout << '\n';

	cout << "Прибавим к первой строке вторую \n";
	cout << "| 6.5X = \n";
	sum_matrix(free_Matrix_first_system, free_Matrix_second_system, free_Matrix_first_system);
	write_matrix_console(free_Matrix_first_system);
	cout << "| 2X + 3Y = \n";
	write_matrix_console(free_Matrix_second_system);
	cout << '\n';

	cout << "Выразим матрицу Х и У \n";
	cout << "X = \n";
	mylty_elem_matrix(1/6.5, free_Matrix_first_system, free_Matrix_first_system);
	assigment_matrix(free_Matrix_first_system, Answer_X);
	write_matrix_console(Answer_X);

	cout << "Y = (-3 2) - 2X\n";
	cout << "    ( 6 1) \n";
	mylty_elem_matrix(2, free_Matrix_first_system, free_Matrix_first_system);
	dif_matrix(free_Matrix_second_system, free_Matrix_first_system, Answer_Y);

	cout << "X =\n";
	write_matrix_console(Answer_X);
	cout << "Y = \n";
	write_matrix_console(Answer_Y);

	clear_matrix(Answer_X);
	clear_matrix(Answer_Y);
	clear_matrix(free_Matrix_first_system);
	clear_matrix(free_Matrix_second_system);
}