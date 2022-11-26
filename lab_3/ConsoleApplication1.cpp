// lab_3 подготовил студент группы ПМИ-13БО Осипов Денис
// var 6, 20;


//вывести на печать значения x, ε, 
//вычисленной суммы ряда, точного значения функции,
//разности суммы и точного значения функции,
//а также абсолютной величины последнего вычисленного члена ряда.

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


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

/*
ф-ция принимает число n типа int. И возводит -1 в степень n.
возвращает -1 в степени n
*/
double flashing_minus_one(int n) {
    if (n % 2 == 0) {
        return 1.0;
    }
    else {
        return -1.0;
    }
}

/*
ф-ция принимает два параметра типа double ε, x
возвращает число которое максимально близко к ε и меньше ε
*/
double find_max_item_row(double ε, double x) {
    int counter = 0;
    double first_x = x;
    while (abs(x) >= ε) {
        x = x * flashing_minus_one(counter) * (first_x * first_x) * (2 * counter + 1) / (2 * counter + 3);
        counter++;
    }
    return x;
}

/*
ф-ция принимает два параметра типа double ε, x
возвращает сумму ряда, такую что
последний элемент ряда максимально близок к ε и меньше ε
*/
double summator_row(double ε, double x) {
    // пока xi не станет меньше ε
    int counter = 0;
    double first_x = x;
    double sum_row = x;
    while (abs(x) >= ε) {
        x = x * flashing_minus_one(counter) * (first_x * first_x) * (2 * counter + 1) / (2 * counter + 3);
        sum_row += x;
        counter++;
    }
    return sum_row;
}

/*
ф-ция принимает два параметра типа double ε, x
выводит
Значение ε
Значение x
Сумму ряда
Точное значение arctg через встроенную ф-цию из библиотеки cmath
Разность суммы ряда и точного значения функции из библиотеки cmath
Абсолютную разность ε и величины последнего члена ряда
*/
void cout_answer(double ε, double x) {
    cout << fixed << setprecision(12) << "Значение e = " << ε << '\n';
    cout << fixed << setprecision(12) << "Значение x = " << x << '\n';
    cout << fixed << setprecision(12) << "Сумма ряда = " << summator_row(ε, x) << '\n';
    cout << fixed << setprecision(12) << "Точное значение arctg(" << x << ") = " << atan(x) << '\n';
    cout << fixed << setprecision(12) << "Разность суммы ряда и точного значения функции = " << summator_row(ε, x) - atan(x) << '\n';
    cout << fixed << setprecision(12) << "Абсолютная разность e и величины последнего члена ряда = " << ε - abs(find_max_item_row(ε, x)) << '\n';
}

int main()
{
    setlocale(0, "rus");
	double ε;
	double x;
    
    cout << "введите е окрестность - число типа double = ";
    ε = check_double_element("введите е окрестность - число типа double: ");
    cout << "введите x число типа double= ";
    x = check_double_element("введите x - число типа double в диапазоне от -1 до 1 ");
    cout_answer(ε, x);

    return 0;
}
