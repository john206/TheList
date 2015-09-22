#ifndef BIRD_H
#define BIRD_H

#include <string>
using namespace std;

class Bird
{
	friend istream& operator>>(istream &in, Bird &b1);
	friend ostream& operator<<(ostream &out, const Bird &b1);

public:
	Bird();
	Bird(string name, int id);
	Bird(const Bird &b1);
	~Bird();

	string getName() const;
	int getID() const;

	bool operator==(const Bird &b1);
	bool operator!=(const Bird &b1);

	bool operator<(const Bird &b1);
	bool operator>(const Bird &b1);

	bool operator<=(const Bird &b1);
	bool operator>=(const Bird &b1);

private:
	string name;
	int id;
};

#endif // BIRD_H
