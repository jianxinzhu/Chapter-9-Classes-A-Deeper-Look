/*
name: jianxin zhu
date: july/28/2020
*/
#include<iostream>
#include"Rctangle.h"
using namespace std;

int main()
{
	Rectangle square{ 10.0, 15.0 };

	square.area();
	cout << endl;
	square.perimeter();

	cout << "\nChange the length to 5.0 and width to 10.0" << endl;
	square.set_Length(5.0).set_Width(10.0);

	square.area();
	cout << endl;
	square.perimeter();


}
