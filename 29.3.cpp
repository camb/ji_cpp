// Chapter 29 Practice problem 3
// Write a search method that takes a vector, of any type, and a value, of any type, and returns true if the value is in the vector, or false if it is not.

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
string searchVector( vector<T> &v, T target );

int main () {
    vector<int> v_int(3);
    vector<char> v_chr(2);
    vector<bool> v_bool(3);
    vector<string> v_strg(6);

    v_int[0] = 5;
    v_int[1] = 7;
    v_int[2] = 10;

    v_chr[0] = 'a';
    v_chr[1] = 'z';

    v_bool[0] = true;
    v_bool[1] = 1;
    v_bool[2] = 99;

    v_strg[0] = "this";
    v_strg[1] = "is";
    v_strg[2] = "a";
    v_strg[3] = "series";
    v_strg[4] = "of";
    v_strg[5] = "strings";

    cout << "7 in int vector\n";
    cout << searchVector(v_int, 7) << endl;
    cout << "f in char vector\n";
    cout << searchVector(v_chr, 'f') << endl;
    cout << "z in char vector\n";
    cout << searchVector(v_chr, 'z') << endl;
    cout << "false in bool vector\n";
    cout << searchVector(v_bool, false) << endl;
    cout << "\"series\" in string vector\n";
    string search_strg = "series";
    cout << searchVector(v_strg, search_strg) << endl;

    return 0;
}

template <typename T>
string searchVector( vector<T> &v, T target) {
    bool result = false;
    for ( typename vector<T>::iterator itr = v.begin(); itr != v.end(); ++itr)
    {
        if ( *itr == target )
        {
            result = true;
        }
    }

    if ( result == true )
        return "true";

    return "false";
}