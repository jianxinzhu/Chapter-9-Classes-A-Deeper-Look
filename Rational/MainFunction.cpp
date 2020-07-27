/*
name: jianxin zhu
date: july/26/2020
*/

#include"Rational.h"
#include<iostream>
using namespace std;

int main()
{
	Rational r1{ 3, 5 };
	Rational r2{ 4, 8 };
	Rational r3{};

	cout << "The number: " << r1.toString();
	cout << "\nThe number: " << r2.toString() << endl;

	cout << "---------------------" << endl;

	cout << "addition: ";
	r3.add(r1, r2);
	cout << "Substraction: ";
	r3.subtract(r1, r2);
	cout << "Multiplication: ";
	r3.multiply(r1, r2);
	cout << "Division: ";
	r3.divide(r1, r2);

	cout << "The number: " << r1.toString() << " turn to Double format: " << r3.toDouble(r1) << endl;
	cout << "The number: " << r2.toString() << " turn to Double format: " << r3.toDouble(r2) << endl;

}
