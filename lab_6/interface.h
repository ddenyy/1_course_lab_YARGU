#pragma once
#include "Header.h"
#include "scanf_write_matrix_1.h"
#include "Base_operation_matrix.h"
#include "first_task_function_matrix.h"
#include "second_task_determinate.h"
#include "third_task_matrix_system.h"

void print_menu() {
	cout << "Меню: \n";
	cout << "1 - Считать матрицу из файла input.txt \n";
	cout << "2 - Считать матрицу из консоли \n";
	cout << "3 - Привести матрицу к треугольному виду и посчитать её определитель \n";
	cout << "4 - посчитать матричное уравнение X^3 + 2X^2 + 5*X + 10 \n";
	cout << "5 - решить систему матричных уравнений № 3 в лабораторной работе\n";
	cout << "6 - очистить матрицу результата \n";
	cout << "7 - вывести матрицу в консоль \n";
	cout << "0 - выход \n";

}

void menu(vector<vector<double>>& Matrix, vector<vector<double>>& Res, int& size_matrix) {
	print_menu();
	int user_change;
	do {
		cin >> user_change;
		switch (user_change)
		{
		case 1: {
			scanf_matrix_file("input.txt", size_matrix, Matrix);
			init_matrix(size_matrix, Res);
			assigment_matrix(Matrix, Res);
			print_menu();
			break;
		}
		case 2: {
			clear_matrix(Res);
			init_matrix(size_matrix, Res);
			scanf_matrix_console(size_matrix, Matrix);
			print_menu();
			break;
		}
		case 3: {
			triangulation(Res, size_matrix);
			determinate_triangulation_matrix(Res, size_matrix);
			print_menu();
			break;
		}
		case 4: {
			function_matrix(Res, size_matrix);
			print_menu();
			break;
		}
		case 5: {
			count_matrix_system();
			print_menu();
			break;
		}
		case 6: {
			clear_matrix(Res);
			init_matrix(size_matrix, Res);
			assigment_matrix(Matrix, Res);
			print_menu();
			break;
		}
		case 7: {
			write_matrix_console(Matrix);
			print_menu();
			break;
		}
		case 0: {
			clear_matrix(Matrix);
			clear_matrix(Res);
			exit(0);
			break;
		}
		default:
			break;
		}
	} while (user_change != 0);
}