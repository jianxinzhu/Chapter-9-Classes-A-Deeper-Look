/*
name: jianxin zhu
date: aug/01/2020
*/

#ifndef CARD_H
#define CARD_H

#include<string>

class Card
{
public:
	Card(int, int);

	int get_Face() const;
	int get_Suit() const;
	std::string toString() const;
private:
	static std::string faces[];
	static std::string suits[];

	int face;
	int suit;
};
#endif
