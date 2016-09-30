// Chapter 10 Practice Problem 4

#include <iostream>

using namespace std;

enum ticTacToeTile { BLANK, X, O };
ticTacToeTile board[3][3];

void displayBoard(ticTacToeTile board[][3], int size);
bool gameOver();
bool boardFull();

int main ()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = BLANK;
        }
    }
    int current_player = 0;
    int input1 = 0, input2 = 0;

    do
    {
    displayBoard(board, 3);
    cout << "Player " << current_player + 1 << ", where will you go?\n";
    cin >> input2;
    cin >> input1;
    if (current_player == 0 && board[input1 - 1][input2 - 1] == BLANK)
    {
        board[input1 - 1][input2 - 1] = X;
        current_player = 1;
    }
    else if (current_player == 1 && board[input1 - 1][input2 - 1] == BLANK)
    {
        board[input1 - 1][input2 - 1] = O;
        current_player = 0;
    }
    else
        cout << "That tile is already taken!\n";
    } while ( !gameOver() && !boardFull() );
    
    displayBoard(board, 3);

    if (gameOver())
    {
        cout << "Congrats!! Player ";
        switch (current_player)
        {
        case 0:
            cout << "two";
            break;
        case 1:
            cout << "one";
            break;
        }
        cout << " has won!\n";
    }
    else if (boardFull())
    {
        cout << "The board has been completely filled! Game over!\n";
    }
    return 0;
}

bool boardFull()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == BLANK)
                return false;
        }
    }
    return true;    
}

void displayBoard(ticTacToeTile board[][3], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (board[i][j])
            {
                case BLANK:
                    cout << "[ - ]";
                    break;
                case X:
                    cout << "[ X ]";
                    break;
                case O:
                    cout << "[ O ]";
                    break;
            }
            cout << " ";
        }
        cout << endl;
    }
}

bool gameOver()
{
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != BLANK )
            return true;
        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != BLANK )
            return true;
    }
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[0][0] != BLANK )
        return true;
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[0][2] != BLANK )
        return true;

    return false;
}