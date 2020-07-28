/*
name: jianxin zhu
date: july/27/2020
*/

#include"Name.h"
#include<iostream>

int main()
{
	Name employee;

	employee.set_Name("Mrs", "Smith", "Jane", "D");

	std::cout << employee.toString();
}
