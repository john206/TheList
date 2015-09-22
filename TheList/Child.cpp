#include "stdafx.h"
#include "Child.h"
#include <iostream>

Child::Child() : fName(""), lName(""), age(0){}

Child::Child(string fName, string lName, int age) : fName(fName), lName(lName), age(age){}

Child::Child(const Child &c1)
{
	
	this->fName = c1.fName;
	this->lName = c1.lName;
	this->age = c1.age;
}

Child::~Child()
{
	
}

string Child::getLastName() const
{
	return lName;
}

string Child::getFirstName() const
{
	return fName;
}

int Child::getAge() const
{
	return age;
}

bool Child::operator==(const Child& c1)
{
	if (lName == c1.lName && fName == c1.fName && age == c1.age)
		return true;
	else
		return false;
}

bool Child::operator!=(const Child& c1)
{
	if (*this == c1)
		return false;
	else
		return true;
}

bool Child::operator<(const Child& c1)
{
	if (lName < c1.lName)
		return true;
	else if (lName == c1.lName && fName < c1.fName)
		return true;
	else if (lName == c1.lName && fName == c1.fName && age < c1.age)
		return true;
	else
		return false;
}

bool Child::operator>(const Child& c1)
{
	if (*this < c1)
		return false;
	else if (*this == c1)
		return false;
	else
		return true;
}

bool Child::operator<=(const Child &c1)
{
	if (*this < c1 || *this == c1)
		return true;
	else
		return false;
}

bool Child::operator>=(const Child &c1)
{
	if (*this > c1 || *this == c1)
		return true;
	else
		return false;
}

istream& operator>>(istream &in, Child &c1)
{
	in >> c1.fName;
	in >> c1.lName;
	in >> c1.age;
	return in;
}

ostream& operator<<(ostream &out, const Child &c1)
{
	out << c1.getFirstName() << c1.getLastName() << c1.getAge();
	return out;
}
