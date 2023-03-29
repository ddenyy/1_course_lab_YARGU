#include "BigInteger.h"


// ��������� ������ int � ������
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

// ����������� �� ���������
BigInteger::BigInteger()
{
	this->isNegative = false;
	this->value = "0";
}

// ����������� �� �����
BigInteger::BigInteger(int value)
{
	// �������� ��� ����� �������������
	value < 0 ? this->isNegative = true : this->isNegative = false;
	
	// ��������� �������� ����� � ���� ������
	this->value = to_string(this->isNegative ? -value : value);
}

// ����������� �� ������
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

// ����������� �����������
BigInteger::BigInteger(const BigInteger &other)
{
	this->value = other.getValue();
	this->isNegative = other.getIsNegative();
}



// �-��� �������� ������� �����
void BigInteger::clearLeadingZeros()
{
	int position = 0;

	while (this->value[0] == '0' && value.size() - position > 1)
	{
		position++;
	}
	// �������� ������� ����
	this->value = this->value.substr(position);
}

// �������� �� �� ��� �������� �������� ������ �����
void BigInteger::checkDigits()
{
	for (size_t i = 0; i < this->value.size(); i++)
	{
		if (this->value[i] > '9' || this->value[i] < '0')
		{
			// ���������� ���������� ���� ����� ������� �� �� �������� ����� ������
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


// ��������� ����� �����
int BigInteger::sign() const {
	return (1 - 2 * this->isNegative) * (this->value != "0");
}

// ������ �����
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

	// ���� ����� �������, �� ����� ����� ����������
	if (this->isNegative == other.getIsNegative())
	{
		// ������ ����� � ������� ������� ��� �������������
		// � � ������� ������ ��� �������������
		if (this->isNegative)
		{
			return len1 > len2;
		}
		else
		{
			return len1 < len2;
		}

		// ������ ������ � ������� ������ ��������

		size_t pos = 0;
		while (pos < len1 && this->value == value2)
		{
			pos++;
		}

		// ���� ������ ������, �� ������ ����� � ������� ������ ��� ������������� 
		// � � ������� ������ ��� �������������, ����� ����� �����
		
		// ��������� ��� ������ ������ ����������� �����
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


// ������� �����, ���� ���� �������������, ���������� �������������, ����� �������������
BigInteger BigInteger::operator-() const&& {
	string copy = this->isNegative ? this->value : std::string("-") + this->value;
	BigInteger Current(copy);

	return Current;
}

// ������� ���� (������ �������� �������� �����)
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
	// ������ ��������� �����
	if (*this == other)
	{
		return 0;
	}

	if (!this->isNegative && !other.getIsNegative())
	{
		// �������� ������� �����
		string value2 = other.getValue();
		// ������ ������� � ������� �����
		size_t len1 = this->value.size();
		size_t len2 = value2.size();
		// ������ ����������
		size_t lenght = max(len1, len2);
		// ���� ����������
		bool isNegativeResult = other > *this;

		// ��������� ��������� ������������� ����� � �����
		vector<int> A(lenght), B(lenght);
		vector<int> Result(lenght + 1);
		A[0] = B[0] = 0;
		Result[lenght] = Result[lenght - 1] = '\0';

		// ���� ����������
		int sign = (2 * isNegativeResult) - 1;

		for (size_t i = 0; i < lenght - 1; i++) {
			A[i] += (i < len1) ? (value[len1 - 1 - i] - '0') : 0; // ��������� �������
			B[i] += (i < len2) ? (value2[len2 - 1 - i] - '0') : 0; // �� ����� ����������

			B[i + 1] = -isNegativeResult; // � ����������� �� ����� �������� ��� �� ��������
			A[i + 1] = isNegativeResult - 1; // 10 � ���������� �������

			Result[lenght - 1 - i] += 10 + sign * (B[i] - A[i]);
			Result[lenght - 1 - i - 1] = Result[lenght - 1 - i] / 10;
			Result[lenght - 1 - i] = Result[lenght - 1 - i] % 10 + '0';
		}

		// ��������� �������� � ��������� ��������
		A[lenght - 1] += (lenght - 1 < len1) * (value[0] - '0');
		B[lenght - 1] += (lenght - 1 < len2) * (value2[0] - '0');

		// ���������� � ������ ��������� ������
		Result[0] += sign * (B[lenght - 1] - A[lenght - 1]) + '0';
		
		/*string answer = isNegativeResult ? string("-") + createStr(Result) : createStr(Result);
		BigInteger Answer(answer);
		return Answer;*/
		return BigInteger(this->isNegative ? std::string("-") + createStr(Result) : createStr(Result));
	}
	else 
		return this->isNegative && other.getIsNegative() ? (-BigInteger(other) - (-BigInteger(*this))) : (*this + -BigInteger(other));
}

