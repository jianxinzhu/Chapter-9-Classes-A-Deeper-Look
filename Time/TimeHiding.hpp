/*
name: jianxin zhu
date: aug/01/2020
*/

#include<string>

#ifndef TIME_H
#define TIME_H

class Time
{
public:

	static const unsigned int secondPerHour = 3600;
	static const unsigned int secondPerMinute = 60;
	explicit Time(unsigned int =0, unsigned int=0, unsigned int=0);
	~Time();

	Time& set_Time(unsigned int, unsigned int, unsigned int);
	Time& set_Hour(unsigned int);
	Time& set_Minute( unsigned int);
	Time& set_Second(unsigned int);

	unsigned int get_Hour() const;
	unsigned int get_Minute() const;
	unsigned int get_Second() const;
	unsigned int get_SecondAfterMidNight() const;



	std::string toUniversalString() const;
	std::string toStandardString() const;


private:
	unsigned int hour{ 0 };
	unsigned int minute{ 0 };
	unsigned int second{ 0 };

	bool isMidnight = false;

	unsigned int secondAfterMidNight = 0;


};
#endif
