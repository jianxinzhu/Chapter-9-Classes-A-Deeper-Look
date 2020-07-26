/*  name: jianxin zhu
    date: july/26/2020
*/

#include"QuaadraticEquation.h"
#include<sstream>
#include<cmath>
#include<iostream>

QuadraticEquation::QuadraticEquation(double a, double b, double c)
{
	set_A(a);
	set_B(b);
	set_C(c);

}
void QuadraticEquation::set_A(double a)
{
	if (a <= 0)
	{
		value_A = 1;
	}
	else
	{
		value_A = a;
	}
}
void QuadraticEquation::set_B(double b)
{
	value_B = b;
}
void QuadraticEquation::set_C(double c)
{
	value_C = c;
}
double QuadraticEquation::get_A() const
{
	return value_A;
}
double QuadraticEquation::get_B() const
{
	return value_B;
}
double QuadraticEquation::get_C() const
{
	return value_C;
}

void QuadraticEquation::add(QuadraticEquation& equation1, const QuadraticEquation& equation2)
{
	equation1.value_A += equation2.value_A;
	equation1.value_B += equation2.value_B;
	equation1.value_C += equation2.value_C;
}

void QuadraticEquation::subtract(QuadraticEquation& equation1, const QuadraticEquation& equation2)
{
	equation1.value_A -= equation2.value_A;
	equation1.value_B -= equation2.value_B;
	equation1.value_C -= equation2.value_C;
}
std::string QuadraticEquation::toString() const
{
	std::ostringstream output;

	output << value_A <<"X^2" << ((value_B>0)?"+":"")<<value_B <<"X" << ((value_C>=0)?"+":"")
		<<value_C<< std::endl;

	return output.str();
}
void QuadraticEquation::solve()
{
	double res = sqrt(pow(value_B, 2) - (4 * value_A * value_C));

	if (res > 0)
	{
		double res_1 = (((-1) * value_B) + res) / (2 * value_A);
		double res_2 = (((-1) * value_B) - res) / (2 * value_A);

		std::cout << "Solution one: " << res_1 << std::endl;
		std::cout << "Solution two: " << res_2 << std::endl;
	}
	else
	{
		std::cout << "No Real Roots" << std::endl;
	}

}
