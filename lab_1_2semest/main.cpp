// lab_1_OsipovDenis_PMI13BO_2semestr.cpp 
// Лабораторная работа студента группы пми-13БО Осипова Дениса. Вариант 13
#include "main.h"
#include "Price.h"
#include "menu.h"
#include "Api_vector.h"

int main()
{
    vector<Price> DataBase;
    DataBase = inputFromFile("input.txt");
    setlocale(LC_CTYPE, "rus");

    print_inctruction_input();
    menu_swith_input_Data(DataBase);
    print_inctruction_logic_prog();
    menu_swith_action(DataBase);

	testAllRequestDataBase(DataBase);
	
	return 0;
}
