// Chapter 18 Practice Problem 3
// Write a program with two options: register a user and log in. Register user allows a new user to create a login name and password. Log in allows a user to log in and access a second area, with options for "change password" and "log out". Change password allows the user to change the password, and log out will return the user to the original screen.

#include <iostream>
#include <map>

using namespace std;

void loginUser(string user, string pw, map<string, string>& user_logins);

int main ()
{
    map <string, string> user_logins;

    while (true)
    {
        int input;
        string user;
        string pw;
        cout << "Hello, welcome to the main menu. What would you like to do?\n";
        cout << "0- Exit\n1- Register a user\n2- Log in\n";
        cin >> input;
        cin.ignore();
        switch (input)
        {
            case 0:
                return 0;
                break;
            case 1:
                cout << "Enter the username: ";
                getline(cin, user);
                cout << "Enter the password: ";
                getline(cin, pw);

                user_logins[user] = pw;
                break;
            case 2:
                cout << "Logging in...\n";
                cout << "Enter your username: ";
                getline(cin, user);
                cout << "Enter your password: ";
                getline(cin, pw);
                loginUser(user, pw, user_logins);
                break;
        }
    }

    return 0;
}

void loginUser(string user, string pw, map<string, string>& user_logins)
{
    int input;

    if (user_logins[user] == pw)
    {
        cout << "Login successful...\n";
        while (true)
        {
            cout << "What would you like to do now?\n";
            cout << "0- Return to main menu\n";
            cout << "1- Change password\n";
            cout << "2- Logout\n";
            cin >> input;
            cin.ignore();
            switch(input)
            {
                case 0:
                    return;
                    break;
                case 1:
                    cout << "Enter you new password: ";
                    getline(cin, pw);
                    user_logins[user] = pw;
                    break;
                case 2:
                    // No specific logout operation needed, return to main menu
                    return;
                    break;
            }
        }
    }
    else
    {
        cout << "Login failed, returning to main menu...\n";
        return;
    }
    return;
}