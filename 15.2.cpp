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

// void add node sorted function
void addSortedNode(node* &linked_list, int new_num);

int main ()
{
    node* p_first = new node;
    p_first->num = 16;
    p_first->prev = NULL;
    node* temp = new node;
    p_first->next = temp;
    temp->num = 45;
    temp->prev = p_first;
    temp = new node;
    temp->num = 99;
    temp->prev = p_first->next;
    temp->prev->next = temp;
    temp->next = NULL;

    // TODO initialize sorted linked list
    // TODO run function a few times with numbers to sort that will interact with the original numbers and eachother
    // TODO p_ to NULL and free memory
}


void addSortedNode(node* &linked_list, int new_num)
{
    cout << "blah\n";
    // TODO if num < first num, num is first
    // TODO while cur_p !+ NULL loop
    // TODO if num > cur_p, proceed to next item in linked list
    // TODO if reach NULL and no nums are greater, 
}