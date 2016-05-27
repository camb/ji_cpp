// Chapter 14 Practice Problem 4
// Write a program that checks if the binary tree is properly sorted so that all nodes to the left of a given node are less than the value of that node, and all nodes to the right are greater than the value of that node.

#include <iostream>
#include <string>

using namespace std;

struct node
{
    int value;
    node* p_left;
    node* p_right;
};

bool isSorted(node* tree);
string stringIsSorted(node* tree);

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

    // This node is improperly sorted
    temp = new node;
    temp->value = 12;
    temp->p_left = NULL;
    temp->p_right = NULL;
    tree->p_left->p_right = temp;

    // Create the right branch, this should be properly sorted
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

    cout << "Is the root sorted? " << stringIsSorted(tree) << endl;
    cout << "Is the left sorted? " << stringIsSorted(tree->p_left) << endl;
    cout << "Is the right sorted? " << stringIsSorted(tree->p_right) << endl;

}

string stringIsSorted(node* tree)
{
    if (isSorted(tree))
        return "yes";
    else
        return "no";
}

bool isSorted(node* tree)
{
    // If a node has no children, return true
    if (tree->p_left == NULL && tree->p_right == NULL)
    {
        return true;
    }
    // If node values are unsorted, return false
    else if (tree->value < tree->p_left->value ||
        tree->value > tree->p_right->value)
    {
        return false;
    }

    bool left_sort;
    bool right_sort;
    left_sort = isSorted(tree->p_left);
    right_sort = isSorted(tree->p_right);

    if (left_sort == false || right_sort == false)
    {
        return false;
    }
    else
        return true;
}