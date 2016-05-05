// Chapter 14 Practice Problem 5
// Write a two-player gmae of Connect Four where the user can set the width and height of the board and each player gets a turn to drop a token into the slot. Display the board using + for one side, x for the other, and _ to indicate blank spaces.

#include <iostream>

using namespace std;

struct boardSpace
{
    char status;
};

void displayBoard(boardSpace ***board, int height, int width);

int main ()
{
    int board_width, board_height;
    cout << "How high do you want the board to be?\n";
    cin >> board_height;
    cout << "How wide do you want the board to be?\n";
    cin >> board_width;

    boardSpace ***p_p_board;
    p_p_board = new boardSpace**[board_width];

    for (int i = 0; i < board_height; i++)
    {
        p_p_board[i] = new boardSpace*[board_width];
        for (int j = 0; j < board_width; j++)
        {
            p_p_board[i][j] = new boardSpace[board_width];
        }
    }

    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            p_p_board[i][j]->status = '_';
        }
    }


    displayBoard(p_p_board, board_height, board_width);
    return 0;
}


void displayBoard(boardSpace ***board, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[" << board[i][j]->status << "]";
        }
        cout << endl;
    }
}