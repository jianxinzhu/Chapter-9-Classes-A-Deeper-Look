/*
name: jianxin zhu
date: july/26/2020
*/

#include"Rational.h"
#include<iostream>
#include<sstream>

Rational::Rational(int num, int deno)
{
	if (deno >= 0 && num >=0)
	{
		numerator = num;
		denominator = deno;
	}
	else
	{
		std::cout << "Numerator or Denominator sholud not zero";
	}
}
void Rational::add(Rational num1,  Rational num2)
{
	num1.numerator *= num2.denominator;
	num2.numerator *= num1.denominator;
	num1.denominator *= num2.denominator;
	num1.numerator += num2.numerator;

	
	int smallest{ (num1.numerator <= num1.denominator) ? num1.numerator : num1.denominator };
	int factor = 1;

	for (int i = 1; i <= smallest; i++)
	{
		if ((num1.numerator % i == 0) && (num1.denominator % i == 0))
		{
			factor = i;
		}
	}

	num1.numerator /= factor;
	num1.denominator /= factor;

	std::cout << num1.numerator << "/" << num1.denominator << std::endl;
	

}
void Rational::subtract(Rational num1, Rational num2)
{
	num1.numerator *= num2.denominator;
	num2.numerator *= num1.denominator;
	num1.denominator *= num2.denominator;
	num1.numerator -= num2.numerator;

	
	int smallest{ (num1.numerator <= num1.denominator) ? num1.numerator : num1.denominator };
	int factor = 1;


	for (int i = 1; i <= smallest; i++)
	{
		if ((num1.numerator % i == 0) && (num1.denominator % i == 0))
		{
			factor = i;
		}
	}

	num1.numerator /= factor;
	num1.denominator /= factor;

	std::cout << num1.numerator << "/" << num1.denominator << std::endl;
}
void Rational::multiply(Rational num1, Rational num2)
{
	num1.numerator *= num2.numerator;
	num1.denominator *= num2.denominator;

	int smallest{ (num1.numerator <= num1.denominator) ? num1.numerator : num1.denominator };
	int factor = 1;

	for (int i = 1; i <= smallest; i++)
	{
		if ((num1.numerator % i == 0) && (num1.denominator % i == 0))
		{
			factor = i;
		}
	}

	num1.numerator /= factor;
	num1.denominator /= factor;

	std::cout << num1.numerator << "/" << num1.denominator << std::endl;

}
void Rational::divide(Rational num1, Rational num2)
{
	num1.numerator *= num2.denominator;
	num1.denominator *= num2.numerator;

	int smallest{ (num1.numerator <= num1.denominator) ? num1.numerator : num1.denominator };
	int factor = 1;

	for (int i = 1; i <= smallest; i++)
	{
		if ((num1.numerator % i == 0) && (num1.denominator % i == 0))
		{
			factor = i;
		}
	}

	num1.numerator /= factor;
	num1.denominator /= factor;

	std::cout << num1.numerator << "/" << num1.denominator << std::endl;

}
double Rational::toDouble(Rational& num)
{
	double res = static_cast<double>(num.numerator) / num.denominator;

	return res;
}
std::string Rational::toString() const
{
	std::ostringstream output;

	output << numerator << "/" << denominator;

	return output.str();

}
