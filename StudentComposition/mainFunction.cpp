/*
name: jianxin zhu
date: july/27/2020
*/
#include"Student.h"

#include<iostream>
using namespace std;

int main()
{
	Date birth{ 10,10,1997 };
	Name name {"Mr","John","Paul","X" };
	Student student{ name, birth,"123456789@gmail.com","Male",197886 };

	cout << student.toString();
}

