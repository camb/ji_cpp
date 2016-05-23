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

    // Display towers after each iteration to show steps.
    printTowers(towers);

    // Easier variable to work with for the current location value
    int cur = towers[height][column];

    // If value above current value you're trying to move, recurvively call solve hanoi on that tile
    if (height != 3 && towers[height + 1][column] != 0)
    {
        solveHanoi(towers, height + 1, column);
    }

    // Base case that will exit recusion
    if (towers[0][2] == 4 &&
        towers[1][2] == 3 &&
        towers[2][2] == 2 &&
        towers[3][2] == 1)
    {
        cout << "The tower is solved!\n";
        printTowers(towers);
        return 0;
    }




    // move on top of NEAREST value if available
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
                return 0;
            }
        }   
    } 

    // move on top of OPEN column if available
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
                // Display towers after each iteration to show steps.
                printTowers(towers);
                return 0;
            }
    }


    // move on top of LARGER value if available
    for (int c = 0; c < 3; c++)
    {
        for (int h = 0; h < 4; h++)
        {
            if (towers[h][c] > towers[height][column] && towers[h + 1][c] == 0)
            {
                towers[h + 1][c] = cur;
                towers[height][column] = 0;
                return 0;
            }
        }
    }

    // If nothing is available, move column with lowest value to clear space
    for (int c = 0; c < 3; c++)
    {
        for (int h = 0; h < 4; h++)
        {
            if (towers[h][c] == 1)
            {
                solveHanoi(towers, 0, c);
                solveHanoi(towers, height, column);
                return 0;
            }
        }
    }

    cout << "HEIGHT: " << height << " COLUMN: " << column << endl;
    printTowers(towers);


    // Final run of towers to get them in correct place
    cout << "FINAL SOLUTION!";
    solveHanoi(towers, 0, 1);
}