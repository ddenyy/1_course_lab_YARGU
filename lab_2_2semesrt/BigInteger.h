#pragma once
#include "Header.h"


class BigInteger
{
private:
	short PosStartNegativeNumber = 1;
	string value;
	bool isNegative;
	void clearLeadingZeros();
	void checkDigits();

public:
	BigInteger();
	BigInteger(const string &value);
	BigInteger(int value);
	BigInteger(const BigInteger& other);

	string getValue() const;
	bool getIsNegative() const;

	void setIsNegative(bool isNegative);
	void setValue(string value);

	int sign() const;
	BigInteger abs();


	const bool operator==(const BigInteger& other) const;
	const bool operator!=(const BigInteger& other) const;
	const bool operator<(const BigInteger& other) const;
	const bool operator>(const BigInteger& other) const;
	const bool operator<=(const BigInteger& other) const;
	const bool operator>=(const BigInteger& other) const;
	BigInteger &operator=(const BigInteger& other);

	BigInteger operator-() const&&;
	BigInteger operator+() const&&;
	BigInteger& operator++();

	BigInteger operator+(const BigInteger& other) const;
	BigInteger operator - (const BigInteger &other) const;
	BigInteger operator/(const BigInteger& other) const;
	BigInteger& operator-=(const BigInteger& other);
	BigInteger operator%(const BigInteger& bigInt) const;
};