// CHapter 10 Practice Problem 1

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int findSmallestRemainingElement ( int array[], int size, int index);
void swap (int array[], int first_index, int second_index);
void sort (int array[], int size)
{
    for ( int i = 0; i < size; i++ )
    {
        int index = findSmallestRemainingElement(array, size, i);
        swap( array, i, index );
    }
}

int findSmallestRemainingElement ( int array[], int size, int index)
{
    int index_of_smallest_value = index;
    for (int i = index + 1; i < size; i++)
    {
        if ( array[ i ] < array[ index_of_smallest_value ] )
            index_of_smallest_value = i;
    }
    return index_of_smallest_value;
}

void swap (int array[], int first_index, int second_index)
{
    int temp = array[ first_index ];
    array[ first_index ] = array[ second_index ];
    array[ second_index ] = temp;
}

void displayArray (int array[], int size)
{
    cout << "{";
    for ( int i = 0; i < size; i++ )
    {
        if ( i != 0 )
            cout << ", ";
        cout << array[ i ];
    }
    cout << "}";
}

int main ()
{
    srand( time( NULL ) );
    int array_size = rand() % 15;
    cout << array_size << endl;
    int array[ array_size ];
    for ( int i = 0; i < array_size; i++ )
    {
        array[ i ] = rand() % 100;
    }
    cout << "Original array: ";
    displayArray( array, array_size );
    cout << endl;

    sort( array, array_size );

    cout << "Sorted array: ";
    displayArray( array, array_size );
    cout << endl;
}