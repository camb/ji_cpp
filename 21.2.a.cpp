// Chapter 21 Practice Problem 2
// Take the program you wrote above and put the function definitions into a separate source file from the rest of your calculator code.

#include <iostream>
#include "21.2.b.cpp"

using namespace std;


int main () {
	int input;
	float x, y;
	cout << "Calculator:\nWhich function would you like to preform?\n";
	cout << "1 - add   2 - subtract   3 - multiple   4 - divide\n";
	cin >> input;
	cout << "Enter your first variable:\n";
	cin >> x;
	cout << "Enter your second variable:\n";
	cin >> y;
	cout << "The result is: ";
	switch (input)
	{
		case 1:
			cout << add(x, y) << endl;
			break;
		case 2:
			cout << subtract(x, y) << endl;
			break;
		case 3:
			cout << multiply(x, y) << endl;
			break;
		case 4:
			cout << divide(x, y) << endl;
			break;
	}
	return 0;
}
