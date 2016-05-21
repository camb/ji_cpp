// Chapter 16 Practice Problem 5
// Write a recursive algorithm to solve the towers of Hanoi problem.

#include <iostream>

using namespace std;

void printTowers(int towers[4][3]);

int solveHanoi(int towers[4][3], int height, int column);

int main ()
{
    // Multidimensional array for the towers that will hold disk width values. The array is capable of holding 4 disks and has 3 columns
    int towers[4][3];
    // When printing it will be displayed as:
    // [4,0][4,1][4,2]
    // [3,0][3,1][3,2]
    // [2,0][2,1][2,2]
    // [1,0][1,1][1,2]
    // [0,0][0,1][0,2]
    // so that 0 functions as the 'bottom' of the tower but it is viewed upright

    // Set initial values to 0, ie. no disk
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            towers[i][j] = 0;
        }
    }

    // Build initial left column disk tower
    for (int i = 0; i < 4; i++)
    {
        towers[i][0] =  4 - i;
    }

    solveHanoi(towers, 0, 0);

    // TODO create a recursive function to move disks
}

void printTowers(int towers[4][3])
{
    for (int i = 3; i > -1; i--)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << towers[i][j] << "\t";
        }
        cout << endl;
    }

    for (int i = 0; i < 17; i++)
    {
        cout << "=";
    }
    cout << endl;
}

int solveHanoi(int towers[4][3], int height, int column)
{
    cout << "HEIGHT: " << height << " COLUMN: " << column << endl;
    // Easier variable to work with for the current location value
    int cur = towers[height][column];

    // If value above current value you're trying to move, recurvively call solve hanoi on that tile
    if (height != 3 && towers[height + 1][column] != 0)
    {
        solveHanoi(towers, height + 1, column);
    }
    else
    {
        // Display towers after each iteration to show steps.
        printTowers(towers);
    }

    // Base case that will exit recusion
    if (towers[0][2] == 4 &&
        towers[1][2] == 3 &&
        towers[2][2] == 2 &&
        towers[3][2] == 1)
    {
        cout << "The tower is solved!\n";
        return 0;
    }

    // Loop over colums to find available openings
    int top0 = 0;
    int top1 = 0;
    int top2 = 0;
    for (int c = 0; c < 3; c++)
    {
        for (int h = 3; h >= 0; h--)
        {
            if 
        }
    }

    for (int c = 0; c < 3; c++)
    {
        // Don't search the current value's column
        if (c == column)
        {
            continue;
        }
        // If a column is open, use it
        else if (towers[0][c] == 0)
            {
                towers[height][column] = 0;
                towers[0][c] = cur;
                if (height > 0)
                {
                    solveHanoi(towers, height - 1, column);
                }
            }
    }

    // If there was no space for the cur value to move to,
    // Find and move the smallest value recursively and then run again
    // if (foundSpot == false && cur != 1)
    // {
    //     for (int c = 0; c < 3; c++)
    //     {
    //         for (int h = 0; h < 4; h++)
    //         {
    //             if (towers[c][h] == 1)
    //             {
    //                 cout << "BYE!\n";
    //                 solveHanoi(towers, h, c);
    //                 solveHanoi(towers, height, column);
    //             }
    //         }
    //     }
    // }
}