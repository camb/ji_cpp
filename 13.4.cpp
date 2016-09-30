// Chapter 12 Practice Problem 4

#include <iostream>

using namespace std;

void doMath(int *multiplied, int *added);

int main ()
{
    int int1 = 0, int2 = 0;
    int *multiplied, *added;
    multiplied = &int1;
    added = &int2;

    doMath ( & int1, & int2 );

    cout << "Multiplied: " << *multiplied << endl;
    cout << "Added: " << *added << endl;
    return 0;
}

void doMath(int *multiplied, int *added)
{
    int temp1 = 0, temp2 = 0;
    cout << "Enter your first integer: ";
    cin >> temp1;
    cout << "Enter your second integer: ";
    cin >> temp2;

    *multiplied = temp1 * temp2;
    *added = temp1 + temp2;
}