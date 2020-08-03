/*
name: jianxin zhu
date: aug/02/2020
*/

#ifndef DECKOFCARDS_H
#define DECKOFCARDS_H

#include"Card.h"
#include<vector>
#include<random>

static std::random_device rd;
static std::mt19937 gen(rd());

class DeckOfCards
{
	static const int totalCard = 52;
	static const int handCard = 5;
	static enum class CARDSTATUS{NONE=1, PAIR, TWOPAIR, THRREKIND, FOURKIND, FLUSH, STRAIGHT};
public:
	DeckOfCards();

	
    static void shuffle();


	void dealFiveCard();
	void sortCard();
	void showCard();
	void setScore(int);
	Card dealCard();

	bool isPair();
	bool isTwoPair();
	bool isThreeKind();
	bool isFourKind();
	bool isFlush();
	bool isStrainght();

	bool moreCard() const;

	int getScore();
	int get_WinningCard() const;
	CARDSTATUS getStatus() const;
	void gameResult();
	void compareResult(DeckOfCards, DeckOfCards);

private:
	int score;
	int winnging_Card;
	CARDSTATUS playerStatus = CARDSTATUS::NONE;
	bool isSorted;

	std::vector<Card>hand;
	static std::vector<Card>deck;
	static int currentCard;


	static int randomNumber();
};
#endif
