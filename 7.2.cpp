// Chapter 7 Practice Problem 2

#include <iostream>

using namespace std;

int main ()
{
    for (int i = 4; i > 0; i--)
    {
        cout << "On the ";
        switch (i)
        {
            case 4:
                cout << "first";
                break;
            case 3:
                cout << "second";
                break;
            case 2:
                cout << "third";
                break;
            case 1:
                cout << "fourth";
                break;
        }
        cout << " day of Christmas\n";
        cout << "My true love sent to me:\n";
        switch (i)
        {
        case 1:
            cout << "Four Calling Birds\n";
        case 2:
            cout << "Three French Hens\n";
        case 3:
            cout << "Two Turtle Doves\n";
            cout << "And a Partridge in a Pear Tree.\n";
            break;
        case 4:
            cout << "A Partridge in a Pear Tree.\n";
            break;
        }
    }
}