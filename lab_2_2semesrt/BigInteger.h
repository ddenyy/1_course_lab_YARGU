#pragma once
#include "Header.h"


class BigInteger
{
private:
	short PosStartNegativeNumber = 1;
	string value;
	bool isNegative;
	void clearLeadingZeros();

public:
	BigInteger();
	BigInteger(const string &value);
	BigInteger(int value);
	BigInteger(const BigInteger& other);

	string getValue() const;
	string toString() const;
	bool getIsNegative() const;

	void setIsNegative(bool isNegative);
	void setValue(string value);

	int sign() const;
	BigInteger abs();


	const bool operator == (const BigInteger& other) const;
	const bool operator != (const BigInteger& other) const;
	const bool operator < (const BigInteger& other) const;
	const bool operator > (const BigInteger& other) const;
	const bool operator <= (const BigInteger& other) const;
	const bool operator >= (const BigInteger& other) const;
	BigInteger &operator = (const BigInteger& other);

	BigInteger operator - () const&&;
	BigInteger operator + () const&&;
	BigInteger operator++(int);
	BigInteger& operator++();
	BigInteger& operator--();
	BigInteger operator--(int);

	explicit operator bool() const;

	BigInteger operator + (const BigInteger& other) const;
	BigInteger operator - (const BigInteger &other) const;
	BigInteger operator / (const BigInteger& other) const;
	BigInteger& operator -= (const BigInteger& other);
	BigInteger operator % (const BigInteger& other) const;
	BigInteger operator * (const BigInteger& bigInt) const;
	friend ostream& operator<<(std::ostream& stream, const BigInteger& bigInt);
	friend istream& operator>>(std::istream& stream, BigInteger& bigInt);

};
