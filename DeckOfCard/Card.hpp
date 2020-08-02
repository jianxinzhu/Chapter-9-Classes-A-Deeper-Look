/*
name: jianxin zhu
date: aug/1/2020
*/

#ifndef CARD_H
#define CARD_H

#include<string>

class Card
{
public:
	Card(int, int);

	std::string toString() const;
private:
	static std::string faces[];
	static std::string suits[];

	int face;
	int suit;
};
#endif
