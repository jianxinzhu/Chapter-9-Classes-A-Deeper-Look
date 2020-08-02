/*
name: jianxin zhu
date: aug/01/2020
*/

#include"DeckOfCards.h"
#include"Card.h"
#include<ctime>
#include<stdexcept>

DeckOfCards::DeckOfCards()
	:currentCard(0), gen(std::random_device()())
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 13; j++)
		{
			deck.push_back(Card(j, i));
		}
	}
}
int DeckOfCards::randomNumber()
{
	return std::uniform_int_distribution<int>{ 1, totalCard - 1 }(gen);
}
void DeckOfCards::shuffle()
{
	srand(time(0));

	for (int i = 0; i < 52; i++)
	{
		int r1 = randomNumber();
		int r2 = randomNumber();

		Card c1 = deck[r1];
		Card c2 = deck[r2];
		Card c3 = c1;

		deck[r1] = c2;
		deck[r2] = c3;
	}
}
Card DeckOfCards::dealCard()
{
	if (moreCard())
	{
		return deck[currentCard++];
	}
	else
	{
		throw std::invalid_argument("End of deck reached");
	}
}
bool DeckOfCards::moreCard() const
{
	return currentCard < totalCard;
}
