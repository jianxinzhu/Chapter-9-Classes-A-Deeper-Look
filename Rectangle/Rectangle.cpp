/*
name: jianxin zhu
date: july/27/2020
*/

#include"Rctangle.h"
#include<stdexcept>
#include<iostream>

Rectangle::Rectangle(double L, double W)
{
	set_Length(L);
	set_Width(W);
}

Rectangle& Rectangle::set_Length(double length)
{
	if (length > 0.0 && length < 20.0)
	{
		this->length = length;
		return *this;
	}
	else
	{
		throw std::invalid_argument("Length must be in 0.0 to 20.0");
	}
}
Rectangle& Rectangle::set_Width(double width)
{
	if (width > 0.0 && width < 20.0)
	{
		this->width = width;
		return *this;
	}
	else
	{
		throw std::invalid_argument("Width must be in 0.0 to 20.0");
	}

}
double Rectangle::get_Length() const
{
	return length;
}
double Rectangle::get_Width() const
{
	return width;
}

void Rectangle::area()
{
	double rectangle_Length = get_Length();
	double rectangel_Width = get_Width();

	double rectangle_Area = rectangle_Length * rectangel_Width;

	std::cout << "Area : " << rectangle_Area;
}
void Rectangle::perimeter()
{
	double rectangle_Length = get_Length();
	double rectangel_Width = get_Width();

	double rectangle_Perimeter = 2* (rectangle_Length + rectangel_Width);

	std::cout << "Perimeter : " << rectangle_Perimeter;
}
