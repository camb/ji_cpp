// Chapter 15 Practice Problem 3
// Write a program to find an element in a linked list by name.

#include <iostream>
#include <string>

using namespace std;

struct node
{
    string name;
    string role;
    node* next;
    node* prev;
};

void lookupName(node* llist, string name);

int main ()
{
    node* p_first = new node;
    node* p_temp = new node;
    p_first->name = "Joe";
    p_first->role = "Grandmaster Plumber";
    p_first->next = p_temp;
    p_first->prev = NULL;
    p_temp->name = "Hal";
    p_temp->role = "Electrical Engineer";
    p_temp->prev = p_first;
    p_temp = new node;
    p_temp->name = "Sue";
    p_temp->role = "Sales Agent";
    p_temp->prev = p_first->next;
    p_first->next->next = p_temp;
    p_temp->next = NULL;

    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->name << " is a " << p_temp->role << ".\n";
        p_temp = p_temp->next;
    }

    lookupName(p_first, "Sue");
    lookupName(p_first, "Hal");
    lookupName(p_first, "Joe");

    p_temp = NULL;
    p_first = NULL;
    delete p_temp;
    delete p_first;
}

void lookupName(node* llist, string name)
{
    while (llist != NULL)
    {
        if (llist->name == name)
        {
            cout << llist->role << endl;
        }

        llist = llist->next;
    }
}