#include "BigInteger.h"


// переводит вектор int в строку
string createStr(vector<int>& v)
{
	string s = "";
	for (size_t i = 0; i < v.size(); i++)
	{
		s.push_back((char)v[i]);
	}
	return s;
}


BigInteger::operator bool() const
{
	if (this->getIsNegative() || this->getValue().size() == 0 || this->getValue() == "0")
	{
		return false;
	} 
	else
	{
		return true;
	}
}

// конструктор по умолчанию
BigInteger::BigInteger()
{
	this->isNegative = false;
	this->value = "0";
}

// конструктор из числа
BigInteger::BigInteger(int value)
{
	// проверка что число отрицательное
	value < 0 ? this->isNegative = true : this->isNegative = false;
	
	// установка значения числа в виде строки
	this->value = to_string(this->isNegative ? -value : value);
}

// конструктор из строки
BigInteger::BigInteger(const string &value)
{
	if (value.size() == 0) 
	{
		this->isNegative = false;
		this->value = "0";
		return;
	}
	
	this->isNegative = value[0] == '-';
	this->value = value.substr(this->isNegative);

	this->clearLeadingZeros();
}

// конструктор копирования
BigInteger::BigInteger(const BigInteger &other)
{
	this->value = other.getValue();
	this->isNegative = other.getIsNegative();
}

// ф-ция удаления ведущих нулей
void BigInteger::clearLeadingZeros()
{
	int position = 0;

	while (this->value[position] == '0' && value.size() - position > 1)
	{
		position++;
	}
	// очистили ведущие нули
	this->value = this->value.substr(position);
}

string BigInteger::getValue() const
{
	return this->value;
}
string BigInteger::toString() const
{
	string ans = this->getIsNegative() ? "-" + this->getValue() : this->getValue();
	return ans;
}

bool BigInteger::getIsNegative() const
{
	return this->isNegative;
}

void BigInteger::setIsNegative(bool isNegative)
{
	this->isNegative = isNegative;
}

void BigInteger::setValue(string value)
{
	this->value = value;
}


// получение знака числа
int BigInteger::sign() const {
	return (1 - 2 * this->isNegative) * (this->value != "0");
}

// модуль числа
BigInteger BigInteger::abs()
{
	BigInteger AbsInt(this->value);
	return AbsInt;
}


