#include "BigInteger.h"


// переводит вектор int в строку
string createStr(vector<int>& v)
{
	stringstream ss;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i != 0)
			ss << ",";
		ss << v[i];
	}
	string s = ss.str();

	return s;
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
	
	/*value[0] == '-' ? this->isNegative = true : this->isNegative = false;
	this->isNegative ? this->value = value.substr(this->PosStartNegativeNumber) : this->value = value;*/
	this->isNegative = value[0] == '-';
	this->value = value.substr(this->isNegative);

	this->clearLeadingZeros();
	this->checkDigits();
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

	while (this->value[0] == '0' && value.size() - position > 1)
	{
		position++;
	}
	// очистили ведущие нули
	this->value = this->value.substr(position);
}

// проверка на то что значение содержит только цифры
void BigInteger::checkDigits()
{
	for (size_t i = 0; i < this->value.size(); i++)
	{
		if (this->value[i] > '9' || this->value[i] < '0')
		{
			// выкидываем исключение если число состоит не из символов соотв цифрам
			throw string("value of container include INCORRECT characters: ") + this->value;
		}
	}
}


string BigInteger::getValue() const
{
	return this->value;
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


const bool BigInteger::operator ==(const BigInteger &other) const
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

const bool BigInteger::operator!=(const BigInteger &other) const
{
	return !(*this == other);
}

const bool BigInteger::operator < (const BigInteger &other) const
{
	string value2 = other.getValue();
	size_t len1 = this->value.size();
	size_t len2 = other.getValue().size();

	// если знаки совпали, то имеет смысл сравнивать
	if (this->isNegative == other.getIsNegative())
	{
		// меньше число с меньшей длинной для положительных
		// и с большей длиной для отрицательных
		if (this->isNegative)
		{
			return len1 > len2;
		}
		else
		{
			return len1 < len2;
		}

		// найдем разряд в котором разные значения

		size_t pos = 0;
		while (pos < len1 && this->value == value2)
		{
			pos++;
		}

		// если разряд найден, то меньше число с меньшей цифрой для положительных 
		// и с большей цифрой для отрицательных, иначе числа равны
		
		// проверили что разряд вообще принадлежит числу
		if (pos < len1)
		{
			if (this->isNegative)
			{
				return this->value[pos] > value2[pos];
			}
			else
			{
				return this->value[pos] < value2[pos];
			}
		}

	}
	return this->isNegative;
}

const bool BigInteger::operator > (const BigInteger &other) const
{
	return !(*this < other || *this == other);
}

const bool BigInteger::operator<=(const BigInteger &other) const {
	return *this < other || *this == other;
}

const bool BigInteger::operator>=(const BigInteger &other) const {
	return *this > other || *this == other;
}

BigInteger &BigInteger::operator = (const BigInteger &bigInt) {
	this->value = bigInt.getValue();
	this->isNegative = bigInt.getIsNegative();

	return *this;
}


// унарный минус, если было отрицательным, возвращаем положительное, иначе отрицательное
BigInteger BigInteger::operator-() const&& {
	string copy = this->isNegative ? this->value : std::string("-") + this->value;
	BigInteger Current(copy);

	return Current;
}

// унарный плюс (просто копируем значение числа)
BigInteger BigInteger::operator+() const&& {
	BigInteger Current = *this;

	return Current;
}

BigInteger BigInteger::operator+(const BigInteger& other) const
{
	return BigInteger("0");
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
		
		/*string answer = isNegativeResult ? string("-") + createStr(Result) : createStr(Result);
		BigInteger Answer(answer);
		return Answer;*/
		return BigInteger(this->isNegative ? std::string("-") + createStr(Result) : createStr(Result));
	}
	else 
		return this->isNegative && other.getIsNegative() ? (-BigInteger(other) - (-BigInteger(*this))) : (*this + -BigInteger(other));
}

