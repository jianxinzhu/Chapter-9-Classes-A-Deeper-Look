/*
name: jianxin zhu
date: july/31/2020
*/

#include"Date.h"
#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	Date d1{ 3,8,1994 };
	Date d2{ 341,1997 };
	Date d3{ "July",24, 2020 };
	Date d4;

	d1.displayTimeSlash();
	d1.displayTimeDay();
	d1.displayTimeString();

	cout << endl;

	d2.displayTimeSlash();
	d2.displayTimeDay();
	d2.displayTimeString();

	cout << endl;
	
	d3.displayTimeSlash();
	d3.displayTimeDay();
	d3.displayTimeString();

	cout << endl;

	d4.displayTimeSlash();
	d4.displayTimeDay();
	d4.displayTimeString();


}
