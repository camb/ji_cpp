// Chapter 12 Practice Problem 5

#include <iostream>

using namespace std;

void displayStackAddresses();

int main ()
{
	displayStackAddresses();
}

void displayStackAddresses()
{
	int int1, int2;

	if ( &int1 > &int2 )
		cout << "int1: " << &int1 << '\t' << "int2:" << &int2 << endl;
	else if ( &int2 > &int1 )
		cout << "int2:" << &int2 << '\t' << "int1: " << &int1 << endl;
}
