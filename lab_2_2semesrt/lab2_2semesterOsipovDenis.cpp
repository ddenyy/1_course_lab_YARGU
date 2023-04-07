// lab2_2semesterOsipovDenis.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "Header.h"
#include "BigInteger.h"

void AllTests()
{
    BigInteger number_first("123123123123123123123");
    BigInteger number_second("32131231231321321312");

    bool test_bool = number_first < number_second;
    cout << "test 1 '<' expect 1 = " << test_bool << endl;

    number_first = BigInteger("-123123123123123123123");
    number_second = BigInteger("123123123123123123121");

    test_bool = number_second < number_first;

    cout << "test 2 '<' expect 0 = " << test_bool << endl;

    number_first = BigInteger("-10010000000000000000000000000000000000");
    number_second = BigInteger("-11000000000000000001000000000000000000");

    test_bool = number_second > number_first;

    cout << "test 3 '>' expect 0 = " << test_bool << endl;

    number_first = BigInteger("-1");
    number_second = BigInteger("0");

    test_bool = number_second > number_first;

    cout << "test 4 '>' expect 1 = " << test_bool << endl;

    number_first = BigInteger("10000000000000000001000000000000000000");
    number_second = BigInteger("11000000000000000001000000000000000000");

    test_bool = number_second > number_first;

    cout << "test 5 '>' expect 1 = " << test_bool << endl;

    number_first = BigInteger("10000000000000000001000000000000000000");
    number_second = BigInteger("11000000000000000001000000000000000000");

    BigInteger test_ans = number_first + number_second;

    cout << "test 6 '+' expect 21000000000000000002000000000000000000 = " << test_ans << endl;

    number_first = BigInteger("-10000100000000000001000000000000000000");
    number_second = BigInteger("32131200000000000001000000000000000000");

    test_ans = number_first + number_second;

    cout << "test 7 '+' expect 22131100000000000000000000000000000000 = " << test_ans << endl;

    number_first = BigInteger("123456990000000000001000000000000000000");
    number_second = BigInteger("-32131200000000000001000000000000000000");

    test_ans = number_first + number_second;

    cout << "test 8 '+' expect 91325790000000000000000000000000000000 = " << test_ans << endl;

    number_first = BigInteger("123456990000000000001000000000000000000");
    number_second = BigInteger("-32131200000000000001000000000000000000");

    test_ans = number_first * number_second;

    cout << "test 9 '*' expect -3966821237088000000155588190000000000001000000000000000000000000000000000000 = " << test_ans << endl;

    number_first = BigInteger("123456990000000000001000000000000000000");
    number_second = BigInteger("0");

    test_ans = number_first * number_second;

    cout << "test 10 '*' expect 0 = " << test_ans << endl;

    number_first = BigInteger("1111111111111111111111111111111111111111111111111111111111111");
    number_second = BigInteger("99999999999999999999999999999999991111111111111111111111119999999999999999999999");

    test_ans = number_first * number_second;

    cout << "test 11 '*' expect 111111111111111111111111111111111101234567901234567901234577766666666666666666665555555555555556543209876543209876543208888888888888888888889 = " << test_ans << endl;

    number_second = BigInteger("0");

    ++number_second;
    test_ans = number_second;
    cout << "test 12 '++number' expect 1 = " << test_ans << endl;

    number_second = BigInteger("0");

    number_second++;
    test_ans = number_second;
    cout << "test 13 'number++' expect 1 = " << test_ans << endl;

    number_second = BigInteger("0");

    --number_second;
    test_ans = number_second;
    cout << "test 14 '--number' expect -1 = " << test_ans << endl;

    number_second = BigInteger("0");

    number_second--;
    test_ans = number_second;
    cout << "test 15 'number--' expect -1 = " << test_ans << endl;


    BigInteger testInt("123123123123123123123123123123123");
    BigInteger testInt2("12312312312312312312312312312312311111");

    bool ans = testInt != testInt2;

    cout << "test 16 '!=' expect 1 = " << ans << endl;

    testInt = BigInteger("123123123123123123123123123123123");
    testInt2 = BigInteger("123123123123123123123123123123123");

    ans = testInt == testInt2;


    cout << "test 17 '==' expect 1 = " << ans << endl;

    testInt = BigInteger("123123123123123123123123123123123");
    testInt2 = BigInteger("123123123123123123123123123123124");

    ans = testInt >= testInt2;

    cout << "test 18 '>=' expect 0 = " << ans << endl;

    testInt = BigInteger("123123123123123123123123123123123");
    testInt2 = BigInteger("123123123123123123123123123123124");

    ans = testInt <= testInt2;

    cout << "test 18 '<=' expect 1 = " << ans << endl;


    testInt = BigInteger("123123123123123123123123123123123");
    testInt2 = BigInteger("123123123123123123123123123123124");

    BigInteger ansTestInt = testInt - testInt2;

    cout << "test 18 '-' expect -1 = " << ansTestInt << endl;


    testInt = BigInteger("1123123");
    testInt2 = BigInteger("3123121233211233453612423345");

    ansTestInt = testInt2 / testInt;

    cout << "test 19 '/' expect 2780747285213848753531 = " << ansTestInt << endl;


    testInt = BigInteger("1123123");
    testInt2 = BigInteger("3123121233211233453612423345");

    ansTestInt = testInt2 % testInt;

    cout << "test 20 '%' expect 426032 = " << ansTestInt << endl;


    BigInteger cinInteger;

    cout << "input number type of BigInteger = ";
    cin >> cinInteger;

    cout << " test 21 '<<' && '>>' your input number type of BigInteger = " << cinInteger << endl;

}

int main()
{
    AllTests();
    return 0;
}

