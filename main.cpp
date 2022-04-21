#include <iostream>

#include "fraction.hpp"

using namespace std;


int main()
{
	Fraction a(4, 5);
	Fraction b(2);
	Fraction c;

	c = a * b;

	cout << a << " * " << b << " = " << c << endl;

	if (a == b)
	{
		cout << a << " is equal to " << b << endl;
	}
	else 
	{
		cout << a << " is not equal to " << b << endl;
	}

	return 0;
}
