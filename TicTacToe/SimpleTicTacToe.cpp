/*
name: jiainxin zhu
date: july/31/2020
*/

#include<iostream>
#include<iomanip>

using namespace std;

enum Status { WIN, CONTINUE };

char tic_Board[3][3] = { '1','2','3','4','5','6','7','8','9' };
char player = 'X';

void Print_Board()
{
	cout << "-----------" << endl;
	for (int i = 0; i < 3; i ++ )
	{
		for (int j = 0; j < 3; j++)
		{
			cout << setw(3)<<tic_Board[i][j];
		}

		cout << endl;
	}
	cout << "-----------" << endl;
}
void move_XO()
{
	int a;
	cout << "Enter Your Move(1-9): ";
	cin >> a;

	switch (a)
	{
	case 1:
		tic_Board[0][0] = player;
		break;
	case 2:
		tic_Board[0][1] = player;
		break;
	case 3:
		tic_Board[0][2] = player;
		break;
	case 4:
		tic_Board[1][0] = player;
		break;
	case 5:
		tic_Board[1][1] = player;
		break;
	case 6:
		tic_Board[1][2] = player;
		break;
	case 7:
		tic_Board[2][0] = player;
		break;
	case 8:
		tic_Board[2][1] = player;
		break;
	case 9:
		tic_Board[2][2] = player;
		break;
	default:
		cout << "You are not Entering a Vaild move" << endl;
		break;

	}
}
void player_Switch()
{
	if (player == 'X')
	{
		player = 'O';
	}
	else
	{
		player = 'X';
	}
}
Status check_Status()
{
	Status check_status = Status::CONTINUE;

	for (int i = 0; i < 3; i++)
	{
		if (tic_Board[i][0] == tic_Board[i][1] && tic_Board[i][0] == tic_Board[i][2])
		{
			check_status = WIN;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (tic_Board[0][i] == tic_Board[1][i] && tic_Board[0][i] == tic_Board[2][i])
		{
			check_status = WIN;
		}
	}

	if (tic_Board[0][0] == tic_Board[1][1] && tic_Board[0][0] == tic_Board[2][2])
	{
		check_status = WIN;
	}

	if (tic_Board[0][2] == tic_Board[1][1] && tic_Board[0][2] == tic_Board[2][0])
	{
		check_status = WIN;
	}


	return check_status;
}

int main()
{
	int count = 0;
	Status game_Status = CONTINUE;

	while (count <= 9 && game_Status == Status::CONTINUE)
	{
		Print_Board();
		move_XO();
		player_Switch();
		game_Status = check_Status();
		count++;

		if (game_Status == Status::WIN)
		{
			player_Switch();
			cout << "Player '" << player << "' Winning the game." << endl;
			Print_Board();
		}
	}

	if (count == 9)
	{
		cout << "Game is DRAW" << endl;
	}

	system("pause");
	return 0;
}
