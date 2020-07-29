/*
name: jianxin zhu
date: july/28/2020
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
public:
	explicit Rectangle(double = 1.0, double = 1.0);

	void area();
	void perimeter();

	Rectangle& set_Length(double);
	Rectangle& set_Width(double);

	double get_Length() const;
	double get_Width() const;

private:
	double length = 0;
	double width = 0;
};
#endif
