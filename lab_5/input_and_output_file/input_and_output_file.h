#ifndef INPUT_AND_OUTPUT_FILE_H
#define INPUT_AND_OUTPUT_FILE_H
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;

/*
ф-ция чтения файла
*/
string read_file(string path);

/*
ф-ция вывода строки в файл
создает файл с именем name_file
записывает в файл text
*/
void output_in_file(string name_file, string text);

/*
ф-ция ввода секретного слова
*/
string input_secret_string();

/*
выводит 5 самых частых символов встречающихся в тексте
принимает ссылку на частотный массив, размер частотного массива, алфавит
*/
void output_five_most_rate_symbols(int* Array, int size_array, string Array_alphabet);

#endif // INPUT_AND_OUTPUT_FILE_H
