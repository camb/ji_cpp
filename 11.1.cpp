// Chapter 11 Practice Problem 1

#include <iostream>
#include <string>

using namespace std;

struct userInfo
{
    string name;
    string address;
    string phone_number;
};

int main ()
{
    userInfo user1;
    cout << "Hello enter the user name: ";
    getline(cin, user1.name, '\n');
    cout << "Enter " << user1.name << "'s address: ";
    getline(cin, user1.address, '\n');
    cout << "Enter " << user1.name << "'s phone number: ";
    cin >> user1.phone_number;
    cout << user1.name << " lives at " << user1.address << " and can be reached at " << user1.phone_number << endl;
}