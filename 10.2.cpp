// Chapter 10 Practice Problem 2

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    srand( time( NULL ) );
    int array[50];
    for (int i = 0; i < 50; i++)
        array[i] = rand() % 100;

    int highest = array[0], lowest = array[0], sum = 0;
    float average = 0;
    for (int i=0; i < 50; i++)
    {
        if (array[i] > highest)
            highest = array[i];
        if (array[i] < lowest)
            lowest = array[i];
        sum += array[i];
    }
    cout << "Highest: " << highest << endl;
    cout << "Lowest: " << lowest << endl;
    cout << "Average: " << sum / 50.0 << endl;

    for (int i = 0; i < 50; i++)
    {
        cout << array[i] << endl;
    }
}