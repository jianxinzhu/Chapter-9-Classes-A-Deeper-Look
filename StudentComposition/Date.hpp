/*
name: jianxin zhu
date: july/27/2020
*/

#include<string>

#ifndef DATE_H
#define DATE_H

class Date {
public:
	static const unsigned int monthsPerYear{ 12 };
	explicit Date(unsigned int = 1, unsigned int = 1, unsigned int = 1900);
	std::string toString() const;

private:
	unsigned int month;
	unsigned int day;
	unsigned int year;

	unsigned int checkDay(unsigned int) const;

};
#endif
