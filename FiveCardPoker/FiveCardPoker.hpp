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
	static const int handCard = 5;
public:
	DeckOfCards();

	void shuffle();
	void dealFiveCard();
	void sortCard();
	void showCard();
	Card dealCard();

	bool isPair();
	bool isTwoPair();
	bool isThreeKind();
	bool isFourKind();
	bool isFlush();
	bool isStrainght();

	bool moreCard() const;

	void gameResult();

private:
	std::vector<Card>deck;
	std::vector<Card>hand;
	int currentCard;


	std::mt19937 gen;
	int randomNumber();
};
#endif
