/*
name: jianxin zhu
date: aug/01/2020
*/

#include"DeckOfCards.h"
#include"Card.h"
#include<ctime>
#include<iostream>
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
	return std::uniform_int_distribution<int>{ 0, totalCard - 1 }(gen);
}
void DeckOfCards::dealFiveCard()
{
	for (int i = 0; i < handCard; i++)
	{
		hand.push_back(dealCard());
	}

}
void DeckOfCards::showCard()
{
	for (int i = 0; i < handCard; i++)
	{
		std::cout << hand[i].toString();
	}



}
void DeckOfCards::sortCard()
{
	int flag = 1;

	for (int i = 0; i < handCard&&flag; i++)
	{
		flag = 0;
		for (int j = 0; j < handCard-1; j++)
		{
			if (hand[j].get_Face() > hand[j+1].get_Face())
			{
				Card c1 = hand[j];
				Card c2 = hand[j+1];
				Card c3 = c1;

				hand[j]= c2;
				hand[j+1] = c3;

				flag = 1;
			}
		}
	}
}
void DeckOfCards::shuffle()
{

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
bool DeckOfCards::isPair() 
{
	for (int i = 0; i < handCard; i++)
	{
		for (int j = i + 1; j < handCard; j++)
		{
			if (hand[i].get_Face() == hand[j].get_Face())
			{
				return true;
			}
		}
	}
	return false;
}
bool DeckOfCards::isTwoPair()
{
	if (isPair())
	{
		for (int i = 0; i < handCard; i++)
		{
			for (int j = i + 1; j < handCard; j++)
			{
				if (hand[i].get_Face() == hand[j].get_Face())
				{
					int firstPair = hand[i].get_Face();

					for (int k = 0; k < handCard; k++)
					{
						for (int l = k + 1; l < handCard; l++)
						{
							if (hand[k].get_Face() != firstPair && hand[k].get_Face() == hand[l].get_Face())
							{
								return true;
							}
						}
					}

				}
			}
		}
		return false;
	}

}
bool DeckOfCards::isThreeKind()
{
	for (int i = 0, counter = 0; i < handCard; ++i) 
	{
		for (int j = i+1; j < handCard; ++j) 
		{
			if (hand[i].get_Suit() == hand[j].get_Suit()) 
			{
				counter++;

				if (counter == 3) 
				{
					return true;
				}
			}
		}
	}
	return false;

}
bool DeckOfCards::isFourKind()
{
	for (int i = 0, counter = 0; i < handCard; i++)
	{
		for (int j = i + 1; j < handCard; j++)
		{
			if (hand[i].get_Suit() == hand[j].get_Suit())
			{
				counter++;

				if (counter == 4)
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool DeckOfCards::isFlush()
{
	int flush = 0;
	for (int i = 0; i < handCard; i++)
	{
		if (hand[0].get_Suit() == hand[i].get_Suit())
		{
			flush++;
		}
	}

	if (flush == 5)
	{
		return true;
	}

	return false;
}
bool DeckOfCards::isStrainght()
{
	int counter = 1;
	for (int i = 0; i < handCard-1; i++)
	{
		if (hand[i].get_Face() == hand[i+1].get_Face() + 1)
		{
			counter++;
		}
	}

	if (counter == 5)
	{
		return true;
	}
	
	return false;
}

void DeckOfCards::gameResult()
{
	std::cout << "****************" << std::endl;
	if (isPair())
	{
		if (isTwoPair())
		{
			std::cout << "You have Two Pair" << std::endl;
		}
		else
		{
			std::cout << "You have one Pair" << std::endl;
		}
	}

	if (isThreeKind())
	{
		if (isFourKind())
		{
			if (isFlush())
			{
				std::cout << "You have a Flush" << std::endl;
			}
			else
			{
				std::cout << "You have Four Kind" << std::endl;
			}
		}
		else
		{
			std::cout << "You have Three Kind" << std::endl;
		}
	}

	if (isStrainght())
	{
			std::cout << "You have a Straight" << std::endl;
    }

	std::cout << "****************" << std::endl;
}
