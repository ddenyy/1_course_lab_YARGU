// lab2_2semesterOsipovDenis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
#include "BigInteger.h"

int main()
{
    
    BigInteger number_first("100");
    BigInteger number_second("-123123");

    BigInteger Ans = number_second * number_first;
    string str_ans = Ans.getValue();
    Ans.getIsNegative() ? str_ans = "-" + str_ans : str_ans;
    cout << str_ans << '\n';

    BigInteger a(0);
    BigInteger b(1);

    if (a)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}

