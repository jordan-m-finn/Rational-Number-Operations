// Jordan Finn
// COMSC 200-5119

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber
{
public:

	// constructor
	RationalNumber();

	// constructor
	RationalNumber(int, int);

	// display function
	void printRational() const;

	// overloaded assigment operator functions for +, -, *, /, and =
	RationalNumber operator+(const RationalNumber& fraction);
	RationalNumber operator-(const RationalNumber& fraction);
	RationalNumber operator*(const RationalNumber& fraction);
	RationalNumber operator/(const RationalNumber& fraction);
	RationalNumber& operator=(const RationalNumber& fraction);

	// overloaded relational and equality operator functions for <, >, <=, >=, ==, and !=
	bool operator<(const RationalNumber& fraction) const;
	bool operator>(const RationalNumber& fraction) const;
	bool operator<=(const RationalNumber& fraction) const;
	bool operator>=(const RationalNumber& fraction) const;
	bool operator==(const RationalNumber& fraction) const;
	bool operator!=(const RationalNumber& fraction) const;

private:
	int numerator;
	int denominator;

	// fraction simplifier
	void simplifyFraction();
	int greatestCommonDenominator(int x, int y) const;
};

#endif