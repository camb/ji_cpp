// Chapter 8 Practice Problem 3

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    srand( time( NULL ) );
    int num = 0;
    num = rand() % ( 100 - 1 + 1 ) + 1;
    int guess = 50;
    int max_guess = 100;
    int min_guess = 1;
    do
    {
        cout << "Guess what the number is: " << guess << endl;
        if ( guess < num )
        {
            cout << "Too low!" << endl;
            min_guess = guess;
            guess = ( guess + max_guess ) / 2;
        }
        else if ( guess > num )
        {
            cout << "Too high!" << endl;
            max_guess = guess;
            guess = ( guess + min_guess ) / 2;
        }
    } while ( guess != num );
    if ( guess == num )
        {
            cout << "Yes! The number was " << num << endl;
        }
}