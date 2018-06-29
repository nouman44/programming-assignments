
#include "stdafx.h"
#include <iostream>
#include "fraction.h"

using namespace std;

float fraction::smallestValue = 0;

float fraction::largestValue = 0;

float fraction::averageValue = 0;

int fraction::num = 0;

bool fraction::firstInitialize = true;

int fraction::computeGCD(int a, int b)
{
	
	int gcd = 0;
	int temp = 0;

	if (a > b)
	{
		temp = a;
		a = b;
		b = temp;
	}

	while (a != 0)
	{
		b = b % a;

		temp = a;
		a = b;
		b = temp;

		gcd = b;
	}

	return gcd;
}

int fraction::computeLCM(int a, int b)
{
	int lcm = 0;
	bool lcmFound = false;

	if (a < b)
		lcm = b;
	else
		lcm = a;

	while (!lcmFound)
	{
		if ((lcm%a == 0) && (lcm%b == 0))
			lcmFound = true;
		else
			lcm++;
	}

	return lcm;
}

void fraction::IncrementNum()
{
	num = num + 1;
}

void fraction::ValueCheck()
{
	float value = (float)numerator / (float)denominator;

	if (firstInitialize)
	{
		smallestValue = value;
		largestValue = value;
		firstInitialize = false;
	}

	if (value < smallestValue)
		smallestValue = value;
	if (value > largestValue)
		largestValue = value;
}

fraction::fraction(int userNum, int userDenom)
{
	numerator = userNum;

	if (userDenom != 0)
		denominator = userDenom;
	else
		denominator = 1;

	float value = (float)numerator / (float)denominator;

	IncrementNum();

	averageValue = ((averageValue*(num - 1)) + value) / num;

	ValueCheck();
}

void fraction::operator!(void) const
{
	cout << numerator << "/" << denominator << endl;
}

fraction & fraction::operator~(void)
{
	int gcd = computeGCD(numerator, denominator);

	numerator = numerator / gcd;
	denominator = denominator / gcd;

	return *this;
}

fraction fraction::operator-(void) const
{
	fraction fracObj;
	
	fracObj.numerator = -numerator;
	fracObj.denominator = denominator;

	return fracObj;
}

fraction fraction::operator*(void) const
{
	fraction fracObj;

	fracObj.numerator = denominator;
	fracObj.denominator = numerator;

	return fracObj;
}

fraction & fraction::operator+=(const fraction & operand)
{
	int lcm = computeLCM(denominator, operand.denominator);

	int multiplier1 = lcm / denominator;
	int multiplier2 = lcm / operand.denominator;

	denominator = lcm;

	numerator = (numerator*multiplier1) + (operand.numerator*multiplier2);

	*this = ~*this;

	ValueCheck();
	
	return *this;
}

fraction & fraction::operator-=(const fraction & operand)
{
	int lcm = computeLCM(denominator, operand.denominator);

	int multiplier1 = lcm / denominator;
	int multiplier2 = lcm / operand.denominator;

	denominator = lcm;

	numerator = (numerator*multiplier1) - (operand.numerator*multiplier2);

	*this = ~*this;

	ValueCheck();

	return *this;
}

fraction & fraction::operator*=(const fraction & operand)
{
	numerator = numerator * operand.numerator;
	denominator = denominator * operand.denominator;

	*this = ~*this;

	ValueCheck();

	return *this;
}

fraction & fraction::operator/=(const fraction & operand)
{
	numerator = numerator * operand.denominator;
	denominator = denominator * operand.numerator;

	*this = ~*this;

	ValueCheck();

	return *this;
}

bool fraction::operator>(const fraction & operand) const
{
	bool valCheck = true;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value <= opValue)
		valCheck = false;

	return valCheck;
}

bool fraction::operator<(const fraction & operand) const
{
	bool valCheck = true;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value >= opValue)
		valCheck = false;

	return valCheck;
}

bool fraction::operator>=(const fraction & operand) const
{
	bool valCheck = true;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value < opValue)
		valCheck = false;

	return valCheck;
}

bool fraction::operator<=(const fraction & operand) const
{
	bool valCheck = true;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value > opValue)
		valCheck = false;

	return valCheck;
}

bool fraction::operator==(const fraction & operand) const
{
	bool isEqual = false;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value == opValue)
		isEqual = true;

	return isEqual;
}

bool fraction::operator!=(const fraction & operand) const
{
	bool notEqual = true;

	float value = (float)numerator / (float)denominator;
	float opValue = (float)operand.numerator / (float)operand.denominator;

	if (value == opValue)
		notEqual = false;

	return notEqual;
}

fraction & fraction::operator++()
{
	numerator = numerator + denominator;

	*this = ~*this;

	return *this;
}

fraction fraction::operator++(int)
{
	fraction fracObj(*this);

	fracObj.numerator = numerator + denominator;

	fracObj = ~fracObj;

	return fracObj;
}

float fraction::largest()
{
	return largestValue;
}

float fraction::smallest()
{
	return smallestValue;
}

float fraction::average()
{
	return averageValue;
}

ostream & operator<<(ostream &strm, const fraction & f)
{
	strm << f.numerator << "/" << f.denominator << endl;

	return strm;
}

istream & operator>>(istream &strm, fraction & f)
{
	cout << "Enter numerator: ";
	strm >> f.numerator;
	cout << "Enter denominator: ";
	strm >> f.denominator;

	if (f.denominator == 0)
	{
		f.denominator = 1;
	}

	float value = (float)f.numerator / (float)f.denominator;

	f.IncrementNum();

	fraction::averageValue = ((fraction::averageValue*(fraction::num - 1)) + value) / fraction::num;

	f.ValueCheck();

	return strm;
}
