 /*lab_work_number_4.cpp
 лабораторная работа №4 Студента группы пми-13БО Осипова Дениса
 3 поле | король | 2 задача
 */

#include <iostream>
using namespace std;

/*ф-ция ОБРАБОТКИ ОШИБОК ВВОДА принимает строку - комментарий в случае неправильного ввода
возвращает переменную типа int которая была введена пользователем
*/
int check_int_element(string text) {
	int element;
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

/*
ф-ция ВЫВОДИТ ТЕКУЩУЮ ПОЗИЦИЮ короля
принимает 1 параметр типа int и выводит его в консоль
*/
void cout_step(int step) {
	cout << " => " << step;
}

/*
ф-ция ПРОВЕРЯЕТ на одной ли строке король и позиция финиша.
принимает:
текущая позиция короля типа int
позиция в которую должен прийти король типа int
количество элементов в строке типа int
!!! Если король находится на одной строке с точкой финиша выведет TRUE иначе FALSE !!!
*/
bool check_on_one_row(int i, int position_finish, int count_element_in_row) {			
	if (i <= count_element_in_row && position_finish <= count_element_in_row) {				// проверка что король и финиш на первой строке
		return true;
	} else if (i / count_element_in_row == position_finish / count_element_in_row) {		// проверка что король и финиш не на первой строке
		return true;
	}
	else {
		return false;
	}
};

/*
ф-ция проверки позиции короля и финиша в строке принимает два параметра 
первый параметр текущая позиция короля
второй параметр конечная позиция короля
Возвращает true если позиция короля правее 
Возвращает false если позиция короля левее
относительно конечной точки финиша
*/
bool is_more(int i, int position_finish) {
	if (i > position_finish) {
		return true;
	}
	else {
		return false;
	}
}

/*
ф - ция шага между строками. 
принимает:
значение ячейки где находится король типа int.
количество элементов в строке типа int.
количество всего строк на поле типа int
направление куда делаем шаг типа bool. Eсли is_up true то вверх иначе вниз
*/
int step_between_rows(int i, int count_element_in_row, int count_rows, bool is_up) {
	int current_position = i;															// текущая позиция короля
	if (is_up) {				
		if (current_position > count_element_in_row) {									// проверка что текущая позиция НЕ на 1 строке
			current_position -= count_element_in_row;
		}
		else {
			current_position;
		}
	}
	else  {
		if (current_position < count_element_in_row * (count_rows - 1)) {				// проверка что текущая позиция НЕ на последней строке
			current_position += count_element_in_row;
		}
		else {
			current_position;
		}
	}
	return current_position;
}

/*
ф-ция шага в строке
принимает:
текущую позицию короля (int i)
позицию финиша (int position_finish)
количество элементов в строке
*/
void step_in_row(int i, int position_finish, int count_element_in_row) {
	int current_position = i;
		if (is_more(current_position, position_finish)) {				// проверка расположения короля относительно финиша на одной строке
			while (current_position > position_finish) {				// пока позиция короля правее
				current_position--;										// идём влево
				cout_step(current_position);							// выводим текущую позицию
			}
		}
		else {
			while (current_position < position_finish) {
				current_position++;
				cout_step(current_position);
			}
		}
}
/*
главная функция которая ведёт короля до позиции финиша из позиции старта
принимает:
стартовую позицию короля i типа int
количество элементов в строке типа int
количество всех строк типа int
позицию финиша
*/
void step_to_finish(int i, int count_element_in_row, int count_rows, int position_finish) {
	int start_row = i / count_element_in_row;													// номер строки с которой начинает шагать король
	int finish_row = position_finish / count_element_in_row;									// номер строки в которую придёт король

	int current_position = i;																	// текущая позиция короля
	cout_step(current_position);																// выведем текущую позицию короля
	if (start_row > finish_row) {																// случай, когда строка с которой стартуем ниже
		bool is_up = true;																		// переменная чтоб ф-ция шага между строк поняла куда идти
		while (!check_on_one_row(current_position,position_finish, count_element_in_row)) {		// пока король и позиция финиша НЕ на одной строке
			current_position = step_between_rows(current_position, count_element_in_row, count_rows, is_up);	// меняем текущую позицию (сделали шаг вверх)
			cout_step(current_position);														// вывели текущую позицию в консоль
		}
		if (check_on_one_row(current_position, position_finish, count_element_in_row)) {		// доп.проверка, если мы на одной строке
			step_in_row(current_position, position_finish, count_element_in_row);				// шагаем В строке с текущей позиции до финиша
		}
	}
	else {
		bool is_up = false;																		// переменная чтоб ф-ция шага между строк поняла куда идти
		while (!check_on_one_row(current_position, position_finish, count_element_in_row)) {	// пока король и позиция финиша НЕ на одной строке
			current_position = step_between_rows(current_position, count_element_in_row, count_rows, is_up); // меняем текущую позицию (сделали шаг ВНИЗ)
			cout_step(current_position);														// вывели ответ
		}
		if (check_on_one_row(current_position, position_finish, count_element_in_row)) {        // доп.проверка, если мы на одной строке
			step_in_row(current_position, position_finish, count_element_in_row);				// шагаем В строке с текущей позиции до финиша
		}
	}
}

/*
ф-ция считывает все переменные необходимые для работы программы
принимает ссылки на все переменные из main
*/
void cin_all(int* count_rows, int* count_elemets_in_row, int* row_position_start, int* position_in_row_start, int* row_position_finish, int* position_in_row_finish) {

	cout << "Введите количество строк в поле = ";
	*count_rows = check_int_element("Введите элемент типа int! количество строк = ");

	cout << "Введите количество элементов в строке = ";
	*count_elemets_in_row = check_int_element("Введите элемент типа int! количество элементам в строке = ");

	cout << "Введите номер строки с какой король будет ходить = ";
	*row_position_start = check_int_element("Введите элемент типа int! номер строки с которой будет ходить король = ");

	cout << "Введите позицию короля в строке с которой он будет ходить = ";
	*position_in_row_start = check_int_element("Введите элемент типа int! позиция в строке с которой будет ходить король = ");

	cout << "Введите номер строки в которую король придёт = ";
	*row_position_finish = check_int_element("Введите элемент типа int! номер строки в которую придёт король = ");

	cout << "Введите позицию короля в строке в которую он придёт = ";
	*position_in_row_finish = check_int_element("Введите элемент типа int! позиция в строке куда придёт король = ");
}

/*
ф-ция выявления ошибок при вводе
принимает: ссылки на все переменные из main
*/
void detect_errors(int* count_rows, int* count_elemets_in_row, int* row_position_start, int* position_in_row_start, int* row_position_finish, int* position_in_row_finish) {

	int start_position = ((*row_position_start - 1) * *count_elemets_in_row) + *position_in_row_start;					// номер ячейки с которой старует король

	int finish_position = ((*row_position_finish - 1) * *count_elemets_in_row) + *position_in_row_finish;				// номер ячейки в которую приходит король

	int last_position = *count_elemets_in_row * *count_rows;															// номер последней ячейки на поле

	if (*count_rows < *row_position_start) {
		cout << "в поле всего " << *count_rows << " строк. Введите корретные значения начальной строки! \n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
	else if (*count_rows < *row_position_finish) {
		cout << "в поле всего " << *count_rows << " строк. Введите корретные значения финишной строки строки! \n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
	else if (start_position > last_position) {
		cout << "Мы не можем выходить за пределы поля! Введите корректные значение позиции старта !\n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
	else if (finish_position > last_position) {
		cout << "Мы не можем выходить за пределы поля! Введите корректные значение позиции финиша !\n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
	else if (start_position <= 0) {
		cout << "Начальная позиция не нулевая! минимальные координаты (1,1) ! \n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
	else if (finish_position <= 0) {
		cout << "Конечная позиция неккоректна! \n";
		cin_all(count_rows, count_elemets_in_row, row_position_start, position_in_row_start, row_position_finish, position_in_row_finish);
	}
}

int main()
{	
	setlocale(0, "RUS");
	int count_rows;							// количество строк в поле
	int count_elemets_in_row;				// количество элементов в одной строке
	int row_position_start;					// номер строки с которой ходит король
	int position_in_row_start;				// позиция в строке с которой ходит король 
	int row_position_finish;				// номер строки куда приходит король
	int position_in_row_finish;				// позиция в строке куда приходит король

	cin_all(&count_rows,&count_elemets_in_row, &row_position_start, &position_in_row_start,&row_position_finish, &position_in_row_finish);

	detect_errors(&count_rows, &count_elemets_in_row, &row_position_start, &position_in_row_start, &row_position_finish, &position_in_row_finish);
	
	int start_position = ((row_position_start - 1) * count_elemets_in_row) + position_in_row_start;
	int finish_position = ((row_position_finish - 1) * count_elemets_in_row) + position_in_row_finish;

	step_to_finish(start_position, count_elemets_in_row, count_rows, finish_position);

	return 0;
}

