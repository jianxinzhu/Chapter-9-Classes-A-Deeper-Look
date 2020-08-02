/*
name: jianxin zhu
date: aug/01/2020
*/
#include"Card.h"
#include<sstream>

std::string Card::suits[5] = { "","Spade","Heart","Diamond","Club" };
std::string Card::faces[14] = {"", "Ace","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };

Card::Card(int f, int s)
{
	face = f;
	suit = s;
}

int Card::get_Face() const
{
	return face;
}
int Card::get_Suit() const
{
	return suit;
}

std::string Card::toString() const
{
	std::ostringstream output;
	output << faces[face] << " of " << suits[suit] << std::endl;

	return output.str();
}
