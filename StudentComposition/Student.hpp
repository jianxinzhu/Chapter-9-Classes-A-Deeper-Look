/*
name: jianxin zhu
date: july/27/2020
*/

#include<string>

#ifndef STUDENT_H
#define STUDENT_H

#include"Date.h"
#include"Name.h"


class Student
{
public:
	Student(const Name&, const Date&, const std::string&, const std::string&, int);

	std::string toString() const;

	void set_Email_Address(const std::string&);
	void set_Gender(const std::string&);
	void set_Registration_Number(int);

	std::string get_Email_Address() const;
	std::string get_Gender() const;
	int get_Registration_Number() const;


private:
	const Name studentName;
	const Date yearOfBirth;

	std::string student_Gender;
	std::string email_Address;
	int registration_Number;
};
#endif 

