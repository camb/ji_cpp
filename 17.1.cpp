// Chapter 17 Practice Problem 1
// Write a program to display the contents of a binary tree. Can you write a program that prints the nodes in a binary tree in sorted order? What about in reverse sorted order?

#include <iostream>

using namespace std;

struct node
{
    int value;
    node* p_left;
    node* p_right;
};

void printBTree(node* tree, bool reverse);

int main ()
{
    // Create main tree node
    node* tree = new node;
    tree->value = 10;
    tree->p_left = NULL;
    tree->p_right = NULL;

    // Create the left branch
    node* temp = new node;
    temp->value = 8;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_left = temp;

    temp = new node;
    temp->value = 6;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_left->p_left = temp;

    temp = new node;
    temp->value = 9;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_left->p_right = temp;

    // Create the right branch
    temp = new node;
    temp->value = 14;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_right = temp;

    temp = new node;
    temp->value = 11;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_right->p_left = temp;

    temp = new node;
    temp->value = 40;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_right->p_right = temp;

    temp = NULL;
    delete temp;

    cout << "Printing sorted binary tree:\n";
    printBTree(tree, false);
    cout << endl;

    cout << "Printing reverse sorted binary tree:\n";
    printBTree(tree, true);
}

void printBTree(node* tree, bool reverse)
{   
    if (reverse == false)
    {
        if (tree->p_left != NULL)
        {
            printBTree(tree->p_left, false);
        }

        cout << tree->value << endl;

        if (tree->p_right != NULL)
        {
            printBTree(tree->p_right, false);
        }        
    }
    else if (reverse == true)
    {
        if (tree->p_right != NULL)
        {
            printBTree(tree->p_right, true);
        }

        cout << tree->value << endl;

        if (tree->p_left != NULL)
        {
            printBTree(tree->p_left, true);
        }
    }
}