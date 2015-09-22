#ifndef CHILD_H
#define CHILD_H

#include <string>
using namespace std;

class Child
{
	friend istream& operator>>(istream &in, Child &c1);
	friend ostream& operator<<(ostream &out, const Child &c1);

public:
	Child();
	Child(string fName, string lName, int age);
	Child(const Child &c1);
	~Child();

	string getLastName() const;
	string getFirstName() const;
	int getAge() const;

	bool operator==(const Child &c1);
	bool operator!=(const Child &c1);

	bool operator<(const Child &c1);
	bool operator>(const Child &c1);

	bool operator<=(const Child &c1);
	bool operator>=(const Child &c1);

private:
	string fName, lName;
	int age;
};

#endif // CHILD_H
