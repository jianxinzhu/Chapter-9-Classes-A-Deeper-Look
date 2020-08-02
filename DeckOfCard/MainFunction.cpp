/*
name: jianxin zhu
date: july/01/2020
*/

#include"DeckOfCards.h"
#include<iostream>

using namespace std;

int main()
{
	DeckOfCards deck;
	deck.shuffle();
	while (deck.moreCard())
	{
		cout << deck.dealCard().toString() << endl;
	}
	return 0;
}
