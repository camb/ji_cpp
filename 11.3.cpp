// Chapter 11 Practice Problem 1

#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct userInfo
{
    string name;
    string address;
    string phone_number;
};

int main ()
{
    int num_users;
    cout << "Hello, enter your total number of users: ";
    cin >> num_users;
    cin.ignore ( numeric_limits<streamsize>::max(), '\n' ); 
    cout << endl;
    userInfo user_array[num_users];
    for ( int i = 0; i < num_users; i++ )
    {
        cout << "Hello enter the user name: ";
        getline(cin, user_array[i].name, '\n');
        cout << "Enter " << user_array[i].name << "'s address: ";
        getline(cin, user_array[i].address, '\n');
        cout << "Enter " << user_array[i].name << "'s phone number: ";
        cin >> user_array[i].phone_number;
        cout << user_array[i].name << " lives at " << user_array[i].address << " and can be reached at " << user_array[i].phone_number << endl;
        cin.ignore ( numeric_limits<streamsize>::max(), '\n' ); 
    }
}