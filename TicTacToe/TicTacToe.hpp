/*
name: jianxin zhu
date: july/31/2020
*/

#ifndef TIC_H
#define TIC_H

class Tic
{
	static enum Status { WIN, DRAW, CONTINUE };
public:
	Tic();
	void makeMove();
	void printBoard();
	bool validMove(int, int);
	bool xoMove(int);
	Status gameStatus();

private:
	int board[3][3];
};
#endif
