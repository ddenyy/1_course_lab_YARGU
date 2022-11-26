// лабораторная работа номер 5. студента групппы пми-13БО Осипова Дениса
// вариант номер 8 и 1 соответственно

#include "crypt/crypt.h"
#include "input_and_output_file/input_and_output_file.h"
#include "array_metdots/array.h"
#include <fstream>
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;


int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	string path = "input.txt";
	string ordinary_text = read_file(path);
	string secret_string = input_secret_string();
	string Array_alphabet = "абвгдежзийклмнопрстуфхцчшщъыьэюя";
	string Array_encrypted_alphabet = transform_alphabet(Array_alphabet, secret_string);
	string encrypted_text = encrytped_string(ordinary_text, Array_alphabet, Array_encrypted_alphabet);
	
	string uncrypt_encrypted_text = uncrypt_string(encrypted_text, Array_alphabet, Array_encrypted_alphabet);
	output_in_file("osipov.txt", uncrypt_encrypted_text);
	output_in_file("osipovCrypt.txt", encrypted_text);


	// 32 т.к в алфавите всего 32 буквы
	const int size_rate = 73;
	string Array_alphabet_all_symbols = "абвгдежзийклмнопрстуфхцчшщъыьэюя ,.;!?':—АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	cout << Array_alphabet_all_symbols.size();
	int* Array_rate = new int[size_rate];
	create_rate_array(Array_rate, size_rate, ordinary_text, Array_alphabet_all_symbols);
	output_five_most_rate_symbols(Array_rate, size_rate, Array_alphabet_all_symbols);
	delete[] Array_rate;
}

