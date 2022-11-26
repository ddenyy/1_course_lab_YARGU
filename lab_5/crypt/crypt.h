#ifndef CRYPT_H
#define CRYPT_H
#include <string>
using namespace std;

/*
ф-ция трансформирует алфавит по условию шифровки
принимает алфавит и секретное слово
*/
string transform_alphabet(string alphabet, string word);

/*
ф-ция ДЕшифровки строки. принимает текст, изначальный и видоизменённый алфавит
возвращает текст
*/
string uncrypt_string(string text, string alphabet, string encrytped_alphabet);


/*
ф-ция шифровки строки. принимает текст, начальный алфавит и видоизменённый алфавит
возвращает текст
*/
string encrytped_string(string text, string alphabet, string encrytped_alphabet);

#endif // CRYPT_H
