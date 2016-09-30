// Chapter 14 Practice Problem 5
// Write a two-player gmae of Connect Four where the user can set the width and height of the board and each player gets a turn to drop a token into the slot. Display the board using + for one side, x for the other, and _ to indicate blank spaces.

#include <iostream>

using namespace std;

struct boardSpace
{
    char status;
};

void displayBoard(boardSpace **board, int height, int width);
bool gameOver(boardSpace **board, int height, int width);

int main ()
{
    int board_width, board_height;
    cout << "How high do you want the board to be?\n";
    cin >> board_height;
    while (board_height < 4)
    {
        cout << "It must be larger than 3. Enter another number.\n";
        cin >> board_height;
    }
    cout << "How wide do you want the board to be?\n";
    cin >> board_width;
    while (board_width < 4)
    {
        cout << "It must be larger than 3. Enter another number.\n";
        cin >> board_width;
    }

    boardSpace** p_p_board = new boardSpace*[board_height];

    for (int i = 0; i < board_height; i++)
    {
        p_p_board[i] = new boardSpace[board_width];
    }

    for (int i = 0; i < board_height; i++)
    {
        for (int j = 0; j < board_width; j++)
        {
            p_p_board[i][j].status = '_';
        }
    }

    displayBoard(p_p_board, board_height, board_width);

    int cur_player = 1;
    int column = 0;
    while (true)
    {
        // Ask current player to pick a column
        cout << "It's player " << cur_player << "'s turn. Pick a column.\n";

        // Validate that the space is within board_width and column isn't full by checking the topmost slot. Place or ask to pick again
        bool guess_again = true;
        while (guess_again)
        {
            cin >> column;
            if (column >= 0 && column < board_width && p_p_board[0][column].status == '_' )
            {
                // Iterate from the lowest slot to the highest
                for (int i = board_height - 1; i >= 0; i--)
                {
                    if (p_p_board[i][column].status == '_')
                    {
                        // Change symbol depending upon player
                        if (cur_player == 1)
                        {
                            p_p_board[i][column].status = '+';
                        }
                        else if (cur_player == 2)
                        {
                            p_p_board[i][column].status = 'x';
                        }
                        guess_again = false;
                        break;
                    }
                }
            }
            else
            {
                cout << "Pick another column!\n";
            }
        }

        displayBoard(p_p_board, board_height, board_width);

        // Evaluate if gameOver() and break if so
        if (gameOver(p_p_board, board_height, board_width))
        {
            cout << "Game Over! Player " << cur_player << " has won the game!\n";
            break;
        }


        // Check if board is full and return true if so
        bool out_of_room = true;
        for (int i = 0; i < board_height; i++)
        {
            for (int j = 0; j < board_width; j++)
            {
                if (p_p_board[i][j].status == '_')
                {
                    out_of_room = false;
                    break;
                }
            }
        }
        if (out_of_room)
        {
            cout << "The board is full! Game Over!\n";
            break;
        }

        // Altername to next player
        if (cur_player == 1)
            cur_player = 2;
        else if (cur_player == 2)
            cur_player = 1;
    }

    // Free board memory
    for (int i = 0; i < board_height; i++)
    {
        delete [] p_p_board[i];
    }
    delete p_p_board;

    return 0;
}


void displayBoard(boardSpace **board, int height, int width)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << "[" << board[i][j].status << "]";
        }
        cout << endl;
    }
}

bool gameOver(boardSpace **board, int height, int width)
{
    // Check the various 4 in a row possibilities
    // Vertical check
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width - 3 ; j++)
        {
            if (board[i][j].status != '_' &&
                     board[i][j].status == board[i][j + 1].status &&
                     board[i][j].status == board[i][j + 2].status &&
                     board[i][j].status == board[i][j + 3].status)
            {
                return true;
            }
        }
    }

    // Horizontal check
    for (int i = 0; i < height - 3; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (board[i][j].status != '_' &&
                board[i][j].status == board[i + 1][j].status &&
                board[i][j].status == board[i + 2][j].status &&
                board[i][j].status == board[i + 3][j].status)
            {
                return true;
            }
        }
    }

    // Upper left to bottom right diagonal check
    for (int i = 0; i < height - 3; i++)
    {
        for (int j = 0; j < width - 3; j++)
        {
            if (board[i][j].status != '_' &&
                board[i][j].status == board[i + 1][j + 1].status &&
                board[i][j].status == board[i + 2][j + 2].status &&
                board[i][j].status == board[i + 3][j + 3].status)
            {
                return true;
            }            
        }
    }

    // Lower left to upper right diagonal check
    for (int i = 0; i < height - 3; i++)
    {
        for (int j = 3; j < width; j++)
        {
            if (board[i][j].status != '_' &&
                board[i][j].status == board[i + 1][j - 1].status &&
                board[i][j].status == board[i + 2][j - 2].status &&
                board[i][j].status == board[i + 3][j - 3].status)
            {
                return true;
            }            
        }
    }

    return false;
}