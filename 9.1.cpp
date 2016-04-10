// Chapter 9 Practice Problem 1

#include <iostream>

using namespace std;

void translateLowNumber ( int num );
void translateChunk ( int num );

int main ()
{
    int number;
    while ( true )
    {
        cout << "Enter a number between -999,999,999 to 999,999,999 to convert to text. Enter 0 to exit: ";
        cin >> number;

        if ( number < 0 )
        {
            cout << "negative ";
            number = -number;
        }
        else if ( number == 0)
            return 0;
        
        if ( number <= 19 )
            translateLowNumber( number );
        else
        {
            // break number into 3 digit chunks
            int millions = number / 1000000;
            int thousands = ( number - ( millions * 1000000 ) ) / 1000;
            int hundreds = number - ( millions * 1000000 ) - ( thousands * 1000 );
            // int tens = hundreds - ( hundreds / 100 );
            if ( millions > 0 )
            {
                translateChunk( millions );
                cout << " million ";
            }
            if ( thousands > 0 )
            {
                translateChunk( thousands );
                cout << " thousand ";
            }
            if ( hundreds > 0 )
                translateChunk( hundreds );
            // else
                // translateChunk ( tens );
        }
        // for each chunk append magnitude
        cout << endl;
    }
}

void translateChunk ( int num )
{
    int hundreds = num / 100;
    int tens = ( num - ( hundreds * 100 ) ) / 10;
    int ones = num - ( hundreds * 100 ) - ( tens * 10 );
    if ( hundreds > 0)
    {
        translateLowNumber( hundreds );
        cout << " hundred ";
    }
    switch ( tens )
    {
    case ( 0 ):
        translateLowNumber ( ones );
        break;
    case ( 1 ):
        translateLowNumber( ( tens * 10 ) + ones );
        break;
    case ( 2 ):
        cout << "twenty ";
        break;
    case ( 3 ):
        cout << "thirty ";
        break;
    case ( 4 ):
        cout << "fourty ";
        break;
    case ( 5 ):
        cout << "fifty ";
        break;
    case ( 6 ):
        cout << "sixty ";
        break;
    case ( 7 ):
        cout << "seventy ";
        break;
    case ( 8 ):
        cout << "eighty ";
        break;
    case ( 9 ):
        cout << "ninety ";
        break;
    }
    if ( tens >= 2 )
    {
        translateLowNumber( ones );
    }
}

void translateLowNumber( int num )
{
    switch ( num )
    {
    case ( 1 ):
        cout << "one";
        break;
    case ( 2 ):
        cout << "two";
        break;
    case ( 3 ):
        cout << "three";
        break;
    case ( 4 ):
        cout << "four";
        break;
    case ( 5 ):
        cout << "five";
        break;
    case ( 6 ):
        cout << "six";
        break;
    case ( 7 ):
        cout << "seven";
        break;
    case ( 8 ):
        cout << "eight";
        break;
    case ( 9 ):
        cout << "nine";
        break;
    case ( 10 ):
        cout << "ten";
        break;
    case ( 11 ):
        cout << "eleven";
        break;
    case ( 12 ):
        cout << "twelve";
        break;
    case ( 13 ):
        cout << "thirteen";
        break;
    case ( 14 ):
        cout << "fourteen";
        break;
    case ( 15 ):
        cout << "fifteen";
        break;
    case ( 16 ):
        cout << "sixteen";
        break;
    case ( 17 ):
        cout << "seventeen";
        break;
    case ( 18 ):
        cout << "eighteen";
        break;
    case ( 19 ):
        cout << "nineteen";
        break;
    }
}