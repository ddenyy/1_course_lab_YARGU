// lab2_2semesterOsipovDenis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Header.h"
#include "BigInteger.h"

int main()
{
    
    BigInteger number_first("111");
    BigInteger number_second("222");

    BigInteger Ans = number_second - number_first;

    cout << Ans.getValue();

}
