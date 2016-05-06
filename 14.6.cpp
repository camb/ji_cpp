// Chapter 14 Practice Problem 6
// Write a program that takes a width and a height and dynamically generates a maze with the given width and height. The maze must always have a valid path through it (how can you ensure this?). Print the maze to the screen once it's been generated.

#include <iostream>

using namespace std;

struct mazeTile
{
    bool isPath;
};

void displayMaze(mazeTile** maze, int width, int height);

int main ()
{
    int width, height;

    // Input height and width from user
    cout << "Enter the maze height:\n";
    cin >> height;
    cout << "Enter the maze width:\n";
    cin >> width;

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