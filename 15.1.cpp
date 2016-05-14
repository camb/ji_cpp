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
void removeItem(llist* orig_list, int remove_num);

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

    removeItem(p_first, 69);

    // Cout the linked list items after removal
    cout << "After removal:\n";
    p_temp = p_first;
    while (p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    // TODO Run the remove function on a specific struct
}

// TODO Define the remove element function that takes a struct pointer argument
void removeItem(llist* orig_list, int remove_num)
{
    llist* p_cur = new llist;
    llist* p_prev = new llist;
    p_cur = orig_list;
    p_prev = orig_list;
    // TODO need p_next for while loop detection
    while (p_cur->next != NULL)
    {
        // If first item in linked list matches
        if (p_prev == p_cur && p_cur->num == remove_num)
        {
            orig_list = orig_list->next;
            p_cur = p_cur->next;
            delete p_prev;
            p_prev = p_cur;
        }
        // If middle item in linked list matches
        else if (p_cur->num == remove_num && p_cur->next != NULL)
        {
            p_prev->next = p_cur->next;
            delete p_cur;
            p_cur = p_prev->next;
        }
        // If last item in linked list matches
        else if (p_cur->num == remove_num && p_cur->next == NULL)
        {
            p_prev->next = NULL;
            delete p_cur;
            p_cur = NULL;
        }
        // If item num doesn't match
        else
        {
            p_prev = p_cur;
            p_cur = p_cur->next;
        }
    }
}