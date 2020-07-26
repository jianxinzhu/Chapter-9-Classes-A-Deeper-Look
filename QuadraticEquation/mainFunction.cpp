/*  
name: jianxin zhu
date: july/25/2020
*/

#include<iostream>
#include"QuaadraticEquation.h"

int main()
{
	QuadraticEquation problem1{ 5.0,6.0,1.0 };
	QuadraticEquation problem2{ 5.0,2.0,1.0 };

	std::cout << "Quadratic Equation 1: " << problem1.toString();
	problem1.solve();

	std::cout << "Quadratic Equation 2: " << problem2.toString();
	problem2.solve();

	problem1.add(problem1, problem2);
	std::cout << "Add first equation to second equation: " << problem1.toString();
	problem1.solve();



	
}
