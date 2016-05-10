// Chapter 14 Practice Problem 6
// Write a program that takes a width and a height and dynamically generates a maze with the given width and height. The maze must always have a valid path through it (how can you ensure this?). Print the maze to the screen once it's been generated.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct mazeTile
{
    bool isPath;
};

void displayMaze(mazeTile** maze, int width, int height);
bool inBounds(int width, int height, int test_w, int test_h);

int main ()
{
    srand( time(NULL));
    int width, height;

    // Input height and width from user
    cout << "Enter the maze height > 4:\n";
    cin >> height;
    while (height < 4)
    {
        cout << "It must be greater than 4! Try again!\n";
        cin >> height;
    }
    cout << "Enter the maze width > 4:\n";
    cin >> width;
    while (width < 4)
    {
        cout << "It must be greater than 4! Try again!\n";
        cin >> width;
    }

    // Generate a 2D pointer array with pointer pointers
    mazeTile **p_p_maze = new mazeTile*[height];
    for (int i = 0; i < height; i++)
    {
        p_p_maze[i] = new mazeTile[width];
    }
    
    // Initialize the blank maze
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            p_p_maze[i][j].isPath = false;
        }
    }

    displayMaze(p_p_maze, width, height);

    // Pick an edge start tile
    int start_w, start_h;
    while (true)
    {
        cout << "LOOPIN'\n";
        start_w = rand() % (width + 1);
        start_h = rand() % (height + 1);
        if(start_h == 0 || start_w == 0)
        {
            cout << "ZERO REACHED\n";
            break;
        }
    }

    cout << "Width: " << start_w << endl;
    cout << "Height: " << start_h << endl;
    p_p_maze[start_h][start_w].isPath = true;

    displayMaze(p_p_maze, width, height);



    // TODO walk the array randomly and create a valid maze trail that terminates once it reaches another board edge
    // TODO Walk should check that each proceeding random step is on s tile that is only touching 1 other path tile
    // TODO Some sort of logic/check to prevent the maze from walking in a spiral/deadend and trapping itself.
    // TODO display the true path
    // TODO possibly go over the valid maze path board and create false paths that terminate before board edges?
    // TODO display the complete maze

    // Free maze memory
    for (int i = 0; i < height; i++)
    {
        delete p_p_maze[i] ;
    }
}

void displayMaze(mazeTile** maze, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maze[i][j].isPath)
            {
                cout << " * ";
            }
            else
            {
                cout << "[ ]";
            }
        }
        cout << endl;
    }
}


bool inBounds(int width, int height, int test_w, int test_h)
{
    if (test_w > width || test_w < 0)
        return false;
    else if (test_h > height || test_h < 0)
        return false;
    else
        return true;
}