/*  name : jianxin zhu
    date: july/25/2020
*/

#include<string>

#ifndef QUADRATICEQUATION_H
#define QUADRATICEQUATION_H


class QuadraticEquation
{
public:
	explicit QuadraticEquation(double = 1.0, double = 0.0, double = 0.0);

	void add(QuadraticEquation&, const QuadraticEquation &);
	void subtract(QuadraticEquation&, const QuadraticEquation&);
	void solve();
	void set_A(double);
	void set_B(double);
	void set_C(double);

	std::string toString() const;
	double get_A() const;
	double get_B() const;
	double get_C() const;


private:
	double value_A = 0.0;
	double value_B = 0.0;
	double value_C = 0.0;
};
#endif
