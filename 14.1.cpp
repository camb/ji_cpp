// Chapter 14 Practice Problem 1

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main ()
{
    srand( time( NULL ) );
    int t_height = rand() % 8 + 5;
    int t_length = rand() % 8 + 5;
    int padding = (t_length * 6 - 21) / 2;
    for (int i = 0; i < padding; i++)
        cout << "_";
    cout << "Multiplication table";
    for (int i = 0; i < padding + 1; i++)
        cout << "_";
    cout << endl;

    int **p_p_multtable;
    p_p_multtable = new int*[t_height];
    for ( int i = 0; i < t_height; i++)
    {
        p_p_multtable[i] = new int[t_length];
    }

    for ( int i = 0; i < t_height; i++)
    {
        for ( int j = 0; j < t_length; j++)
        {
            if ( i == 0 )
                p_p_multtable[i][j] = j;
            else if ( j == 0 )
                p_p_multtable[i][j] = i;
            else
                p_p_multtable[i][j] = i * j;
            if ( p_p_multtable[i][j] < 10 )
                cout << "  " << p_p_multtable[i][j] << " | ";
            else if ( p_p_multtable[i][j] > 99 )
                cout << p_p_multtable[i][j] << " | ";
            else
                cout << " " << p_p_multtable[i][j] << " | ";
        }    
        cout << endl;
    }

    for ( int i = 0; i < t_height; i++)
    {
        delete p_p_multtable[i];
    }
    delete [] p_p_multtable;
    return 0;
}