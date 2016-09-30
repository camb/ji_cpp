// Chapter 17 Practice Problem 2
// Write a program that counts the number of nodes in a binary tree

#include <iostream>

using namespace std;

struct node
{
    int value;
    node* p_left;
    node* p_right;
};

int countBTree(node* tree);

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

    cout << "Binary tree has " << countBTree(tree) << " nodes.\n";
}


int countBTree(node* tree)
{
    int count = 0;

    if (tree->p_left != NULL)
    {
        count += countBTree(tree->p_left);
    }

    if (tree->p_right != NULL)
    {
        count += countBTree(tree->p_right);
    }
    
    return ++count;
}