// Chapter 14 Practice Problem 4
// Write a program that lets users keep track of the last time they talked to each of their friends.
// Users should be able to add new friends (as many as they want!) and store the number of days ago that they last talked to each friend.
// Let users update this value (but don't let them put in bogus numbers like negative values). Make it possible to display the list sorted by the names of the frinds of by how recently it was since they talked to each friend.

#include <iostream>
#include <string>

using namespace std;

struct friendTalk
{
	string name;
	int days_since;
};

int main ()
{
	friendTalk* p_friend = new friendTalk[4];

	string cont = "yes";
	while (cont != "no")
	{


		cout << "Add more? yes or no\n";
		cin >> cont;
	}
	return 0;
}