// Chapter 7 Practice Problem 3

#include <iostream>

using namespace std;

enum TicTacToeSquare { TTTS_BLANK, TTTS_O, TTTS_X };
TicTacToeSquare sq1, sq2, sq3, sq4, sq5, sq6, sq7, sq8, sq9;

void displaysquare ( TicTacToeSquare i );

void displayboard ();

int checkwinner ();

int main ()
{
    cout << "Welcome to Tic Tac Toe:\n";
    cout << "Player 1 plays 'O' and Player 2 plays 'X'\n";
    
    // Player 1 = 0, PLayer 2 = 1
    // Player 1 plays 'O', Player 2 plays 'X'
    int currentplayer = 0;
    bool gameInProgress = true;
    int move = 0;
    do
    {
        // display the board
        displayboard();

        // check if game over
        if ( checkwinner() == 0 )
            return 0;

        // ask 1 player to go
        cout << "It is player ";
        switch  ( currentplayer )
        {
        case 0:
            cout << "one";
            break;
        case 1:
            cout << "two";
            break;
        }
        cout << "'s turn to go.\n";
        cout << "Which square, 1-9, would you like to take? Enter 0 to exit.\n";
        cin >> move;
        switch ( move )
        {
        case 0:
            return 0;
            break;
        case 1:
            if ( currentplayer == 0 && sq1 == TTTS_BLANK )
                sq1 = TTTS_O;
            else if ( currentplayer == 1 && sq1 == TTTS_BLANK )
                sq1 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 2:
            if ( currentplayer == 0 && sq2 == TTTS_BLANK )
                sq2 = TTTS_O;
            else if ( currentplayer == 1 && sq2 == TTTS_BLANK )
                sq2 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 3:
            if ( currentplayer == 0 && sq3 == TTTS_BLANK )
                sq3 = TTTS_O;
            else if ( currentplayer == 1 && sq3 == TTTS_BLANK )
                sq3 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 4:
            if ( currentplayer == 0 && sq4 == TTTS_BLANK )
                sq4 = TTTS_O;
            else if ( currentplayer == 1 && sq4 == TTTS_BLANK )
                sq4 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 5:
            if ( currentplayer == 0 && sq5 == TTTS_BLANK )
                sq5 = TTTS_O;
            else if ( currentplayer == 1 && sq5 == TTTS_BLANK )
                sq5 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 6:
            if ( currentplayer == 0 && sq6 == TTTS_BLANK )
                sq6 = TTTS_O;
            else if ( currentplayer == 1 && sq6 == TTTS_BLANK )
                sq6 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 7:
            if ( currentplayer == 0 && sq7 == TTTS_BLANK )
                sq7 = TTTS_O;
            else if ( currentplayer == 1 && sq7 == TTTS_BLANK )
                sq7 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 8:
            if ( currentplayer == 0 && sq8 == TTTS_BLANK )
                sq8 = TTTS_O;
            else if ( currentplayer == 1 && sq8 == TTTS_BLANK )
                sq8 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        case 9:
            if ( currentplayer == 0 && sq9 == TTTS_BLANK )
                sq9 = TTTS_O;
            else if ( currentplayer == 1 && sq9 == TTTS_BLANK )
                sq9 = TTTS_X;
            else
                cout << "That square is already taken!\n";
            break;
        }

        // continue with next player
        switch ( currentplayer )
        {
        case 0:
            currentplayer = 1;
            break;
        case 1:
            currentplayer = 0;
            break;
        }
    } while ( gameInProgress == true );

}

void displaysquare ( TicTacToeSquare i )
{
    switch ( i )
    {
    case TTTS_BLANK:
        cout << "[ ]";
        break;
    case TTTS_X:
        cout << "[X]";
        break;
    case TTTS_O:
        cout << "[O]";
        break;
    }
}

void displayboard ()
{
    displaysquare ( sq1 );
    displaysquare ( sq2 );
    displaysquare ( sq3 );
    cout << endl;
    displaysquare ( sq4 );
    displaysquare ( sq5 );
    displaysquare ( sq6 );
    cout << endl;
    displaysquare ( sq7 );
    displaysquare ( sq8 );
    displaysquare ( sq9 );
    cout << endl;
}

int checkwinner ()
{
    if ( sq1 == sq2 && sq1 == sq3 && sq1 != TTTS_BLANK)
    {
        if ( sq1 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq1 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq4 == sq5 && sq4 == sq6  && sq4 != TTTS_BLANK)
    {
        if ( sq4 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq4 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq7 == sq8 && sq7 == sq9  && sq7 != TTTS_BLANK)
    {
        if ( sq7 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq7 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq1 == sq5 && sq1 == sq9  && sq1 != TTTS_BLANK )
    {
        if ( sq1 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq1 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq7 == sq5 && sq7 == sq3  && sq7 != TTTS_BLANK )
    {
        if ( sq7 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq7 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq1 == sq4 && sq1 == sq7  && sq1 != TTTS_BLANK )
    {
        if ( sq1 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq1 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq2 == sq5 && sq2 == sq8  && sq2 != TTTS_BLANK )
    {
        if ( sq2 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq2 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else if ( sq3 == sq6 && sq3 == sq9  && sq3 != TTTS_BLANK )
    {
        if ( sq3 == TTTS_O )
            cout << "Player one wins!\n";
        else if ( sq3 == TTTS_X )
            cout << "Player two wins!\n";
        return 0;
    }
    else
        return 1;
}