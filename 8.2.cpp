// Chapter 8 Practice Problem 2

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    srand( time( NULL ) );
    int num = 0;
    num = rand() % ( 100 - 1 + 1 ) + 1;
    int guess = 0;
    do
    {
        cout << "Guess what the number is: ";
        cin >> guess;
        if ( guess < num )
            cout << "Too low!" << endl;
        else if ( guess > num )
            cout << "Too high!" << endl;
        else if ( guess == num )
            cout << "Yes! The number was " << num << endl;
    } while ( guess != num );
}