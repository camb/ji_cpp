// Chapter 12 Practice Problem 1

#include <iostream>

using namespace std;

void getName(string *p_fn, string *p_ln);

int main ()
{
    string fn = "kung";
    string ln = "fu";
    getName(& fn, & ln);

    cout << "Hello " << fn << " " << ln << "!" << endl;


}

void getName(string *p_fn, string *p_ln)
{
    cout << "Current values: " << *p_fn << " " << *p_ln << endl;
    cout << "Enter your first name: ";
    getline(cin, *p_fn, '\n');
    cout << "Enter your last name: ";
    getline(cin, *p_ln, '\n');
}