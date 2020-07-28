/*
name: jianxin zhu
date: july/27/2020
*/

#include"Student.h"
#include<iostream>

using namespace std;

int main()
{
	Student student{ "John","Paul","X","123456789@mail.com","Male",1997,123456 };

	cout << student.toString();
}
