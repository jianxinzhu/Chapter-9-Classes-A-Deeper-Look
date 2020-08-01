/*
name: jianxin zhu
date: july/31/2020
*/
#include<string>
#ifndef DATE_H
#define DATE_H


class Date
{
public:
	static const unsigned int monthPerYear = 12;
	Date();
	Date(unsigned int, unsigned int, unsigned int);
	Date(unsigned int, unsigned int);
	Date(const std::string&, unsigned int, unsigned int);


	void set_Day(unsigned int);
	void set_Month(unsigned int);
	void set_Year(unsigned int);

	unsigned int get_Day() const;
	unsigned int get_Month() const;
	unsigned int get_Year() const;

	void displayTimeSlash() const;
	void displayTimeString() const;
	void displayTimeDay() const;

	unsigned int coverToDay() const;
	std::string coverToMonth() const;
	void coverDayToMonth(unsigned int);
	void coverStringToNum(const std::string&);
	




private:
	unsigned int day;
	unsigned int month;
	unsigned int year;


	unsigned int checkDay(int) const;
};
#endif
