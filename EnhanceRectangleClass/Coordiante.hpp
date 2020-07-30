/*
name: jianxin zhu
date: july/29/2020
*/

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
	explicit Coordinate(double = 1.0, double = 1.0);

	Coordinate& set_X(double);
	Coordinate& set_Y(double);

	double get_X() const;
	double get_Y() const;
private:
	double x = 0;
	double y = 0;
};
#endif
