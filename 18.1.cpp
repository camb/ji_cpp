// Chapter 18 Practice Problem 1
// Implement a small address book program that allows users to enter names and email addresses, remove or change entries, and list the entries in their address book. Don’t worry about saving the address book to disk; it’s ok to lose the data when

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct entry
{
    string name;
    string addr;
};

int main ()
{
    vector<entry> addrs(0);
    entry* new_entry;
    string name, addr;

    int command = 1;
    while (command != 0)
    {

        cout << "What would you like to do?\n";
        cout << "0- Exit program 1- Add entry 2- Remove entry 3- List Entry\n";
        cin >> command;
        cin.ignore();
        switch (command)
        {
            case 0:
                return 0;
                break;
            case 1:
                new_entry = new entry;

                cout << "What is the new entry's name:\n";
                getline(cin, name);
                new_entry->name = name;

                cout << "What is the new entry's address:\n";
                getline(cin, addr);
                new_entry->addr = addr;

                addrs.push_back(*new_entry);
                break;
            case 2:
                int del;
                cout << "Which entry would you like to delete?\n";
                cin >> del;
                addrs.erase(addrs.begin() + del);
                break;
            case 3:
                cout << "Address book:\n";
                for ( vector<entry>::iterator itr = addrs.begin(); itr != addrs.end(); ++itr )
                {
                    cout << "Name: " << itr->name << endl;
                    cout << "Address: " << itr->addr << endl;
                }
                break;
        }
    }

    return 0;
}