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
int makePath(mazeTile** maze, int w, int h, int cur_x, int cur_y, bool hit_edge);

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


    // TODO makePath == 2 continue to fake paths else clear and redo maze
    // Establish the true maze path
    int a = 0, b = 0;
    while (true)
    {
        // Initialize the blank maze
        cout << "Clear and making maze\n";
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                p_p_maze[i][j].isPath = false;
            }
        }

        int start_w = width / (rand() % 2 + 2);
        int start_h = height / (rand() % 2 + 2);
        p_p_maze[start_h][start_w].isPath = true;
        // cout << "Start Width: " << start_w << " Height: " << start_h << endl;
        a = makePath(p_p_maze, width, height, start_w, start_h, true);
        b = makePath(p_p_maze, width, height, start_w, start_h, true);
        if (a + b == 2)
        {
            break;   
        }
        // else
        //     break;
    }

    cout << "Complete path:\n";
    displayMaze(p_p_maze, width, height);

    // Create false paths that terminate before board edges
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (p_p_maze[i][j].isPath == true)
            {
                // cout << "Attempting p_p_maze i: " << i << " j: " << j << endl;
                makePath(p_p_maze, width, height, i, j, false);
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (p_p_maze[i][j].isPath == true)
            {
                // cout << "Attempting p_p_maze i: " << i << " j: " << j << endl;
                makePath(p_p_maze, width, height, i, j, false);
            }
        }
    }
    cout << "Complete maze:\n";
    displayMaze(p_p_maze, width, height);

    // TODO Some sort of logic/check to prevent the maze from walking in a spiral/deadend and trapping itself.
    // TODO display the true path
    // TODO display the complete maze

    // Free maze memory
    for (int i = 0; i < height; i++)
    {
        delete p_p_maze[i];
    }
    delete [] p_p_maze;
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
    if (test_w >= width || test_w < 0)
        return false;
    else if (test_h >= height || test_h < 0)
        return false;
    else
        return true;
}


int makePath(mazeTile** maze, int w, int h, int cur_w, int cur_h, bool hit_edge)
{
    // TODO Currently the tryUDLR are not at all being used because we recursively call the function before accumulating 4 tries. This is assuredly causing issues.
    bool tryU = false, tryD = false, tryL = false, tryR = false;
    bool cont = true;
    while(cont)
    {
        int randtry = rand() % 4;
        switch (randtry)
        {
        case 0:
            if (inBounds(w, h, cur_w, cur_h - 1) &&
                maze[cur_h - 1][cur_w].isPath == false &&
                inBounds(w, h, cur_w + 1, cur_h - 1) &&
                maze[cur_h - 1][cur_w + 1].isPath == false &&
                inBounds(w, h, cur_w - 1, cur_h - 1) &&
                maze[cur_h - 1][cur_w - 1].isPath == false)
            {
                cur_h--;
                cont = false;
                // cout << "Up! ";
            }
            else
            {
                tryU = true;
            }
            
            break;

        case 1:
            if (inBounds(w, h, cur_w, cur_h + 1) &&
                maze[cur_h + 1][cur_w].isPath == false &&
                inBounds(w, h, cur_w + 1, cur_h + 1) &&
                maze[cur_h + 1][cur_w + 1].isPath == false &&
                inBounds(w, h, cur_w - 1, cur_h + 1) &&
                maze[cur_h + 1][cur_w - 1].isPath == false)
            {
                cur_h++;
                cont = false;
                // cout << "Down! ";
            }
            else
            {
                tryD = true;
            }

            break;

        case 2:
            if (inBounds(w, h, cur_w - 1, cur_h) &&
                maze[cur_h][cur_w - 1].isPath == false &&
                inBounds(w, h, cur_w - 1, cur_h + 1) &&
                maze[cur_h + 1][cur_w - 1].isPath == false &&
                inBounds(w, h, cur_w - 1, cur_h - 1) &&
                maze[cur_h - 1][cur_w - 1].isPath == false)
            {
                cur_w--;
                cont = false;
                // cout << "Left! ";
            }
            else
            {
                tryL = true;
            }

            break;

        case 3:
            if (inBounds(w, h, cur_w + 1, cur_h) &&
                maze[cur_h][cur_w + 1].isPath == false &&
                inBounds(w, h, cur_w + 1, cur_h + 1) &&
                maze[cur_h + 1][cur_w + 1].isPath == false &&
                inBounds(w, h, cur_w + 1, cur_h - 1) &&
                maze[cur_h - 1][cur_w + 1].isPath == false)
            {
                cur_w++;
                cont = false;
                // cout << "Right! ";
            }
            else
            {
                tryR = true;
            }

            break;
        }

        if (tryU == true && tryD == true && tryL == true && tryR == true)
        {
            // cout << "No options left!\n";
            return 0;
            // break;
        }

    }

    // Don't draw if an edge on a non-edge terminal
    if (hit_edge == false)
    {
        if (cur_h == 0 || cur_w == 0 || cur_w == w -1 || cur_h == h - 1)
        {
            // cout << "Non-edge terminal!\n";
            return 0;
        }
    }
    
    maze[cur_h][cur_w].isPath = true;

    // If the maze has hit another edge, break
    if (hit_edge == true &&
        (cur_h == 0 || cur_w == 0 || cur_w == w -1 || cur_h == h - 1))
    {
        // cout << "Reached the end!\n";
        // Use special return code for edge hit validate that we have an exit.
        return 1;
    }
    // If we haven't hit an edge and should, recurse with hit_edge = true
    else if (hit_edge == true)
    {
        makePath(maze, w, h, cur_w, cur_h, true);
        return 0;
    }
    // If we haven't hit an edge and shouldn't, recurse with hit_edge = false
    // (hit_edge == false)
    else if (hit_edge == false)
    {
        makePath(maze, w, h, cur_w, cur_h, false);
        return 0;
    }
}