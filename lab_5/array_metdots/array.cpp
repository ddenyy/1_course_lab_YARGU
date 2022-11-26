#include "array.h"
#include <string>
using namespace std;
/*
ф-ция заполняет частотый массив
принимает ссылку на массив частотных символов, текст и алфавит

*/
void fill_rate_array(int* Array_rate, string text, string alphabet) {
	// заполняем частотный массив
	for (int j = 0; j < text.size(); j++) {
		if (alphabet.find(text[j]) != -1) {
			Array_rate[alphabet.find(text[j])] += 1;
		}
	}
}

/*
ф-ция создает частотный массив
*/
void create_rate_array(int* Array_rate, int size_alphabet, string text, string alphabet) {
	// зануляем массив
	for (int i = 0; i < size_alphabet; i++) {
		Array_rate[i] = 0;
	}
	fill_rate_array(Array_rate, text, alphabet);
}

/*
ф-ция находит индекс максимального элемента
*/
int find_index_max(int* Array, int size) {
	int max_ind = 0;
	int max_value = 0;
	for (int i = 0; i < size; i++) {
		if (Array[i] > max_value) {
			max_value = Array[i];
			max_ind = i;
		}
	}
	return max_ind;
}