/*
name: jianxin zhu
date: aug/01/2020
*/

#include"DeckOfCards.h"
#include<iostream>

using namespace std;

void playGame(DeckOfCards& d1)
{
	d1.shuffle();
	d1.dealFiveCard();
	d1.sortCard();
	d1.showCard();
	d1.gameResult();
}

int main()
{
	DeckOfCards deckPlayer1;
	DeckOfCards deckPlayer2;
	
	playGame(deckPlayer1);
	playGame(deckPlayer2);


	return 0;
}
