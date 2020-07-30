/*
name: jianxin zhu
date: july/29/2020
*/

#include"Coordinate.h"
#include<stdexcept>


Coordinate::Coordinate(double x, double y)
{
	set_X(x);
	set_Y(y);
}
Coordinate& Coordinate::set_X(double x)
{
	if (x > 0.0 && x <= 20.0)
	{
		this->x = x;
		return *this;
	}
	else
	{
		throw std::invalid_argument("X must be in the range 0.0 to 20.0");
	}
}
Coordinate& Coordinate::set_Y(double y)
{
	if (y > 0.0 && y < 20.0)
	{
		this->y = y;
		return *this;
	}
	else
	{
		throw std::invalid_argument("Y must be in the range 0.0 to 20.0");
	}
}
double Coordinate::get_X() const
{
	return x;
}
double Coordinate::get_Y() const
{
	return y;
}
