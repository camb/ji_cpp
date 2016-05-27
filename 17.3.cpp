// Chapter 17 Practice Problem 3
// Write a program that checks whether a binary tree is properly balanced.

#include <iostream>

using namespace std;

struct node
{
    int value;
    node* p_left;
    node* p_right;
};

int nodeBalCount(node* tree);
string isBalanced(node* tree);

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

    cout << "Is the main tree balanced? " << isBalanced(tree) << endl;
    cout << "Is the left sub tree balanced? " << isBalanced(tree->p_left) << endl;
    cout << "Is the right sub tree balanced? " << isBalanced(tree->p_right) << endl;

}

string isBalanced(node* tree)
{
    int num = 0;
    num = nodeBalCount(tree);

    if (num == 0)
        return "no";
    else
        return "yes";
}

int nodeBalCount(node* tree)
{
    int count = 0;

    // If node has only 1 NULL branch return 0
    if ((tree->p_right == NULL || tree->p_left == NULL) && (tree->p_right != NULL || tree->p_left != NULL))
    {
        count = 0;
    }
    // If node has 2 NULL branches add 1 to count
    else if (tree->p_right == NULL && tree->p_left == NULL)
    {
        count += 1;
    }
    // If either branch is unbalanced, return 0 for the root
    else if (nodeBalCount(tree->p_left) == 0 || nodeBalCount(tree->p_right) == 0)
    {
        count = 0;
    }
    // If node has 2 valid branches, check each branch for balance and compare their totals
    else if (nodeBalCount(tree->p_right) == nodeBalCount(tree->p_left))
    {
        count += nodeBalCount(tree->p_left);
        count += nodeBalCount(tree->p_right);
    }

    return count;
}
