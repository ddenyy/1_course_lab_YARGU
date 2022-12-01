#pragma once
#include "Header.h"
#include "Base_operation_matrix.h"
#include "scanf_write_matrix_1.h"

void function_matrix(vector<vector<double>>& Matrix, int size_matrix) {
	vector<vector<double>> Answer(size_matrix, vector<double>(size_matrix));
	vector<vector<double>> Matrix_pow_one(size_matrix, vector<double>(size_matrix));
	vector<vector<double>> Matrix_pow_two(size_matrix, vector<double>(size_matrix));
	vector<vector<double>> Matrix_pow_three(size_matrix, vector<double>(size_matrix));

	assigment_matrix(Matrix, Matrix_pow_one);

	multy_matrix(Matrix_pow_one, Matrix_pow_one, Matrix_pow_two);
	multy_matrix(Matrix_pow_two, Matrix_pow_one, Matrix_pow_three);

	cout << "исходная матрица\n";
	write_matrix_console(Matrix_pow_one);

	cout << "1-е действие X -> X^3 \n";
	write_matrix_console(Matrix_pow_three);

	cout << '\n';

	cout << "2-е действие X -> X^2 \n";
	write_matrix_console(Matrix_pow_two);
	cout << '\n';

	cout << "3-е действие X^2 -> 2 * X^2\n";
	mylty_elem_matrix(2, Matrix_pow_two, Matrix_pow_two);
	write_matrix_console(Matrix_pow_two);
	cout << '\n';

	cout << "4-е действие X -> 5 * X\n";
	mylty_elem_matrix(5, Matrix_pow_one, Matrix_pow_one);
	write_matrix_console(Matrix_pow_one);
	cout << '\n';

	cout << "5-е действие X^3 + 2X^2 \n";
	sum_matrix(Matrix_pow_three, Matrix_pow_two, Answer);
	write_matrix_console(Answer);
	cout << '\n';

	cout << "6-е действие X^3 + 2X^2 + 5*X\n";
	sum_matrix(Answer, Matrix_pow_one, Answer);
	write_matrix_console(Answer);

	cout << '\n';

	cout << "7-е действие X^3 + 2X^2 + 5*X + 10 = Ответ\n";
	sum_matrix_and_number(Answer, Answer, 10);
	write_matrix_console(Answer);

	clear_matrix(Answer);
	clear_matrix(Matrix_pow_one);
	clear_matrix(Matrix_pow_two);
	clear_matrix(Matrix_pow_three);
}