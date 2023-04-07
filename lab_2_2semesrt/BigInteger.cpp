#include "BigInteger.h"


// ��������� ������ int � ������
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
	
	this->isNegative = value[0] == '-';
	this->value = value.substr(this->isNegative);

	this->clearLeadingZeros();
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

	while (this->value[position] == '0' && value.size() - position > 1)
	{
		position++;
	}
	// �������� ������� ����
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
	string value2 = other.getValue(); // �������� ������� �����
	size_t len1 = value.length(); // ����� ������� �����
	size_t len2 = value2.length(); // ����� ������� �����

	// ���� ����� ����������, �� ��������� ��������
	if (isNegative == other.getIsNegative()) {
		if (len1 != len2)
		{
			if (this->getIsNegative())
			{
				// ����� �������������, ������ ��, ������� �� ������ ������
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

			//return (len1 < len2) ^ isNegative; // ������ ����� � ������� ������� ��� ������������� � � ������� ������ ��� �������������
		}

		size_t i = 0;

		// ���� ������, � ������� �������� ����������
		while (i < len1 && value[i] == value2[i])
			i++;

		// ���� ������ ������, �� ������ ����� � ������� ������ ��� ������������� � � ������� ������ ��� �������������, ����� ����� �����
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

	return isNegative; // ����� ������, ���� ����� �������������, �� ��� ������, ���� �������������, �� ������
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


// ������� �����, ���� ���� �������������, ���������� �������������, ����� �������������
BigInteger BigInteger::operator - () const && {
	string copy = this->isNegative ? this->value : string("-") + this->value;
	BigInteger Current(copy);
	return Current;
}

// ������� ���� (������ �������� �������� �����)
BigInteger BigInteger::operator + () const&& {
	BigInteger Current = *this;
	return Current;
}

// ��������� (������ �������� �������� �����)
BigInteger BigInteger::operator++(int) {
	BigInteger res = *this;
	*this = *this + BigInteger(1);
	return res;
}

// ���������� ������ ����������
BigInteger& BigInteger::operator++() {
	return *this = *this + 1;
}


BigInteger& BigInteger::operator--() {
	return *this = *this - 1;
}

// ����������� ������ ����������
BigInteger BigInteger::operator--(int) {
	BigInteger res = *this;
	*this = *this - BigInteger(1);
	return res;
}




BigInteger BigInteger::operator+(const BigInteger& other) const {
	//bool isAddOp = !(other.getIsNegative() ^ this->getIsNegative()); // ���� ����� ����������, �� ��������� ��������
	bool isAddOp = other.getIsNegative() == this->getIsNegative(); // ���� ����� ����������, �� ��������� ��������

	if (isAddOp) {
		string num2 = other.getValue(); // �������� ������� �����

		size_t len1 = this->value.size(); // ����� ������� �����
		size_t len2 = num2.size(); // ����� ������� �����
		size_t length = 1 + max(len1, len2);  // ����� ����� + 1 ��-�� ���������� �������� �������

		string res = "0";// ��������� ������ ��� ���������� �������� ��������
		res.resize(length + 1);

		res[length - 1] = res[length] = '\0';

		for (size_t i = 0; i < length - 1; i++) {
			int j = length - 1 - i;
			res[j] += ((i < len2) ? (num2[len2 - 1 - i] - '0') : 0) + ((i < len1) ? (value[len1 - 1 - i] - '0') : 0); // ��������� �������� ��������
			res[j - 1] = res[j] / 10; // ��������� ������� � �������� ������, ���� �� ���
			res[j] = res[j] % 10 + '0'; // ��������� ������ ������� �� ���������� �������� � ���������� ������ � �����
		}

		this->getIsNegative() ? res = string("-") + res :res = res;
		return BigInteger(res); // ���������� ���������, � ����������� �� �����`
	}
	else
		return this->getIsNegative() ? (other - (-BigInteger(*this))) : (*this - (-BigInteger(other))); // ���� �� ����� �������������, � ������ �������������, ���������� �� ���������, ����� ����
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
		
		string answer = isNegativeResult ? string("-") + createStr(Result) : createStr(Result);
		return BigInteger(answer);
	}
	else 
		return this->isNegative && other.getIsNegative() ? (-BigInteger(other) - (-BigInteger(*this))) : (*this + -BigInteger(other));
}



// ������� ������ ���������
BigInteger& BigInteger::operator-=(const BigInteger& other) {
	return *this = *this - other;
}



// �������� ���� (������� ���� �����)
BigInteger BigInteger::operator/(const BigInteger& other) const {
	string value1 = value;
	string value2 = other.getValue(); // ���������� �������� ������� �����

	if (value2[0] == '0')
		throw string("Division by zero!"); // ������ ������ �� ����, ����� ��� � ����� ����

	if (value[0] == '0')
		return 0; // � ��� ���� ������ ����� �� ��, ����� ����, �� �����?

	if (value2 == "1")
		return BigInteger(other.getIsNegative() ? -BigInteger(*this) : *this); // ������ �� 1 �����, �� �����?

	size_t zeroes = 0;
	while (value2[value2.length() - 1 - zeroes] == '0')
		zeroes++;

	if (zeroes >= value.length())
		return 0;

	// ����������� �� ������� �����
	if (zeroes) {
		value1 = value1.substr(0, value1.length() - zeroes);
		value2 = value2.substr(0, value2.length() - zeroes);
	}

	bool isNegRes = this->getIsNegative() ^ other.getIsNegative(); // ������� ���� �����

	BigInteger tmp(value2);

	size_t divider_length = value2.length(); // ���������� ����� ��������
	long divider_v = divider_length > 8 ? 0 : atol(value2.c_str()); // ���� ����� ������ 8, �� �������� long'���� ��������, ����� ��������� ������ � long

	size_t length = value1.length(); // �������� ����� ��������
	size_t index = 0; // �������� � �������� �������

	string div; // ������ ���������� �������
	string tmp_num; // ������ �������� (������� ������� �� �������� � �������)

	// ��������� ��������� ����� ��� �������
	while (BigInteger(tmp_num) < tmp && index < length)
		tmp_num += value1[index++];

	do {
		int count = 0; // ��������� ������� �������� �� ��������

		// ���� ����� ���������, �� �����
		if (BigInteger(tmp_num) >= tmp) {
			if (divider_length > 8) { // ���� �� ������ � long, �� ����� � ������� ���������
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

		div += count + '0'; // ���� �� ������, �� �������� ���� � ����������, ����� �������� ��������� �������

		if (index <= length)
			tmp_num += value1[index++]; // ��������� ����� �������� ��� ��������
	} while (index <= length);

	return BigInteger(isNegRes && div != "0" ? string("-") + div : div); // ���������� ��������� �������� ���� � ��������� ��������� ����
}



// �������� ������� (�������� ������ ������� �� �������)
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

	size_t divider_length = value2.length(); // ���������� ����� ��������
	long divider_v = divider_length >= 9 ? 0 : atol(value2.c_str()); // ���� ����� ������ 8, �� �������� long'���� ��������, ����� ��������� ������ � long

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
		return 0; // ���� ���� �� ���������� ����� ����, �� ��������� ����� ����

	string value2 = other.getValue(); // ���������� �������� ������� �����

	size_t len1 = value.length(); // ���������� ����� ������� �����
	size_t len2 = value2.length(); // ���������� ����� ������� �����
	size_t length = len1 + len2 + 1; // �������� ������ � ����� ���� + 1 ��-�� ���������� ��������
	bool isNegRes = this->getIsNegative() ^ other.getIsNegative(); // ���� ��������������� ���������� - �������������, ���� ����� ������ ������

	vector<int> a(length), b(length); // ������� ���������� � ����������

	string res = ""; // ��������� ������ ��� ����������
	res.resize(length + 1); 

	res[length] = '\0'; // ������������� ������ ��������� ������

	// ��������� ������� ��������� ������� ����� (� �������� ������)
	for (size_t i = 0; i < length; i++) {
		a[i] = (i < len1) ? (value[len1 - 1 - i] - '0') : 0;
		b[i] = (i < len2) ? (value2[len2 - 1 - i] - '0') : 0;
		res[i] = 0;
	}

	// ��������� ��������� "� �������""
	for (size_t i = 0; i < len1; i++) {
		for (size_t j = 0; j < len2; j++) {
			res[length - 1 - (i + j)] += a[i] * b[j];
			res[length - 1 - (i + j + 1)] += res[length - 1 - (i + j)] / 10;
			res[length - 1 - (i + j)] %= 10;
		}
	}

	// ������������ ��������� � ������
	for (size_t i = 0; i < length; i++)
		res[length - 1 - i] += '0';

	return BigInteger(isNegRes ? string("-") + string(res) : string(res)); // ���������� ���������, �������� ��� ����
}

// ����� ����� � �������� �����
ostream& operator<<(ostream& stream, const BigInteger& other) {
	if (other.getIsNegative())
		stream << "-";

	return stream << other.getValue();
}

// ���� ����� �� �������� ������
istream& operator>>(istream& stream, BigInteger& other) {
	string value;
	stream >> value;
	other = BigInteger(value);

	return stream;
}