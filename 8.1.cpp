// Chapter 8 Practice Problem 1

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    srand( time( NULL ) );
    int flip = 0;
    flip = rand() % 2;
    // flip the coin
    if ( flip == 0 )
        cout << "Heads\n";
    else if ( flip == 1 )
        cout << "Tails\n";
}