const bool BigInteger::operator == (const BigInteger &other) const
{
	if ((this->value == other.getValue()) && (this->isNegative == other.getIsNegative()))
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool BigInteger::operator != (const BigInteger &other) const
{
	return !(*this == other);
}

const bool BigInteger::operator < (const BigInteger &other) const
{
	string value2 = other.getValue(); // значение второго числа
	size_t len1 = value.length(); // длину первого числа
	size_t len2 = value2.length(); // длину второго числа

	// если знаки одинаковые, то проверяем значения
	if (isNegative == other.getIsNegative()) {
		if (len1 != len2)
		{
			if (this->getIsNegative())
			{
				// число отрицательное, больше то, которое по длинне меньше
				if (len1 < len2)
				{
					return false;
				}
				else {
					return true;
				}
			}
			else {
				if (len1 < len2)
				{
					return true;
				}
				else
				{
					return false;
				}
				
			}

			//return (len1 < len2) ^ isNegative; // меньше число с меньшей длинной для положительных и с большей длиной для отрицательных
		}

		size_t i = 0;

		// ищем разряд, в котором значения отличаются
		while (i < len1 && value[i] == value2[i])
			i++;

		// если разряд найден, то меньше число с меньшей цифрой для положительных и с большей цифрой для отрицательных, иначе числа равны
		if (i < len1)
		{
			if (this->getIsNegative())
			{
				return value[i] > value2[i];
			}
			else
			{
				return value[i] < value2[i];
			}
		}
		else
		{
			return false;
		}/*
		return (i < len1) && ((value[i] < value2[i]) ^ isNegative);*/
	}

	return isNegative; // знаки разные, если число отрицательное, то оно меньше, если положительное, то больше
}

const bool BigInteger::operator > (const BigInteger &other) const
{
	return !(*this < other || *this == other);
}

const bool BigInteger::operator <= (const BigInteger &other) const {
	return *this < other || *this == other;
}

const bool BigInteger::operator >= (const BigInteger &other) const {
	return *this > other || *this == other;
}

BigInteger &BigInteger::operator = (const BigInteger & other) {
	this->value = other.getValue();
	this->isNegative = other.getIsNegative();
	return *this;
}


// унарный минус, если было отрицательным, возвращаем положительное, иначе отрицательное
BigInteger BigInteger::operator - () const && {
	string copy = this->isNegative ? this->value : string("-") + this->value;
	BigInteger Current(copy);
	return Current;
}

// унарный плюс (просто копируем значение числа)
BigInteger BigInteger::operator + () const&& {
	BigInteger Current = *this;
	return Current;
}

// инкремент (просто копируем значение числа)
BigInteger BigInteger::operator++(int) {
	BigInteger res = *this;
	*this = *this + BigInteger(1);
	return res;
}

// префиксная запись инкремента
BigInteger& BigInteger::operator++() {
	return *this = *this + 1;
}


BigInteger& BigInteger::operator--() {
	return *this = *this - 1;
}

// постфиксная запись декремента
BigInteger BigInteger::operator--(int) {
	BigInteger res = *this;
	*this = *this - BigInteger(1);
	return res;
}




BigInteger BigInteger::operator+(const BigInteger& other) const {
	//bool isAddOp = !(other.getIsNegative() ^ this->getIsNegative()); // если знаки одинаковые, то выполняем сложение
	bool isAddOp = other.getIsNegative() == this->getIsNegative(); // если знаки одинаковые, то выполняем сложение

	if (isAddOp) {
		string num2 = other.getValue(); // значение второго числа

		size_t len1 = this->value.size(); // длину первого числа
		size_t len2 = num2.size(); // длину второго числа
		size_t length = 1 + max(len1, len2);  // длина суммы + 1 из-за возможного переноса разряда

		string res = "0";// строковый массив для выполнения операции сложения
		res.resize(length + 1);

		res[length - 1] = res[length] = '\0';

		for (size_t i = 0; i < length - 1; i++) {
			int j = length - 1 - i;
			res[j] += ((i < len2) ? (num2[len2 - 1 - i] - '0') : 0) + ((i < len1) ? (value[len1 - 1 - i] - '0') : 0); // выполняем сложение разрядов
			res[j - 1] = res[j] / 10; // выполняем перенос в следущий разряд, если он был
			res[j] = res[j] % 10 + '0'; // оставляем только единицы от возможного переноса и превращаем символ в цифру
		}

		this->getIsNegative() ? res = string("-") + res :res = res;
		return BigInteger(res); // возвращаем результат, в зависимости от знака`
	}
	else
		return this->getIsNegative() ? (other - (-BigInteger(*this))) : (*this - (-BigInteger(other))); // одно из чисел отрицательное, а другое положительное, отправляем на вычитание, меняя знак
}

BigInteger BigInteger::operator-(const BigInteger &other) const
{
	// случай равенства чисел
	if (*this == other)
	{
		return 0;
	}

	if (!this->isNegative && !other.getIsNegative())
	{
		// значения второго числа
		string value2 = other.getValue();
		// длинны первого и второго числа
		size_t len1 = this->value.size();
		size_t len2 = value2.size();
		// длинна результата
		size_t lenght = max(len1, len2);
		// знак результата
		bool isNegativeResult = other > *this;

		// переведем строковое представление чисел в числа
		vector<int> A(lenght), B(lenght);
		vector<int> Result(lenght + 1);
		A[0] = B[0] = 0;
		Result[lenght] = Result[lenght - 1] = '\0';

		// знак результата
		int sign = (2 * isNegativeResult) - 1;

		for (size_t i = 0; i < lenght - 1; i++) {
			A[i] += (i < len1) ? (value[len1 - 1 - i] - '0') : 0; // формируем разряды
			B[i] += (i < len2) ? (value2[len2 - 1 - i] - '0') : 0; // из строк аргументов

			B[i + 1] = -isNegativeResult; // в зависимости от знака занимаем или не занимаем
			A[i + 1] = isNegativeResult - 1; // 10 у следующего разряда

			Result[lenght - 1 - i] += 10 + sign * (B[i] - A[i]);
			Result[lenght - 1 - i - 1] = Result[lenght - 1 - i] / 10;
			Result[lenght - 1 - i] = Result[lenght - 1 - i] % 10 + '0';
		}

		// выполняем операцию с последним разрядом
		A[lenght - 1] += (lenght - 1 < len1) * (value[0] - '0');
		B[lenght - 1] += (lenght - 1 < len2) * (value2[0] - '0');

		// записываем в строку последний разряд
		Result[0] += sign * (B[lenght - 1] - A[lenght - 1]) + '0';
		
		string answer = isNegativeResult ? string("-") + createStr(Result) : createStr(Result);
		return BigInteger(answer);
	}
	else 
		return this->isNegative && other.getIsNegative() ? (-BigInteger(other) - (-BigInteger(*this))) : (*this + -BigInteger(other));
}



// краткая запись вычитания
BigInteger& BigInteger::operator-=(const BigInteger& other) {
	return *this = *this - other;
}



// бинарный слеш (деление двух чисел)
BigInteger BigInteger::operator/(const BigInteger& other) const {
	string value1 = value;
	string value2 = other.getValue(); // запоминаем значение второго числа

	if (value2[0] == '0')
		throw string("Division by zero!"); // нельзя делить на ноль, этому ещё в школе учат

	if (value[0] == '0')
		return 0; // а вот ноль делить можно на всё, кроме нуля, но смысл?

	if (value2 == "1")
		return BigInteger(other.getIsNegative() ? -BigInteger(*this) : *this); // делить на 1 можно, но смысл?

	size_t zeroes = 0;
	while (value2[value2.length() - 1 - zeroes] == '0')
		zeroes++;

	if (zeroes >= value.length())
		return 0;

	// избавляемся от круглых чисел
	if (zeroes) {
		value1 = value1.substr(0, value1.length() - zeroes);
		value2 = value2.substr(0, value2.length() - zeroes);
	}

	bool isNegRes = this->getIsNegative() ^ other.getIsNegative(); // считаем знак числа

	BigInteger tmp(value2);

	size_t divider_length = value2.length(); // запоминаем длину делителя
	long divider_v = divider_length > 8 ? 0 : atol(value2.c_str()); // если длина больше 8, то обнуляем long'овый делитель, иначе переводим строку в long

	size_t length = value1.length(); // получаем длину делимого
	size_t index = 0; // стартуем с нулевого индекса

	string div; // строка результата деления
	string tmp_num; // строка подчисла (которое делится на делитель в столбик)

	// формируем начальное число для деления
	while (BigInteger(tmp_num) < tmp && index < length)
		tmp_num += value1[index++];

	do {
		int count = 0; // результат деления подчисла на делитель

		// если можем разделить, то делим
		if (BigInteger(tmp_num) >= tmp) {
			if (divider_length > 8) { // если не входит в long, то делим с помощью вычитания
				BigInteger mod = tmp_num;

				while (mod >= tmp) {
					mod -= tmp;
					count++;
				}

				tmp_num = mod.getValue();
			}
			else {
				long mod = stol(tmp_num);
				count = mod / divider_v;
				tmp_num = to_string(mod % divider_v);
			}
		}

		div += count + '0'; // если не делили, то добавили ноль к результату, иначе добавили результат деления

		if (index <= length)
			tmp_num += value1[index++]; // формируем новое значение для подчисла
	} while (index <= length);

	return BigInteger(isNegRes && div != "0" ? string("-") + div : div); // возвращаем результат учитывая знак и возможное равенство нулю
}



// бинарный процент (операция взятия остатка от деления)
BigInteger BigInteger::operator%(const BigInteger& other) const {
	string value2 = other.getValue();
	string value = this->getValue();

	if (value2[0] == '0')
		throw string("Division by zero!");

	if (value[0] == '0' || value2 == "1")
		return 0;

	if (value.length() < 9 && value2.length() < 9) {
		long res = stol(value) % stol(value2);
		return this->getIsNegative() ? -res : res;
	}

	BigInteger tmp(value2);

	size_t divider_length = value2.length(); // запоминаем длину делителя
	long divider_v = divider_length >= 9 ? 0 : atol(value2.c_str()); // если длина больше 8, то обнуляем long'овый делитель, иначе переводим строку в long

	size_t length = value.length();
	size_t index = 0;
	BigInteger mod2 = value;
	string tmp_num;

	while (BigInteger(tmp_num) < tmp && index < length)
		tmp_num += value[index++];

	do {
		if (BigInteger(tmp_num) >= tmp) {
			if (divider_v)
				tmp_num = to_string(stol(tmp_num) % divider_v);
			else {
				BigInteger mod = tmp_num;

				while (mod >= tmp)
					mod -= tmp;

				tmp_num = mod.getValue();
			}
		}

		if (index <= length) {
			mod2 = tmp_num;
			tmp_num += value[index++];
		}
	} while (index <= length);

	if (mod2.getValue() == "0")
		return 0;

	return this->getIsNegative() ? -BigInteger(mod2) : mod2;
}




 
BigInteger BigInteger::operator * (const BigInteger& other) const
{
	if (value == "0" || other.getValue() == "0")
		return 0; // если один из множителей равен нулю, то результат равен нулю

	string value2 = other.getValue(); // запоминаем значение второго числа

	size_t len1 = value.length(); // запоминаем длину первого числа
	size_t len2 = value2.length(); // запоминаем длину второго числа
	size_t length = len1 + len2 + 1; // резульат влезет в сумму длин + 1 из-за возможного переноса
	bool isNegRes = this->getIsNegative() ^ other.getIsNegative(); // флаг отрицательности результата - отрицательный, если числа разных знаков

	vector<int> a(length), b(length); // массивы аргументов и результата

	string res = ""; // строковый массив для результата
	res.resize(length + 1); 

	res[length] = '\0'; // устанавливаем символ окончания строки

	// заполняем массивы инверсной записью чисел (с ведущими нулями)
	for (size_t i = 0; i < length; i++) {
		a[i] = (i < len1) ? (value[len1 - 1 - i] - '0') : 0;
		b[i] = (i < len2) ? (value2[len2 - 1 - i] - '0') : 0;
		res[i] = 0;
	}

	// выполняем умножение "в столбик""
	for (size_t i = 0; i < len1; i++) {
		for (size_t j = 0; j < len2; j++) {
			res[length - 1 - (i + j)] += a[i] * b[j];
			res[length - 1 - (i + j + 1)] += res[length - 1 - (i + j)] / 10;
			res[length - 1 - (i + j)] %= 10;
		}
	}

	// переписываем результат в строку
	for (size_t i = 0; i < length; i++)
		res[length - 1 - i] += '0';

	return BigInteger(isNegRes ? string("-") + string(res) : string(res)); // возвращаем результат, учитывая его знак
}

// вывод числа в выходной поток
ostream& operator<<(ostream& stream, const BigInteger& other) {
	if (other.getIsNegative())
		stream << "-";

	return stream << other.getValue();
}

// ввод числа из входного потока
istream& operator>>(istream& stream, BigInteger& other) {
	string value;
	stream >> value;
	other = BigInteger(value);

	return stream;
}