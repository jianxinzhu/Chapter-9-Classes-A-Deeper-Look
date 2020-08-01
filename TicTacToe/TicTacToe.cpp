/*
name: jianxin zhu
date: july/31/2020
*/

#include"Tic.h"
#include<iostream>
#include<iomanip>


Tic::Tic()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			board[i][j] = ' ';
		}
	}
}

bool Tic::validMove(int r, int c)
{
	return ((r >= 0 && r < 3) && (c >= 0 && c < 3) && board[r][c] == ' ');
}
Tic::Status Tic::gameStatus()
{
	int a;

	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[0][0] == board[2][2])
	{
		return WIN;
	}
	else if ((board[2][0] != ' ' && board[2][0] == board[1][1] && board[0][0] == board[0][2]))
	{
		return WIN;
	}

	for (a = 0; a < 3; ++a)
	{
		if (board[a][0] != ' ' && board[a][0] == board[a][1] && board[a][0] == board[a][2])
		{
			return WIN;
		}
	}
	for (a = 0; a < 3; ++a)
	{
		if (board[0][a] != ' ' && board[0][a] == board[1][a] && board[0][a] == board[2][a])
		{
			return WIN;
		}
	}

	for (int r = 0; r < 3; ++r)
	{
		for (int c = 0; c < 3; ++c)
		{
			if (board[r][c] == ' ')
			{
				return CONTINUE;
			}
		}
	}

	return DRAW;
}
void Tic::printBoard()
{
	std::cout << "   0   1   2\n\n";
	for (int r = 0; r < 3; ++r)
	{
		std::cout << r;
		for (int c = 0; c < 3; c++)
		{
			std::cout << std::setw(3) << static_cast<char>(board[r][c]);
			if (c != 2)
			{
				std::cout << " |";
			}
		}
		if (r != 2)
		{
			std::cout << "\n_____|____|____"
				<< "\n     |    |    \n";
		}
	}
}
void Tic :: makeMove()
{
	printBoard();

	while (true)
	{
		if (xoMove('X'))
		{
			break;
		}
		else if (xoMove('0'))
		{
			break;
		}
	}
}
bool Tic::xoMove(int symbol)
{
	int x, y;

	do
	{
		std::cout << "\nPlayer " << static_cast<char>(symbol) << " Enter move: ";
		std::cin >> x >> y;
		std::cout << std::endl;
	} while (!validMove(x, y));

	board[x][y] = symbol;
	printBoard();
	Status xoStatus = gameStatus();

	if (xoStatus == WIN)
	{
		std::cout << "\nPlayer " << static_cast<char>(symbol) << " win\n";
		return true;
	}
	else if (xoStatus == DRAW)
	{
		std::cout << "\nGame is a draw.\n";
		return false;
	}
	else
	{
		return false;
	}
}
