/*
name: jianxin zhu
date: july/27/2020
*/
#include<string>

#ifndef STUDENT_H
#define STUDENT_H

class Student
{
public:
	Student(const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, unsigned int, long int);

	void set_Student_Information(const std::string&, const std::string&, const std::string&, const std::string&,
		const std::string&, unsigned int, long int);
	void set_First_Name(const std::string&);
	void set_Last_Name(const std::string&);
	void set_Middle_Name(const std::string&);
	void set_Gender(const std::string&);
	void set_Email_Address(const std::string&);

	void set_yearOfBirth(unsigned int);
	void set_registrationNumber(long int);


	std::string toString() const;
	
	std::string get_First_Name() const;
	std::string get_Last_Name() const;
	std::string get_Middle_Name() const;
	std::string get_Gender() const;
	std::string get_Email_Address() const;
	unsigned int get_yearOfBirth() const;
	long int get_registrationNumber() const;

	
private:
	std::string first_Name;
	std::string last_Name;
	std::string middle_Name;
	std::string email_Address;
	std::string gender;
	unsigned int yearOfBirth;
	long int registreation_Number;

	
};
#endif
