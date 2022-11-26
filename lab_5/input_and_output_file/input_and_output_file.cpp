#include "input_and_output_file.h"
#include "../array_metdots/array.h"

/*
ф-ци€ чтени€ файла
*/
string read_file(string path) {
	ifstream file_in;
	file_in.open(path);

	if (!file_in.is_open())
	{
		cout << "файл не прочитал";
		return "0";
	}
	string all_text = "";
	string section_text;
	while (!file_in.eof()) {
		getline(file_in, section_text);
		all_text += section_text;
	}
	file_in.close();
	return all_text;
}

/*
ф-ци€ вывода строки в файл
создает файл с именем name_file
записывает в файл text
*/
void output_in_file(string name_file, string text) {
	ofstream output_file;
	output_file.open(name_file);
	output_file << text;
	output_file.close();
}


/*
ф-ци€ ввода секретного слова
*/
string input_secret_string() {
	string secret_string;
	cout << "¬ведите секретное слово Ѕ≈« ѕќ¬“ќ–яёў»’—я Ѕ” ¬ = ";
	cin >> secret_string;
	return secret_string;
}


/*
выводит 5 самых частых символов встречающихс€ в тексте
принимает ссылку на частотный массив, размер частотного массива, алфавит
*/
void output_five_most_rate_symbols(int* Array, int size_array, string Array_alphabet) {
	for (int i = 0; i < size_array; i++) {
		cout << Array[i] << " == " << Array_alphabet[i] << '\n';
	}
	cout << "== 5 maximum elements ==" << '\n';
	for (int i = 0; i < 5; i++) {
		//максимальный индекс
		cout << '|';
		int max_index = find_index_max(Array, size_array);
		cout << Array_alphabet[max_index] << ' ';
		Array[max_index] = -1;
	}
	cout << '|';
}

