// Chapter 16 Practice Problem 5
// Write a recursive algorithm to solve the towers of Hanoi problem.

#include <iostream>

using namespace std;

void printTowers(int towers[4][3]);

int solveHanoi(int towers[4][3]);

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

    solveHanoi(towers);

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

int solveHanoi(int towers[4][3])
{
    // TODO move topmost value
    for (int i = 4; i >= 0; i--)
    {
        towers[i][0];
    }

    // TODO If value above current value you're trying to move, recurvively call solve hanoi on that tile
    // If space has tile on it, move tile from space
    // Else if all above values are 0, move tile to space
    // if space to move to has smaller tile in it, select another space

    // Display towers after each iteration to show steps.
    printTowers(towers);

    // Base case that will exit recusion
    if (towers[0][2] == 4 &&
        towers[1][2] == 3 &&
        towers[2][2] = 2 &&
        towers[3][2] == 1)
    {
        cout << "The tower is solved!\n";
        return 0;
    }
}