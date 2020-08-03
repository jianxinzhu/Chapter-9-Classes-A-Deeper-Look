/*
name: jianxin zhu
date: aug/02/2020
*/

#include"DeckOfCards.h"
#include"Card.h"
#include<ctime>
#include<iostream>
#include<stdexcept>

std::vector<Card>DeckOfCards::deck;
int DeckOfCards::currentCard = 0;

DeckOfCards::DeckOfCards()
	:isSorted(false), score(0),winnging_Card(0)
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
	for (int i = 0; i <handCard; i++)
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
	isSorted = true;
}
void DeckOfCards::shuffle()
{

	for (int i = 0; i < totalCard; i++)
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
void DeckOfCards::setScore(int score)
{
	this->score = score;
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
				playerStatus = CARDSTATUS::PAIR;
				winnging_Card = hand[i].get_Face();
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
				if (hand[i].get_Face() != winnging_Card && hand[i].get_Face() == hand[j].get_Face())
				{
					playerStatus = CARDSTATUS::TWOPAIR;

					if (hand[j].get_Face() >= winnging_Card)
					{
						winnging_Card = hand[j].get_Face();
					}
					return true;
				}
			}
		}

		
	}
	return false;

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
					playerStatus = CARDSTATUS::THRREKIND;
					winnging_Card = hand[i].get_Suit();
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
					playerStatus = CARDSTATUS::FOURKIND;
					winnging_Card = hand[i].get_Suit();
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
		playerStatus = CARDSTATUS::FLUSH;
		winnging_Card = hand[0].get_Suit();
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
		playerStatus = CARDSTATUS::STRAIGHT;
		winnging_Card = hand[4].get_Face();
		return true;
	}
	
	return false;
}
int DeckOfCards::getScore()
{
	if (isPair())
	{
		if (isTwoPair())
		{
			this->score += 3;
		}
		else
		{
			this->score += 2;
		}
	}

	if (isThreeKind())
	{
		if (isFourKind())
		{
			if (isFlush())
			{
				this->score += 5;
			}
			else
			{
				this->score += 3;
			}
		}
		else
		{
			this->score += 2;
		}
	}

	if (isStrainght())
	{
		this->score += 5;
	}

	return this->score;
}
DeckOfCards::CARDSTATUS DeckOfCards::getStatus() const
{
	return playerStatus;
}
int DeckOfCards::get_WinningCard() const
{
	return winnging_Card;
}
void DeckOfCards::gameResult()
{
	std::cout << "*********************" << std::endl;
	if (isPair())
	{
		if (isTwoPair())
		{
			std::cout << "*You have Two Pair  *" << std::endl;
		}
		else
		{
			std::cout << "*You have one Pair  *" << std::endl;
		}
	}

	if (isThreeKind())
	{
		if (isFourKind())
		{
			if (isFlush())
			{
				std::cout << "*You have a Flush   *" << std::endl;
			}
			else
			{
				std::cout << "*You have Four Kind *" << std::endl;
			}
		}
		else
		{
			std::cout << "*You have Three Kind*" << std::endl;
		}
	}

	if (isStrainght())
	{
			std::cout << "*You have a Straight*" << std::endl;
    }

	std::cout << "*Your Score is: " << getScore()<<"   *" << std::endl;
	std::cout << "*********************" << std::endl;
}
void DeckOfCards::compareResult(DeckOfCards pp1, DeckOfCards pp2)
{
	if (pp1.getScore() > pp2.getScore())
	{
		std::cout << "Player 1 WON THE GAME" << std::endl;
	}
	else if (pp1.getScore() < pp2.getScore())
	{
		std::cout << "Player 2 WON THE GAME" << std::endl;
	}
	else
	{
		if (pp1.getStatus() == pp2.getStatus())
		{
			if (pp1.getStatus() == CARDSTATUS::PAIR || pp1.getStatus() == CARDSTATUS::TWOPAIR||pp1.getStatus()==CARDSTATUS::STRAIGHT)
			{
				if (pp1.get_WinningCard() > pp2.get_WinningCard())
				{
					std::cout << "Player 1 WON THE GAME" << std::endl;
				}
				else if (pp1.get_WinningCard() < pp2.get_WinningCard())
				{
					std::cout << "Player 2 WON THE GAME" << std::endl;
				}
				else
				{
					std::cout << "The GAME is DRAW" << std::endl;
				}
			}

			if (pp1.getStatus() == CARDSTATUS::THRREKIND || pp1.getStatus() == CARDSTATUS::FOURKIND || pp1.getStatus() == CARDSTATUS::FLUSH)
			{
				if (pp1.get_WinningCard() > pp2.get_WinningCard())
				{
					std::cout << "Player 2 WON THE GAME" << std::endl;
				}
				else if (pp1.get_WinningCard() < pp2.get_WinningCard())
				{
					std::cout << "Player 1 WON THE GAME" << std::endl;
				}
				else
				{
					std::cout << "The GAME is DRAW" << std::endl;
				}
				
			}
		}
		else
		{
			
			std::cout << "The GAME is DRAW" << std::endl;
		}
	}

	std::cout << "---------------------" << std::endl;
	pp1.setScore(0);
	pp2.setScore(0);

}
