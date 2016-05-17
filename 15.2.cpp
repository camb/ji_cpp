// Chapter 15 Practice Problem 2
// Write a program that adds elements to a linked list in sorted order, rather than at the beginning

#include <iostream>

using namespace std;

struct node
{
    int num;
    node* next;
    node* prev;
};

int addSortedNode(node* &linked_list, int new_num);

int main ()
{
    // Initialize sorted linked list
    node* p_first = new node;
    p_first->num = 16;
    p_first->prev = NULL;
    node* p_temp = new node;
    p_first->next = p_temp;
    p_temp->num = 45;
    p_temp->prev = p_first;
    p_temp = new node;
    p_temp->num = 99;
    p_temp->prev = p_first->next;
    p_temp->prev->next = p_temp;
    p_temp->next = NULL;

    cout << "\nOriginal linked list:\n";
    p_temp = p_first;
    while(p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    // Run function a few times with numbers to sort that will interact with the original numbers and eachother
    cout << "\nAdding 4:\n";
    addSortedNode(p_first, 4);
    p_temp = p_first;
    while(p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "\nAdding 60:\n";
    addSortedNode(p_first, 60);
    p_temp = p_first;
    while(p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "\nAdding 59:\n";
    addSortedNode(p_first, 59);
    p_temp = p_first;
    while(p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    cout << "\nAdding 205:\n";
    addSortedNode(p_first, 205);
    p_temp = p_first;
    while(p_temp != NULL)
    {
        cout << p_temp->num << endl;
        p_temp = p_temp->next;
    }

    // Free memory
    p_first = NULL;
    p_temp = NULL;
    delete p_first;
    delete p_temp;
}


int addSortedNode(node* &linked_list, int new_num)
{
    node* p_cur = linked_list;
    node* p_temp = new node;
    p_temp->num = new_num;

    // If num < first num, num is first
    if (new_num < linked_list->num)
    {
        p_temp->next = linked_list;
        linked_list->prev = p_temp;
        linked_list = p_temp;
        return 0;
    }

    // Loop through linked list to find where the new node will sit, break if hit end
    while(p_temp->num >= p_cur->num)
    {
        // If it's the largest number, put it at the end of the list and stop
        if(p_cur->next == NULL)
        {
            p_cur->next = p_temp;
            p_temp->prev = p_cur;
            p_temp->next = NULL;
            return 0;
        }
        p_cur = p_cur->next;
    }

    p_cur->prev->next = p_temp;
    p_temp->prev = p_cur->prev;
    p_cur->prev = p_temp;
    p_temp->next = p_cur;

    p_temp = NULL;
    delete p_temp;
    return 0;
}