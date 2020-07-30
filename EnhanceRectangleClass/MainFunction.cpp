/*
name: jianxin zhu
date: july/29/2020
*/
#include<iostream>
#include"Rctangle.h"
using namespace std;

int main()
{
	char sign = ' ';
	cout << "Enter Your symbol: ";
	cin >> sign;
	Coordinate corner1{ 6,10 };
	Coordinate corner2{ 6,12 };
	Coordinate corner3{ 15,10 };
	Coordinate corner4{ 15,12 };

	Rectangle rec1{ corner1, corner2,corner3,corner4 };
	rec1.setFillCharacter(sign);
	rec1.set_Length(corner1, corner3);
	rec1.set_Width(corner1, corner2);

	cout << "Length: " << rec1.get_Length() << "\nWdith: " << rec1.get_Width()
		<< "\nSphape: " << (rec1.isSquare() ? "Square" : "Rectangle") << endl;
	rec1.area();
	cout << endl;
	rec1.perimeter();
	cout << endl;

	rec1.draw(corner1, corner4, rec1);



	


}
