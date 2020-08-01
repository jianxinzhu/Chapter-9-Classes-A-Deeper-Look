/*
name: jianxin zhu
date: aug/01/2020
*/

#include"SavingAccount.h"
#include<iostream>

using namespace std;

int main()
{
	SavingAccount account1{ 2000.00  };
	account1.modify_Rate(0.03);

	for (int i = 1; i <= 20; i++)
	{
		account1.calculatingBalance();
		std::cout << " Interest Rate: " << account1.get_Saving_Annual_Rate() << std::endl;
	}
}
