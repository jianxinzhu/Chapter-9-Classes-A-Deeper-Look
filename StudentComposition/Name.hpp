/*
name: jianxin zhu
date: jult/27/2020
*/

#include<string>

#ifndef NAME_H
#define NAME_H

class Name
{
public:
	explicit Name(const std::string & = "Mr.", const std::string & = "", const std::string & = "", const std::string & = "");

	void set_Name(const std::string&, const std::string&, const std::string&, const std::string&);
	void set_First_Name(const std::string&);
	void set_Last_Name(const std::string&);
	void set_Salutation(const std::string&);
	void set_Middle_Name(const std::string&);

	std::string get_First_Name() const;
	std::string get_Last_Name() const;
	std::string get_Middle_Name() const;
	std::string get_Salutation() const;

	std::string toString() const;

private:
	std::string salutation;
	std::string firstName;
	std::string lastName;
	std::string middleName;


};
#endif
