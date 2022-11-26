// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// лабораторная работа номер 3 студента группы пми-13БО Осипова Дениса

#include <iostream>
#include <iomanip>
#include <time.h>
#include <cmath>
using namespace std;


/*
функция принимает два параметра типа double и int
первый параметр это основание степени, второй параметр степень 
возвращает число типа double: а в степени n
*/
double to_power(double a, int power) {
	double answer = 1;
	for (int i = 0; i < power; i++) {
		answer = answer * a;
	}
	return answer;
}

/*
ф-ция принимает один параметр типа int 
возвращает факториал данного числа типа int
*/
double to_factorial(int a) {
	if (a == 0) {
		return 1;
	}
	else {
		int answer = 1;
		for (int i = 1; i <= a; i++) {
			answer *= i;
		}
		return answer;
	}
}

/*
ф-ция принимающая параметр типа int
n степень минус единицы
*/
double flash_minus_one(int n) {
	if (n % 2 == 0) {
		return 1;
	}
	else {
		return -1;
	}
}

// ф-ция возвращает n-ный член последовательности.
// принимает значение х double и принимает counter - это номер члена последовательности 
double term(double x, int counter) {
	return (flash_minus_one(counter) * to_power(x / 2.0, 2 * counter + 1)) / (to_factorial(counter) * to_factorial(counter + 1));
}

/*
ф-ция считает сумму ряда с вспомогательными ф-циями
принимает e окрестность типа double и значение х типа double
*/
double sum_row_with_function_variation(double e, double x) {
	double curr_term = term(x, 0);
	double sum = curr_term;
	int counter = 1;
	while (abs(curr_term) >= e) {
		if (sum == INFINITY || sum == -INFINITY) {
			break;
			return sum;
		}
		curr_term = term(x, counter);
		sum += curr_term;
		counter++;
	}
	return sum;
}

/*
ф-ция считает сумму ряда без вспомогательных ф-ция
принимает e окрестность типа double и значение х типа double
*/
double sum_row_without_function(double e, double x) {
	double curr_term = (-1) * (x / 2); // i = 0;
	int counter = 1;
	double sum = curr_term;
	while (abs(curr_term) >= e) {
		curr_term *= (-1) * (x / 2) * (x / 2) / (counter * counter + 3 * counter + 2);
		sum += curr_term;
		counter++;
	}
	return sum;
}

/*
ф-ция выводит строчку в консоль длинны 40
*/
void cout_row() {
	int size_table = 40;
	for (int i = 0; i < size_table; i++) {
		cout << '-';
	}
	cout << '\n';
}

/*
ф-ция выводит значение в строку.
принимает значение х типа double и значение ф-ции типа double
*/
void cout_value(double x, double value) {
	cout << fixed << setprecision(8) << x << '\t' << fixed << setprecision(8) << value << '\n';
	
}


void cout_title(bool is_first_function) {
	if (is_first_function) {
		cout << 'x' << '\t' << '\t' << "F1(x)";
	}
	else {
		cout << 'x' << '\t' << '\t' << "F2(x)";
	}
}
/*
выводит ответ
принимает int n число табуляции ф-ции
принимает double a,b начало и конец отрезка
e - точность вычисления типа double
*/
void cout_tabulation_function(int n, double a, double b, double e) {
	double step = (b - a) / (n - 1);
	bool flag = true;
	double sum_steps = a;
	
	if (flag) {
		cout_row();
		cout_title(true);
		cout << '\n';
		cout_row();
		flag = false;
	}

	clock_t start_with_function_time = clock();
	for (double i = a; i <= b; i += step) {
		cout_value(i, sum_row_with_function_variation(e, i));
	}
	clock_t end_with_function_time = clock();

	double seconds_with_function = (double)(end_with_function_time - start_with_function_time) / CLOCKS_PER_SEC;

	cout_row();
	cout << "time with_function " << seconds_with_function << '\n';
	cout_row();

	cout_title(false);
	cout << '\n';
	cout_row();

	clock_t start_without_function_time = clock();
	for (double i = a; i <= b; i += step) {
		cout_value(i, sum_row_without_function(e, i));
	}
	clock_t end_without_function_time = clock();

	double seconds_without_function = (double)(end_without_function_time - start_without_function_time) / CLOCKS_PER_SEC;

	cout_row();
	cout << "time without_function " << seconds_without_function << '\n';
	cout_row();
	cout << "difference of time = " << abs(seconds_with_function - seconds_without_function);
}

/*ф-ция принимает строку - комментарий в случае неправильного ввода
возвращает переменную типа double которая была введена пользователем
*/
double check_double_element(string text) {
	double element;
	cin >> element;
	while (cin.fail())
	{
		cin.clear();                             // Возвращаем cin в 'обычный' режим работы 
		cin.ignore(10000, '\n');                 // Удаляем значения ВСЕ из входного буфера
		cout << text + ": ";
		cin >> element;
	}
	return element;
}

/*ф-ция принимает строку - комментарий в случае неправильного ввода
возвращает переменную типа int которая была введена пользователем
*/
int check_int_element(string text) {
	int element;
	cin >> element;
	if (cin.fail())
	{
		cin.clear();                             // Возвращаем cin в 'обычный' режим работы 
		cin.ignore(10000, '\n');                 // Удаляем значения ВСЕ из входного буфера
		cout << text + ": ";
		cin >> element;
	}
	return element;
}

void cin_all(int* n, double* a, double* b, double* e) {

	cout << "Введите натуральное число n - табуляция функции = ";
	*n = check_int_element("Введите натуральное число n (type integer) - табуляция функции = ");
	
	cout << "Введите число a рациональное число - начало отрезка = ";
	*a = check_double_element("Введите число a рациональное число (type double) - начало отрезка = ");

	cout << "Введите число b рациональное число - конец отрезка = ";
	*b = check_double_element("Введите число b рациональное число (type double) - начало отрезка = ");

	cout << "Введите число e рациональное число - точность вычислений = ";
	*e = check_double_element("Введите число e рациональное число (type double) - точность вычислений = ");
}

int main()
{
	setlocale(0, "rus");
	int n;		// табуляция
	double a, b;// отрезок в котором будем табулировать функцию
	double e;   // точность вычислений

	cin_all(&n, &a, &b, &e);
	cout_tabulation_function(n, a, b, e);
	
}
