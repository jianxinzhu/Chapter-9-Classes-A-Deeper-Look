/*
name: jianxin zhu
date: july/27/2020
*/

#include<sstream>


#include"Student.h"
#include"Date.h"
#include"Name.h"

Student::Student(const Name& fullname, const Date& birth, const std::string& email, const std::string& gender, int number)
	:studentName(fullname), yearOfBirth(birth)
{
	set_Email_Address(email);
	set_Gender(gender);
	set_Registration_Number(number);
}

void Student::set_Email_Address(const std::string& email_Address)
{
	bool flag = false;
	const std::string s = ".com";
	std::string word = "";
	unsigned int strLength = email_Address.length();

	for (unsigned int i = strLength - 4; i < strLength; i++)
	{
		word += email_Address[i];
	}

	for (unsigned int i = 0; i < strLength; i++)
	{
		if (email_Address[i] == '@')
		{
			flag = true;
		}
	}

	if ((s == word) && flag)
	{
		this->email_Address = email_Address;
	}
	else
	{
		this->email_Address = "*Invaild Address";
	}
}
void Student::set_Gender(const std::string& student_Gender)
{
	if (student_Gender == "Male" || student_Gender == "Female")
	{
		this->student_Gender = student_Gender;
	}
	else
	{
		this->student_Gender = "*Invaild Gender";
	}
}
void Student::set_Registration_Number(int registration_Number)
{
	this->registration_Number = registration_Number;
}
std::string Student::get_Email_Address() const
{
	return email_Address;
}
std::string Student::get_Gender() const
{
	return student_Gender;
}
int Student::get_Registration_Number() const
{
	return registration_Number;
}

std::string Student::toString() const
{
	std::ostringstream output;

	output << "Student's Name: " << studentName.toString() << "\nGender: " << get_Gender()
		<<"\nDOB: "<<yearOfBirth.toString()<< "\nRegistration Number: " << get_Registration_Number()
		<< "\nStudent's Email: "<< get_Email_Address() << std::endl;

	return output.str();
}
