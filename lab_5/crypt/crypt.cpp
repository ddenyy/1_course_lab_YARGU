#include "crypt.h"

/*
ф-ция трансформирует алфавит по условию шифровки
принимает алфавит и секретное слово
*/
string transform_alphabet(string alphabet, string word) {
	for (int i = 0; i < word.size(); i++) {
		int index = alphabet.find(word[i]);
		if (index != -1) {
			alphabet.erase(index, 1);
		}
	}
	return word + alphabet;
}

/*
ф-ция ДЕшифровки строки. принимает текст, изначальный и видоизменённый алфавит
возвращает текст
*/
string uncrypt_string(string text, string alphabet, string encrytped_alphabet) {
	for (int i = 0; i < text.size(); i++) {
		if (encrytped_alphabet.find(text[i]) != -1) {
			text[i] = alphabet[encrytped_alphabet.find(text[i])];
		}
	}
	return text;
}

/*
ф-ция шифровки строки. принимает текст, начальный алфавит и видоизменённый алфавит
возвращает текст
*/
string encrytped_string(string text, string alphabet, string encrytped_alphabet) {
	for (int i = 0; i < text.size(); i++) {
		if (alphabet.find(text[i]) != -1) {
			text[i] = encrytped_alphabet[alphabet.find(text[i])];
		}
	}
	return text;
}
