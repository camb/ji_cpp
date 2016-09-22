// Chapter 24 Practice Problem 1
// Take the structure from the practice problem at the end of the last chapter (representing a tic tac toe board) and reimplement it using a class, marking the publicly useful methods as public and marking the data and any helper methods as private. How much of your code did you have to change?

#include <iostream>

using namespace std;


class ttt {
public:
    void initialize ();
    void drawBoard ();
    bool isOver ();
    void switchPlayer ();
    void playerTurn ();
private:
    enum space {BLANK, O, X};
    enum pturn {P1_X, P2_O};
    pturn turn;
    space board[3][3];
};

int main () {
    ttt game;
    game.initialize();
    game.drawBoard();
    while (!game.isOver())
    {
        game.switchPlayer();
        game.playerTurn();
        game.drawBoard();
    }
}

void ttt::initialize() {
    cout << "Welcome to Tic-Tac-Toe!\n";

    // set the board to all blanks
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = BLANK;
        }
    }

    // make it player two's turn for the initial run, it switches before the first turn
    turn = P2_O;
}

void ttt::drawBoard() {
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == BLANK)
                cout << " - ";
            else if (board[i][j] == X)
                cout << " X ";
            else if (board[i][j] == O)
                cout << " O ";

            if (j < 2)
                cout << "|";
        }
        cout << endl;
        if (i < 2 )
            cout << "--- --- ---\n";
    }
}

bool ttt::isOver () {
    // check if board is full without a winner
    bool noBlanks = true;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == BLANK)
                noBlanks = false;
        }
    }
    if (noBlanks == true)
    {
        cout << "Game over! All spaces are taken! Draw!\n";
        return true;
    }

    bool threeInARow = false;
    // horizontals and vertical winning combinations
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != BLANK)
            threeInARow = true;
        else if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != BLANK)
            threeInARow = true;
    }
    // diagonal winning combinations
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] && board[1][1] != BLANK)
        threeInARow = true;
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0] && board[1][1] != BLANK)
        threeInARow = true;

    if (threeInARow == true)
    {
        cout << "Player ";
        if (turn == P1_X)
            cout << "one";
        else if (turn == P2_O)
            cout << "two";

        cout << " wins!\n";
        return true;
    }

    return false;
}

void ttt::playerTurn () {
    int row, col;
    cout << "Where would you like to go?\nrow: ";
    cin >> row;
    cout << "column: ";
    cin >> col;
    cout << endl;
    if (board[row][col] == BLANK)
    {
        if (turn == P1_X)
        {
            board[row][col] = X;
        }
        else if (turn == P2_O)
        {
            board[row][col] = O;
        }
    }
}

void ttt::switchPlayer () {
    cout << "It's player ";

    if (turn == P1_X)
    {
        cout << "two's";
        turn = P2_O;
    }
    else if (turn == P2_O)
    {
        cout << "one's";
        turn = P1_X;
    }

    cout << " turn.\n";
}