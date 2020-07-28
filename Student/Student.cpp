/*
name: jianxin zhu
date: july/27/2020
*/
#include"Student.h"
#include<sstream>
#include<stdexcept>

Student::Student(const std::string& first, const std::string& last, const std::string& middle,
	const std::string& email, const std::string& gender, unsigned int year, long int number)
{
	set_Student_Information(first, last, middle, email, gender, year, number);
}
void Student::set_Student_Information(const std::string& first, const std::string& last, const std::string& middle,
	const std::string& email, const std::string& gender, unsigned int year, long int number)
{
	set_First_Name(first);
	set_Last_Name(last);
	set_Middle_Name(middle);
	set_Email_Address(email);
	set_Gender(gender);
	set_registrationNumber(number);
	set_yearOfBirth(year);

}
void Student::set_First_Name(const std::string& first_Name)
{
	if (first_Name == "")
	{
		throw std::invalid_argument("FirstName is EMPTY");
	}
	else
	{
		this->first_Name = first_Name;
	}
}
void Student::set_Last_Name(const std::string& last_Name)
{
	if (last_Name == "")
	{
		throw std::invalid_argument("LastName is EMPTY");
	}
	else
	{
		this->last_Name = last_Name;
	}
}
void Student::set_Middle_Name(const std::string& middle_Name)
{
	if (middle_Name == "")
	{
		throw std::invalid_argument("Middle is EMPTY");
	}
	else
	{
		this->middle_Name = middle_Name;
	}
}
void Student::set_Gender(const std::string& gender)
{
	if (gender == "Male" || gender == "Female")
	{
		this->gender = gender;
	}
	else
	{
		throw std::invalid_argument("Invalid Gender");
	}
}
void Student::set_Email_Address(const std::string& email_Address)
{
	bool flag = false;
	const std::string s1 = ".com";
	std::string word = "";

	for (unsigned int i = 0; i < email_Address.length(); i++)
	{
		if (email_Address[i] == '@')
		{
			flag = true;
		}

		if (i >= email_Address.length() - 4)
		{
			word += email_Address[i];
		}
	}

	if (flag && (s1 == word))
	{
		this->email_Address = email_Address;
	}
	else
	{
		throw std::invalid_argument("Invalid Email Address");
	}
}
void Student::set_yearOfBirth(unsigned int yearOfBirth)
{
	this->yearOfBirth = yearOfBirth;
}
void Student::set_registrationNumber(long int registration_Number)
{
	this->registreation_Number = registration_Number;
}

std::string Student::get_First_Name() const
{
	return first_Name;
}
std::string Student::get_Last_Name() const
{
	return last_Name;
}
std::string Student::get_Middle_Name() const
{
	return middle_Name;
}
std::string Student::get_Email_Address() const
{
	return email_Address;
}
std::string Student::get_Gender() const
{
	return gender;
}
unsigned int Student::get_yearOfBirth() const
{
	return yearOfBirth;
}
long int Student::get_registrationNumber() const
{
	return registreation_Number;
}

std::string Student::toString() const
{
	std::ostringstream output;

	output << "Student's Name: " << get_First_Name() << "." << get_Last_Name() << " " << get_Middle_Name()
		<< "\nDOB: " << get_yearOfBirth() << "\nGender: " << get_Gender() << "\nEmail Address: "
		<< get_Email_Address() << "\nRegistration Number: " << get_registrationNumber() << std::endl;

	return output.str();
}
