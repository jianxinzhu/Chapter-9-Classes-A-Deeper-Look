/*
name: jianxin zhu
date: july/31/2020
*/

#include"Date.h"
#include<stdexcept>
#include<iostream>
#include<array>
#include<ctime>


static const std::array<unsigned int, Date::monthPerYear>dayPerMonth{ 31,28,31,30,31,30,31,31,30,31,30,31 };
static const std::array<std::string, Date::monthPerYear>monthOfString{ "January","Ferbuary","March","April","May","June","July","August","September","October","Novermber","December" };

Date::Date(unsigned int m, unsigned int d, unsigned y)
{
	set_Month(m);
	set_Day(d);
	set_Year(y);
}
Date::Date()
{
	std::time_t t = time(0);
	tm* now = localtime(&t);

	int y = now->tm_year + 1900;
	int m = now->tm_mon + 1;
	int d = now->tm_mday;

	set_Year(y);
	set_Month(m);
	set_Day(d);
}
Date::Date(const std::string& m, unsigned int d, unsigned int y)
{
	coverStringToNum(m);
	set_Day(d);
	set_Year(y);

}
Date::Date(unsigned int d, unsigned int y)
{
	coverDayToMonth(d);
	set_Year(y);
}

void Date::set_Day(unsigned int day)
{
	this->day = checkDay(day);
}
void Date::set_Month(unsigned int month)
{
	if (month > 0 && month <= 12)
	{
		this->month = month;
	}
	else
	{
		this->month = 1;
	}
}
void Date::set_Year(unsigned int year)
{
	if (year > 1990 && year <= 2200)
	{
		this->year = year;
	}
	else
	{
		this->year = 1990;
	}
}
unsigned int Date::get_Day() const
{
	return day;
}
unsigned int Date::get_Month() const
{
	return month;
}
unsigned int Date::get_Year() const
{
	return year;
}

unsigned int Date::checkDay(int testday) const
{

	if (testday > 0 && testday <= dayPerMonth[month - 1])
	{
		return testday;
	}
	if (month == 2 && testday == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
	{
		return testday;
	}

	throw std::invalid_argument("Invalid day for current month");

}
void Date::coverDayToMonth(unsigned int testday)
{
	
	if (testday < 1 && testday>366)
	{
		throw std::invalid_argument("Invalid day: (0-365/366)");
	}

	int monthOfthis = 1;

	for (int i = 0; i < monthPerYear; i++)
	{
		if (testday > dayPerMonth[i])
		{
			testday -= dayPerMonth[i];
			monthOfthis++;
		}
		else
		{
			break;
		}
	}

	set_Month(monthOfthis);
	set_Day(testday);
}

void Date::coverStringToNum(const std::string& stringMonth)
{
	int monthOfthis = 0;
	for (int i = 0; i < monthPerYear; i++)
	{
		if (stringMonth == monthOfString[i])
		{
			monthOfthis = i + 1;
		}
	}

	set_Month(monthOfthis);
}
unsigned int Date::coverToDay() const
{
	int totalDay = 0;
	int totalMonth = get_Month();

	for (int i = 0; i < totalMonth-1; i++)
	{
		totalDay += dayPerMonth[i];
	}
	totalDay += get_Day();

	return totalDay;

}
std::string Date::coverToMonth() const
{
	int monthOfthis = get_Month();

	std::string thisMonth = monthOfString[monthOfthis - 1];

	return thisMonth;

}

void Date::displayTimeSlash() const
{
	std::cout << get_Month() << "/" << get_Day() << "/" << get_Year() << std::endl;
}
void Date::displayTimeDay() const
{
	std::cout << coverToDay() << "/" << get_Year() << std::endl;
}
void Date::displayTimeString() const
{
	std::cout << coverToMonth() << " " << get_Day() << " " << get_Year() << std::endl;
}
