/*
name: jianxin zhu
date: Aug/01/2020
*/

#ifndef SAVINGACCOUNT_H
#define SAVINGACCOUNT_H

class SavingAccount
{
public:
	explicit SavingAccount(double);

	void calculatingBalance();

	static void modify_Rate(double);

	static double get_Saving_Annual_Rate();
private:
	double saving_Balance = 0.0;
	static double saving_Annual_Rate;
};
#endif
