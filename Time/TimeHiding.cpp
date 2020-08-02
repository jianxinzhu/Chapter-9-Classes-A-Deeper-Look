/*
name: jianxin zhu
date: aug/01/2020
*/

#include<sstream>
#include<iomanip>

#include"Time.h"

Time::Time(unsigned int h, unsigned int m, unsigned int s)
{
	set_Time(h, m, s);

}
Time::~Time()
{

}
Time& Time::set_Time(unsigned int h, unsigned int m, unsigned int s)
{
	set_Hour(h);
	set_Minute(m);
	set_Second(s);

	return *this;
}
Time& Time::set_Hour(unsigned int h)
{
	if (h > 0 && h < 24)
	{
		hour = h;
		
		if (hour < 5)
		{
			secondAfterMidNight += h * secondPerHour;
			isMidnight = true;
		}
		else
		{
			secondAfterMidNight = 0;
			isMidnight = false;
		}
	}

	return *this;
}
Time& Time::set_Minute(unsigned int m)
{
	if (m > 0 && m < 60)
	{
		minute = m;

		if (isMidnight)
		{
			secondAfterMidNight += m * secondPerMinute;
		}

	}
	return *this;
}
Time& Time::set_Second(unsigned int s)
{
	if (s > 0 && s < 60)
	{
		second = s;

		if (isMidnight)
		{
			secondAfterMidNight += s;
		}

	}

	return *this;
}

unsigned int Time::get_Minute() const
{
	return minute;
}
unsigned int Time::get_Hour() const
{
	return hour;
}
unsigned int Time::get_Second() const
{
	return second;
}
unsigned int Time::get_SecondAfterMidNight() const
{
	return secondAfterMidNight;
}

std::string Time::toUniversalString() const
{
	std::ostringstream output;
	
	if (isMidnight)
	{
		output << "MidNight: " << get_SecondAfterMidNight() << std::endl;
		return output.str();

	}
	else
	{
		output << std::setw(3) << get_Hour() << ":" << std::setw(3) << get_Minute()
			<< ":" << std::setw(3) << get_Second() << std::endl;
		return output.str();
	}

}

std::string Time::toStandardString() const 
{
	std::ostringstream output; 
	output << ((get_Hour() == 0 || get_Hour() == 12) ? 12 : get_Hour() % 12) 
		<< ":" << std::setfill('0') << std::setw(2) << get_Minute() << ":" << std::setw(2) 
		<< get_Second() << (hour < 12 ? " AM" : " PM"); 
	return output.str();
}
