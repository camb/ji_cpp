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
    cout << "\nFinal Output:\n";
    printTowers(towers);

    return 0;
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
    // cout << "HEIGHT: " << height << " COLUMN: " << column << endl;

    // Display towers each call to show steps.
    printTowers(towers);

    // Easier variable to work with for the current location value
    int cur = towers[height][column];

    // If value above current location, recurvively call solve hanoi on that tile
    if (height != 3 && towers[height + 1][column] != 0)
    {
        solveHanoi(towers, height + 1, column);
    }

    // Base cases to exit recursive function if value is already in correct location
    if (towers[4 - cur][2] == cur)
    {
        return 0;
    }

    // Move on top of NEAREST +1 value if available
    for (int c = 0; c < 3; c++)
    {
        // Don't search the current value's column
        if (c == column)
        {
            continue;
        }

        for (int h = 0; h < 4; h++)
        {
            if (towers[h][c] == cur + 1 && towers[h + 1][c] == 0)
            {
                towers[h + 1][c] = cur;
                towers[height][column] = 0;

                // If solved, find and solve next value and solve
                if (towers[4 - cur][2] == cur)
                {
                    // Find next value and call function on it
                    for (int c = 0; c < 3; c++)
                    {
                        for (int h = 0; h < 4; h++)
                        {
                            if (towers[h][c] == cur - 1)
                            {
                                solveHanoi(towers, h, c);
                                return 0;
                            }
                        }
                    }
                }

                return 0;
            }
        }   
    }

    // move on top of LARGER value if available
    for (int c = 0; c < 3; c++)
    {
        for (int h = 0; h < 4; h++)
        {
            if (towers[h][c] > cur + 2 && towers[h + 1][c] == 0)
            {
                towers[h + 1][c] = cur;
                towers[height][column] = 0;
                return 0;
            }
        }
    }

    // Move on top of OPEN column if available
    for (int c = 0; c < 3; c++)
    {
        // Don't search the current value's column
        if (c == column)
        {
            continue;
        }
        // If a column is open, move the value to the open column
        else if (towers[0][c] == 0)
            {
                towers[height][column] = 0;
                towers[0][c] = cur;

                // If we have moved 4 to a blank column we can assume it's solved
                if (cur == 4)
                {
                    // When 4 is solved, find and solve 3
                    for (int c = 0; c < 3; c++)
                    {
                        for (int h = 0; h < 4; h++)
                        {
                            if (towers[h][c] == 3)
                            {
                                solveHanoi(towers, h, c);
                                return 0;
                            }
                        }
                    }
                }

                return 0;
            }
    }

    // If there is nowhere to move a value, call function on column containing 1
    for (int c = 0; c < 3; c++)
    {
        // Don't search the current value's column
        if (c == column)
        {
            continue;
        }

        for (int h = 0; h < 4; h++)
        {
            if (towers[h][c] == 1)
            {
                solveHanoi(towers, 0, c);
                // Once space is cleared, move original again
                solveHanoi(towers, height, column);
                return 0;
            }
        }
    }
}