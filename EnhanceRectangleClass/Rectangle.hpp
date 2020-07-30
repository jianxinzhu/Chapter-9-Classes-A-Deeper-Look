/*
name: jianxin zhu
date: july/29/2020
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include"Coordinate.h"

class Rectangle
{
public:
	static const int WIDTH = 25;
	static const int LENGTH = 25;
	Rectangle(const Coordinate&, const Coordinate&, const Coordinate&, const Coordinate&);

	void area();
	void perimeter();
	bool isSquare();

	void set_Length(const Coordinate&, const Coordinate&);
	void set_Width(const Coordinate&, const Coordinate&);
	char setFillCharacter(char);
	void draw(const Coordinate&, const Coordinate&, const Rectangle&);

	double get_Length() const;
	double get_Width() const;
	char getFillCharacter() const;

private:
	double length = 0;
	double width = 0;
	char sign = ' ';

	const Coordinate first_Corner;
	const Coordinate second_Corner;
	const Coordinate third_Corner;
	const Coordinate forth_Corner;
};
#endif
