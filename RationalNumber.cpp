// Jordan Finn
// COMSC 200-5119

#include "RationalNumber.h"

#include <iostream>
#include <cmath>

// Comment 1:
// This constructor's sole purpose is to initialize an empty fraction (RationalNumber object) to later 
// be replaced by the algebraic result of two other fractions (RationalNumber objects).
RationalNumber::RationalNumber() : numerator(0), denominator(1) {}

// Comment 2:
// This constructor takes in two integers (a numerator and denominator) as parameters
// and first, checks to see if the denominator is zero. Second, if the denominator is not zero
// it then checks to see if the denominator is negative. Lastly, If the denominator is neither 
// negative or zero, then the RationalNumber object can be initialized by the provided argument values.
// The simplifyFraction member function is then called.
RationalNumber::RationalNumber(int n, int d)
{

	if (d == 0)
	{
		throw std::invalid_argument("Denominator cannot be zero");
	}
	
	if (d < 0)
	{
		n = -n;
		d = -d;
	}

	numerator = n;
	denominator = d;

	simplifyFraction();
}

// Comment 3:
// The purpose of this member function is to simplify the fraction. It does
// this by calling the member function, greatestCommonDenominator, and saving
// value returned from that function. That value is then used to adjust the
// RationalNumber's numerator and denominator values.
void RationalNumber::simplifyFraction()
{
	int commonDenominator = greatestCommonDenominator(numerator, denominator);
	numerator /= commonDenominator;
	denominator /= commonDenominator;
}

// Comment 4:
// The purpose of this member function is to find the greatest common denominator
// of the RationalNumber object.
int RationalNumber::greatestCommonDenominator(int x, int y) const
{
	if (y == 0)
	{
		return x;
	}
	return greatestCommonDenominator(y, x % y);
}

// Comment 5:
// This member function simply displays the numerator and denominator values in fraction form.
void RationalNumber::printRational() const
{
	std::cout << numerator << "/" << denominator;
}

// Comment 6:
// This function overloads the assignment operator (+) to add RationalNumber objects.
RationalNumber RationalNumber::operator+(const RationalNumber& fraction) 
{
	return RationalNumber(numerator * fraction.denominator + fraction.numerator * denominator, denominator * fraction.denominator);
}

// Comment 7:
// This function overloads the assignment operator (-) to subtract RationalNumber objects.
RationalNumber RationalNumber::operator-(const RationalNumber& fraction)
{
	return RationalNumber(numerator * fraction.denominator - fraction.numerator + denominator, denominator * fraction.denominator);
}

// Comment 8:
// This function overloads the assignment operator (*) to multiply RationalNumber objects.
RationalNumber RationalNumber::operator*(const RationalNumber& fraction)
{
	return RationalNumber(numerator * fraction.numerator, denominator * fraction.denominator);
}

// Comment 9:
// This function overloads the assignment operator (/) to divide RationalNumber objects.
RationalNumber RationalNumber::operator/(const RationalNumber& fraction)
{
	if (fraction.numerator == 0) 
	{
		throw std::invalid_argument("Dividing by zero is undefined!");
	}
	return RationalNumber(numerator * fraction.denominator, denominator * fraction.numerator);
}

// Comment 8:
// This function overloads the assignment operator (=) to set a RationalNumber object equal to another RationalNumber object.
RationalNumber& RationalNumber::operator=(const RationalNumber& fraction)
{
	if (this != &fraction)
	{
		numerator = fraction.numerator;
		denominator = fraction.denominator;
	}
	return *this;
}

// Comment 9:
// This function overloads the relational operator (<) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is less than the RationalNumber object on the right of the < symbol.
bool RationalNumber::operator<(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator < fraction.numerator * denominator;
}

// Comment 10:
// This function overloads the relational operator (>) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is greater than the RationalNumber object on the right of the > symbol.
bool RationalNumber::operator>(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator > fraction.numerator * denominator;
}

// Comment 11:
// This function overloads the relational operator (<=) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is less than or equal to the RationalNumber object on the right of the <= symbol.
bool RationalNumber::operator<=(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator <= fraction.numerator * denominator;
}

// Comment 12:
// This function overloads the relational operator (>=) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is greater than or equal to the RationalNumber object on the right of the >= symbol.
bool RationalNumber::operator>=(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator >= fraction.numerator * denominator;
}

// Comment 13:
// This function overloads the relational operator (==) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is equivalent the RationalNumber object on the right of the == symbol.
bool RationalNumber::operator==(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator == fraction.numerator * denominator;
}

// Comment 13:
// This function overloads the relational operator (!=) to compare two RationalNumber objects to see if the RationalNumber object
// on the left is not equivalent the RationalNumber object on the right of the != symbol.
bool RationalNumber::operator!=(const RationalNumber& fraction) const
{
	return numerator * fraction.denominator != fraction.numerator * denominator;
}