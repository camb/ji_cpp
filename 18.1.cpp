// Chapter 18 Practice Problem 1
// Implement a small address book program that allows users to enter names and email addresses, remove or change entries, and list the entries in their address book. Don’t worry about saving the address book to disk; it’s ok to lose the data when

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct entry
{
	string name;
	string address;
};


int main ()
{
	int command = 1;

	while (command != 0)
	{

		cout << "What would you like to do?\n";
		cout << "0- Exit program 1- Add entry 2- Remove entry 3- List Entry\n";
		cin >> command;
		switch (command)
		{
			case 0:
				break;
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
		}
	}
	// TODO enter name/address
	// TODO Remove/change entry
	// TODO List entries   
}