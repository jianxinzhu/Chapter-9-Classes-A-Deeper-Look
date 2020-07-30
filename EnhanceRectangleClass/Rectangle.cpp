/*
name: jianxin zhu
date: july/29/2020
*/

#include"Rctangle.h"
#include<stdexcept>
#include<iostream>

Rectangle::Rectangle(const Coordinate& first, const Coordinate& second, const Coordinate& third, const Coordinate& forth)
{
	set_Length(first, second);
	set_Width(third, forth);
}

void Rectangle::set_Length(const Coordinate& corner1, const Coordinate& corner2)
{
	double length = 0.0;
	length = corner2.get_X() - corner1.get_X();

	this->length = length;
}
void Rectangle::set_Width(const Coordinate& corner1, const Coordinate& corner2)
{
	double width = 0.0;

	width = corner2.get_Y() - corner1.get_Y();

	this->width = width;
}
double Rectangle::get_Length() const
{
	return length;
}
double Rectangle::get_Width() const
{
	return width;
}

bool Rectangle::isSquare()
{
	return (get_Length() == get_Width());
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
char Rectangle::setFillCharacter(char sign)
{
	this->sign = sign;
	return sign;
}
char Rectangle::getFillCharacter() const
{
	return sign;
}
void Rectangle::draw(const Coordinate& rec1, const Coordinate& rec2, const Rectangle& sym)
{
	unsigned int rec1_x = static_cast<unsigned int>(rec1.get_X());
	unsigned int rec2_x = static_cast<unsigned int>(rec2.get_X());
	unsigned int rec1_y = static_cast<unsigned int>(rec1.get_Y());
	unsigned int rec2_y = static_cast<unsigned int>(rec2.get_Y());
	char symbol = sym.getFillCharacter();
	for (unsigned int i = 0; i <= LENGTH; i++)
	{
		for (unsigned int j = 0; j <= WIDTH; j++)
		{
			if (i == 0 || i == LENGTH)
			{
				std::cout << '#';
			}
			else if (j == 0 || j == WIDTH)
			{
				std::cout << '#';

			}
			else
			{
				if (i >rec1_x && i <= rec2_x)
				{
					if (j > rec1_y && j <= rec2_y)
					{
						std::cout << symbol;
					}
					else
					{
						std::cout << ' ';
					}
				}
				else
				{
					std::cout << ' ';
				}
			}

			
		}

		std::cout << std::endl;
	}
}
