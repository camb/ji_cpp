// Chapter 14 Practice Problem 4
// Write a program that lets users keep track of the last time they talked to each of their friends.
// Users should be able to add new friends (as many as they want!) and store the number of days ago that they last talked to each friend.
// Let users update this value (but don't let them put in bogus numbers like negative values). Make it possible to display the list sorted by the names of the frinds by how recently it was since they talked to each friend.

#include <iostream>
#include <string>

using namespace std;

struct friendStruct
{
    string name;
    int days_since;
};

friendStruct* growArray(friendStruct* p_values, int *size);
void displayValues(friendStruct* p_values, int size);
void sortValues(friendStruct* p_values, int size);
void updateValue(friendStruct* p_values);

int main ()
{
    int size = 2;
    int* p_size = &size;
    int cur_num = 0;
    friendStruct* p_friend = new friendStruct[*p_size];

    string cont = "yes";
    while (cont != "no")
    {
        cout << "Enter a friends first name:\n";
        cin >> p_friend[cur_num].name;

        cout << "How many days ago did you talk?\n";
        cin >> p_friend[cur_num].days_since;
        while (p_friend[cur_num].days_since < 0)
        {
            cout << "We can't allow negative values! Please enter a positive integer.\n";
            cin >> p_friend[cur_num].days_since;
        }

        cout << "Add more friends? yes or no\n";
        cin >> cont;

        cur_num++;
        cout << "CUR_NUM: " << cur_num << "\tSIZE: " << size << endl;
        // If we've reached the end of the array and intend to add more, grow the array
        if (cur_num == *p_size && cont == "yes")
        {
            p_friend = growArray(p_friend, p_size);
        }

    }

    while (true)
    {
        int input;
        cout << "How would you like to display the entries?\n";
        cout << "0- Exit\n1- By entered value\n2- Sorted by days since you last talked\n3- Update value\n";
        cin >> input;

        switch (input)
        {
        case 0:
            return 0;
            break;
        case 1:
            displayValues(p_friend, cur_num);
            break;
        case 2:
            sortValues(p_friend, cur_num);
            displayValues(p_friend, cur_num);
            break;
        case 3:
            // Update value function call
            displayValues(p_friend, cur_num);
            updateValue(p_friend);
            displayValues(p_friend, cur_num);
            break;
        }
    }

    return 0;
}

friendStruct* growArray(friendStruct* p_values, int *size)
{
    *size *= 2;
    friendStruct *p_new_values = new friendStruct[*size];
    for (int i = 0; i < (*size / 2); i++)
    {
        p_new_values[i] = p_values[i];
    }
    delete [] p_values;
    return p_new_values;
}

void displayValues(friendStruct* p_values, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << "#" << i << ": " << p_values[i].name;
        cout << ", days since talking: " << p_values[i].days_since << endl;
    }
}

void sortValues(friendStruct* p_values, int size)
{
    friendStruct *p_temp =  new friendStruct;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (p_values[i].days_since > p_values[j].days_since)
            {
                *p_temp = p_values[i];
                p_values[i] = p_values[j];
                p_values[j] = *p_temp;
            }
        }
    }
    delete p_temp;
}


void updateValue(friendStruct* p_values)
{
    int num, new_value;

    cout << "Which entry number would you like to edit?\n";
    cin >> num;
    cout << "What would you like the new value to be?\n";
    cin >> new_value;
        while (new_value < 0)
    {
        cout << "We can't allow negative values! Please enter a positive integer.\n";
        cin >> new_value;
    }
    p_values[num].days_since = new_value;
}