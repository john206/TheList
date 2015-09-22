#include "stdafx.h"
#include "Bird.h"
#include <iostream>


Bird::Bird() : name(""), id(0){}

Bird::Bird(string name, int id) : name(name), id(id){}

Bird::Bird(const Bird &b1)
{
	this->name = b1.name;
	this->id = b1.id;
}

Bird::~Bird()
{
	
}

string Bird::getName() const
{
	return name;
}

int Bird::getID() const
{
	return id;
}

bool Bird::operator==(const Bird& b1)
{
	if (id == b1.id && name == b1.name)
		return true;
	else
		return false;
}

bool Bird::operator!=(const Bird& b1)
{
	if (*this == b1)
		return false;
	else
		return true;
}

bool Bird::operator<(const Bird& b1)
{
	if (id < b1.id)
		return true;
	else if (id == b1.id && name < b1.name)
		return true;
	else
		return false;
}

bool Bird::operator>(const Bird& b1)
{
	if (*this < b1)
		return false;
	else if (*this == b1)
		return false;
	else
		return true;
}

bool Bird::operator<=(const Bird &b1)
{
	if (*this < b1 || *this == b1)
		return true;
	else
		return false;
}

bool Bird::operator>=(const Bird &b1)
{
	if (*this > b1 || *this == b1)
		return true;
	else
		return false;
}

istream& operator>>(istream &in, Bird &b1)
{
	in >> b1.name;
	in >> b1.id;
	return in;
}

ostream& operator<<(ostream &out, const Bird &b1)
{
	out << b1.getName() << b1.getID();
	return out;
}
