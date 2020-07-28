/*
name: jianxin zhu
date: july/27/2020
*/

#include<array>
#include<sstream>
#include<stdexcept>
#include"Date.h"

using namespace std;

Date::Date(unsigned int mn, unsigned dy, unsigned int yr)
	: month(mn), day(checkDay(dy)), year(yr) 
{
	if (mn < 1 || mn > monthsPerYear) 
	{
		throw invalid_argument("month must be 1-12");
	}

}

string Date::toString() const {
	ostringstream output;
	output << month << '/' <<day <<'/'<< year;
	return output.str();
}

unsigned int Date::checkDay(unsigned int testDay) const {
	static const array<unsigned int, monthsPerYear + 1> daysPerMonth{
		0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (testDay > 0 && testDay <= daysPerMonth[month]) {
		return testDay;
	}
	if (month == 2 && testDay == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
		return testDay;
	}
	throw invalid_argument("Invalid day for current month and year");
}
