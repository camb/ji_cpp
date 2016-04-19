// Chapter 14 Practice Problem 3

#include <iostream>

using namespace std;

int main ()
{
    int t_height = 4;
    int t_width = 4;

    int **table;
    table = new int*[t_height];
    for ( int i = 0; i < t_height; i++)
    {
        table[i] = new int[t_width];
    }

    for ( int i = 0; i < t_height; i++)
    {
        for ( int j = 0; j < t_width; j++)
        {
            cout << &table[i][j];
        }    
        cout << endl;
    }

    for ( int i = 0; i < t_height; i++)
    {
        delete table[i];
    }
    delete [] table;
    return 0;
}