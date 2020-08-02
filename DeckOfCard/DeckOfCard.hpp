/*
name: jianxin zhu
date: aug/01/2020
*/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include"Card.h"
#include<vector>
#include<random>


class DeckOfCards
{
	static const int totalCard = 52;
public:
	DeckOfCards();

	void shuffle();
	Card dealCard();
	bool moreCard() const;

private:
	std::vector<Card>deck;
	int currentCard;


	std::mt19937 gen;
	int randomNumber();
};
#endif
