/*
name: jianxin zhu
date: july/26/2020
*/

#include<string>

#ifndef RATIONAL_H
#define RATIONAL_H

class Rational
{
public:
	explicit Rational(int = 1, int = 1);
	void add(Rational, Rational);
	void subtract(Rational,  Rational);
	void multiply(Rational, Rational);
	void divide(Rational,  Rational);

	std::string toString() const;
	double toDouble(Rational&);

private:
	int numerator = 1;
	int denominator = 1;

};
#endif
