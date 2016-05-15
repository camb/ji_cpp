// Chapter 15 Practice Problem 1
// Write a program to remove an element from a linked list; the remove function should take just the element to be removed. Is this function easy to write--and will it be fast? Could this be made easier or faster by adding an additional pointer to the list?

#include <iostream>

using namespace std;

// Basic linked list struct
struct llist
{
    int num;
    llist* next;
};

// Instantiate the remove element function that takes a struct pointer argument
// Had to pass the list as a pointer reference to get the value to change if first item is deleted without return
void removeItem(llist* &p_orig_first, int remove_num);

int main ()
{
    // Create the initial linked list pointer
    llist* p_first = new llist;
    p_first->num = 14;

    // Define a few structs and link them together
    llist* p_temp = new llist;
    p_temp->num = 99;
    p_first->next = p_temp;
    p_temp = new llist;
    p_temp->num = 69;
    p_first->next->next = p_temp;
    p_first->next->next->next = NULL;

    // Cout the linked list items before removal
    cout << "Before removal:\n";
    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "Removing 99:\n";
    removeItem(p_first, 99);
    // Cout the linked list items after removal
    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "Removing 69:\n";
    removeItem(p_first, 69);
    // Cout the linked list items after removal
    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "Removing 14:\n";
    removeItem(p_first, 14);
    // Cout the linked list items after removal
    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }
}


void removeItem(llist* &p_orig_first, int remove_num)
{
    llist* p_cur = new llist;
    llist* p_prev = new llist;
    p_cur = p_orig_first;
    p_prev = NULL;

    while (p_cur != NULL)
    {
        // If first item in linked list matches
        if (p_cur == p_orig_first && p_cur->num == remove_num)
        {
            p_prev = p_cur;
            p_cur = p_cur->next;
            p_orig_first = p_cur;
            delete p_prev;
            p_prev = NULL;
        }
        // If middle item in linked list matches
        else if (p_cur->num == remove_num && p_cur->next != NULL)
        {
            p_prev->next = p_cur->next;
            delete p_cur;
            p_cur = p_prev->next;
            p_prev = p_prev;
        }
        // If last item in linked list matches
        else if (p_cur->num == remove_num && p_cur->next == NULL)
        {
            p_prev->next = NULL;
            delete p_cur;
            p_cur = NULL;
        }
        // Else proceed down linked list
        else
        {
            p_prev = p_cur;
            p_cur = p_cur->next;
        }
    }

    // Freeing memory
    p_cur = NULL;
    p_prev = NULL;
    delete p_cur;
    delete p_prev;
}