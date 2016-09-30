// Chapter 12 Practice Problem 3

#include <iostream>

using namespace std;

string getName(string *p_fn, string *p_ln);

int main ()
{
    string fn = "kung";
    string ln = "fu";
    string ln2;
    string *p_null = NULL;

    ln2 = getName(& fn, p_null);

    if (p_null == NULL)
    {
        p_null = &ln2;
    }

    cout << "Hello " << fn << " " << *p_null << "!" << endl;

}

string getName(string *p_fn, string *p_ln)
{
    // cout << "Current values: " << *p_fn << " " << *p_ln << endl;
    cout << "Enter your first name: ";
    cin >> *p_fn;

    string temp;
    if (p_ln == NULL)
    {
        p_ln = &temp;
        cout << "Enter your last name: ";
        cin >> *p_ln;
    }
    return *p_ln;
}