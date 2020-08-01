/*
name: jianxin zhu
date: aug/01/2020
*/

#include"SavingAccount.h"
#include<iostream>

double SavingAccount::saving_Annual_Rate = 0.00;

SavingAccount::SavingAccount(double balance)
	:saving_Balance(balance)
{

}
void SavingAccount::calculatingBalance()
{
	saving_Balance += (saving_Balance * saving_Annual_Rate) / 12.0;

	std::cout << "Balance: " << saving_Balance;
}
double SavingAccount::get_Saving_Annual_Rate()
{
	return saving_Annual_Rate;
}
void SavingAccount::modify_Rate(double rate)
{
	if (rate > 0.00 && rate < 1.00)
	{
		saving_Annual_Rate = rate;
	}
}
