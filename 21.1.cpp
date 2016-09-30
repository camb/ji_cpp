// Chapter 21 Practice Problem 1
// Write a program that contains the functions add, subtract, multiply and divide. Each of these functions should take two integers, and return the result of the operation. Create a small calculator in that uses these functions. Put the function declarations into a header file, but include the source code for these functions in your source file.

#include <iostream>
#include "20.1.h"

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

float add(float x, float y) {
	return x + y;
}

float subtract(float x, float y) {
	return x - y;
}

float multiply(float x, float y) {
	return x * y;
}

float divide(float x, float y) {
	return x / y;
}
