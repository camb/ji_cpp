// Chapter 16 Practice Problem 1
// Write a recursive algorithm to compute the power function pow(x, y) = x^y

#include <iostream>

using namespace std;

int power(int base, int exponent);

int main ()
{
    // Below should output 64
    cout << power(4, 3) << endl;

    // Below should output 10000
    cout << power(10, 4) << endl;

    // Below should output 4913
    cout << power(17, 3) << endl;
}


int power(int base, int exponent)
{
    if (exponent == 1)
    {
        return base;
    }

    return base * power(base, exponent - 1);
}