// Chapter 11 Practice Problem 2

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <unistd.h>


using namespace std;

struct spaceship
{
    int x;
    int y;
    int type;
};

enum boardTile
{
    TIE,
    XWING,
    FALCON,
    BLANK,
};


void displayMap (boardTile board[][20]);
bool spaceshipsOnMap (boardTile board[][20]);
void clearBoard(boardTile board[][20]);
void moveShips(spaceship ships[10]);
void setShipsOnBoard(boardTile board[][20], spaceship ships[]);
spaceship setSpaceships ();

int main ()
{
    srand( time( NULL ) );
    boardTile board[20][20];
    spaceship ships[10];
    for (int i = 0; i < 10; i++)
    {
        ships[i] = setSpaceships();
    }
    
    do
    {
        clearBoard(board);
        moveShips(ships);
        setShipsOnBoard(board, ships);
        displayMap(board);
        for (int i = 0; i < 60; i++)
            cout << "#";
        cout << endl;
    } while (spaceshipsOnMap(board));
    cout << "All spaceships have left the board!\n";
    return 0;
}

void setShipsOnBoard (boardTile board[][20], spaceship ships[])
{
    for (int i = 0; i < 10; i++)
    {
        if (ships[i].x >= 0 && ships[i].x < 20 &&
            ships[i].y >= 0 && ships[i].y < 20)
        {
            switch (ships[i].type)
            {
            case 0:
                board[ships[i].x][ships[i].y] = TIE;
                break;
            case 1:
                board[ships[i].x][ships[i].y] = XWING;
                break;
            case 2:
                board[ships[i].x][ships[i].y] = FALCON;
                break;
            }
        }
    }
}

void moveShips(spaceship ships[10])
{
    for (int i = 0; i < 10; i++)
    {
        if (ships[i].x >= 0 && ships[i].x < 20 &&
            ships[i].y >= 0 && ships[i].y < 20)
        {
            ships[i].x += (rand() % 5 - 2);
            ships[i].y += (rand() % 5 - 2);
        }
    }
}

void clearBoard(boardTile board[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            board[i][j] = BLANK;
        }
    }
}

bool spaceshipsOnMap (boardTile board[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (board[i][j] != BLANK)
                return true;
        }
    }

    return false;
}

spaceship setSpaceships ()
{
    spaceship ship;
    ship.x = rand() % 21;
    ship.y = rand() % 21;
    ship.type = rand() % 3;
    return ship;
}

void displayMap (boardTile board[][20])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            switch (board[i][j])
            {
            case BLANK:
                cout << " . ";
                break;
            case TIE:
                cout << "|o|";
                break;
            case XWING:
                cout << ">v<";
                break;
            case FALCON:
                cout << "(Q>";
                break;
            }
        }
        cout << endl;
    }
    sleep(1);
}