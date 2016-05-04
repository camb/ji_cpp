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

int growArray(int* p_values, int *size);
// TODO Void copy array function

int main ()
{
	friendTalk* p_friend = new friendTalk[4];

	string cont = "yes";
	while (cont != "no")
	{
		cout << "Enter a friends name:\n";
		// TODO getline below
		// cin >> *p_friend.name;

		cout << "How many days ago did you talk?\n";
		// TODO Don't allow negative values below, make this a loop that requires positive ints
		// cin >> *p_friend.days_since;

		cout << "Add more? yes or no\n";
		cin >> cont;
		// TODO If we are continuing and the array is not large enough; run copy and double array function
	}

	// TODO input option for function sort by days since
	// TODO input option for function 

	return 0;
}

// TODO copy function definition
int growArray(int* p_values, int *size)
{
	*size *= 2;
	int *p_new_values = new int[*size];
	for (int i = 0; i < (*size / 2); i++)
	{
		p_new_values[i] = p_values[i];
	}
	delete [] p_values;
	return *p_new_values;
}