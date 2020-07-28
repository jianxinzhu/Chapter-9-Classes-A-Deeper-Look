/*
name: jianxin zhu
date: july/27/2020
*/
#include<sstream>
#include"Name.h"

Name::Name(const std::string& sal, const std::string& first, const std::string& last, const std::string& middle)
{
	set_Name(sal, first, last, middle);
}
void Name::set_Name(const std::string& salutation, const std::string& firstName, const std::string& lastName, const std::string& middleName)
{
	set_Salutation(salutation);
	set_First_Name(firstName);
	set_Last_Name(lastName);
	set_Middle_Name(middleName);
}
void Name::set_Salutation(const std::string& salutation)
{
	this->salutation = salutation;
}
void Name::set_First_Name(const std::string& firstName)
{
	this->firstName = firstName;
}
void Name::set_Last_Name(const std::string& lastName)
{
	this->lastName = lastName;
}
void Name::set_Middle_Name(const std::string& middleName)
{
	this->middleName = middleName;
}

std::string Name::get_Salutation() const
{
	return salutation;
}
std::string Name::get_First_Name() const
{
	return firstName;
}
std::string Name::get_Last_Name() const
{
	return lastName;
}
std::string Name::get_Middle_Name() const
{
	return middleName;
}

std::string Name::toString() const
{
	std::ostringstream output;

	output << get_Salutation() << "." << get_First_Name() << " " << get_Last_Name() << " " << get_Middle_Name();

	return output.str();
}
