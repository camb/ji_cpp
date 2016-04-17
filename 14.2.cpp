// Chapter 14 Practice Problem 12

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void multiTable(int h, int w, int d);

int main ()
{
    srand( time( NULL ) );
    int t_height = rand() % 8 + 3;
    int t_width = rand() % 7 + 3;
    int t_depth = rand() % 3 + 2;

    multiTable(t_height, t_width, t_depth);
}


void multiTable(int t_h, int t_w, int t_d)
{
    cout << "Multiplication table\n";
    cout << "Height: " << t_h << " Width:" << t_w << " Depth: " << t_d << endl;
    int ***p_p_multtable;
    p_p_multtable = new int**[t_d];
    
    for (int i = 0; i < t_d; i++)
    {
        p_p_multtable[i] = new int*[t_h];
        for (int j = 0; j < t_h; j++)
        {
            p_p_multtable[i][j] = new int[t_w];
        }
    }

    for (int i = 0; i < t_d; i++)
    {
        for (int j = 0; j < t_h; j++)
        {
            for (int x = 0; x < t_w; x++)
            {
                p_p_multtable[i][j][x] = i * j * x;

                if ( p_p_multtable[i][j][x] < 10 )
                    cout << "  " << p_p_multtable[i][j][x] << " | ";
                else if ( p_p_multtable[i][j][x] > 99 )
                    cout << p_p_multtable[i][j][x] << " | ";
                else
                    cout << " " << p_p_multtable[i][j][x] << " | ";
                // cout << p_p_multtable[i][j][x];
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < t_d; i++)
    {
        for (int j = 0; j < t_h; j++)
        {
            delete p_p_multtable[i][j];
        }
        delete  [] p_p_multtable[i];
    }
    delete [] p_p_multtable;
}