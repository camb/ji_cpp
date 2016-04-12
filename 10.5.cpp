// Chapter 10 Practice Problem 4

#include <iostream>

using namespace std;

// const int max_size = 4;
enum ticTacToeTile { BLANK, X, O };

const int max_size = 7, min_size = 4;
void displayBoard(ticTacToeTile board[][max_size], int size);
bool gameOver(ticTacToeTile board[][max_size], int size);
bool boardFull(ticTacToeTile board[][max_size], int size);

int main ()
{
    int dimension;
    cout << "How big do you want the board? (between 4-7 tiles)\n";
    cin >> dimension;
    if (dimension < min_size || dimension > max_size)
    {
        cout << "That won't work! The board must be between min_size and 7 tiles!\n";
        return 0;
    }
    ticTacToeTile board[max_size][max_size];
    for (int i = 0; i < max_size; i++)
    {
        for (int j = 0; j < max_size; j++)
        {
            board[i][j] = BLANK;
        }
    }
    int current_player = 0;
    int input1 = 0, input2 = 0;

    do
    {
    displayBoard(board, dimension);
    cout << "Player " << current_player + 1 << ", where will you go?\n";
    cin >> input1;
    cin >> input2;
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
    } while ( !gameOver(board, dimension) && !boardFull(board, dimension) );
    
    displayBoard(board, dimension);

    if (gameOver(board, dimension))
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
    else if (boardFull(board, dimension))
    {
        cout << "The board has been completely filled! Game over!\n";
    }
    return 0;
}

bool boardFull(ticTacToeTile board[][max_size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (board[i][j] == BLANK)
                return false;
        }
    }
    return true;    
}

void displayBoard(ticTacToeTile board[][max_size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            switch (board[i][j])
            {
                case BLANK:
                    cout << "[-]";
                    break;
                case X:
                    cout << "[X]";
                    break;
                case O:
                    cout << "[O]";
                    break;
            }
        }
        cout << endl;
    }
}

bool gameOver(ticTacToeTile board[][max_size], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j <= ( size - 4 ) ; j++)
        {
            // horizontal matches
            if (board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] &&
                board[i][j] == board[i][j + 3] &&
                board[i][j] != BLANK )
            {
                cout << "Horizonal 4 in a row!\n";
                return true;
            }
            // // vertical matches
            else if (board[j][i] == board[j + 1][i] &&
                     board[j][i] == board[j + 2][i] &&
                     board[j][i] == board[j + 3][i] &&
                     board[j][i] != BLANK )
            {
                cout << "Vertical 4 in a row!\n";
                return true;
            }
            // // diagonal upper left to lower right
            else if (i < 4 &&
                     board[i][j] == board[i + 1][j + 1] &&
                     board[i][j] == board[i + 2][j + 2] &&
                     board[i][j] == board[i + 3][j + 3] &&
                     board[i][j] != BLANK )
            {
                cout << "Diagonal upper left to lower right!\n";
                return true;
            }
            // // diagonal lower left to upper right
            else if (i > 2 &&
                     board[i][j] == board[i - 1][j + 1] &&
                     board[i][j] == board[i - 2][j + 2] &&
                     board[i][j] == board[i - 3][j + 3] &&
                     board[i][j] != BLANK )
            {
                cout << "Diagonal lower left to upper right!\n";
                return true;
            }
            }
        }

    return false;
}