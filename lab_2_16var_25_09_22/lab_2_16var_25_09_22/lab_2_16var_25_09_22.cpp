/*
lab_2_16var_25_09_22.cpp
Лабораторная работа №2 студента группы ПМИ-13БО Осипова Дениса
*/

#include <iostream>
using namespace std;

/*ф-ция принимает строку - комментарий в случае неправильного ввода
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

/*функция считает максимальную сумму n подряд идущих положительных
чисел*/
int find_max_positive_sum(int n) {
    int max_positive_sum = 0;
    int current_sum = 0;
    int a;                                       // текущее число которое будет введено для обработки

    for (int i = 0; i < n; i++) {
        cout << "Введите число = ";
        a = check_int_element("Неккоретный ввод. Введите целое число");
        if (a <= 0) {
            if (max_positive_sum < current_sum) {
                max_positive_sum = current_sum;
            }
            current_sum = 0;
        }
        else {
            current_sum += a;
        }
    }
    if (max_positive_sum < current_sum) {        // проверка последней текущей суммы и сравнение её с максимальной
        max_positive_sum = current_sum;
    }

    return max_positive_sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n;                                       // количество чисел которые будут введены
    
    cout << "Введите целое число n - количество подряд идущих чисел = ";
    n = check_int_element("Введите целое число n - количество подряд идущих чисел");

    cout << "максимальная сумма положительных подряд идущих чисел = " << find_max_positive_sum(n) << '\n';
    return 0;
}