// Chapter 29 Practice problem 4
// Implement a sort function that takes a vector of any type and sorts the values by their natural sort order (the order you get from using < or >).

#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
void sortVector( vector<T> &v );
template <typename T>
void coutVector( vector<T> &v );

int main () {
    vector<int> v_int(10);
    v_int[0] = 3;
    v_int[1] = 5;
    v_int[2] = 1;
    v_int[3] = 7;
    v_int[4] = 5;
    v_int[5] = 10;
    v_int[6] = 9;
    v_int[7] = 5;
    v_int[8] = 6;
    v_int[9] = 4;

    cout << "Unsorted int vector:\n";
    coutVector( v_int );

    sortVector( v_int );

    cout << "Sorted int vector:\n";
    coutVector( v_int );

    vector<string> v_string(10);
    v_string[0] = "this";
    v_string[1] = "is";
    v_string[2] = "a";
    v_string[3] = "vector";
    v_string[4] = "of";
    v_string[5] = "strings";
    v_string[6] = "that";
    v_string[7] = "is";
    v_string[8] = "sorted";
    v_string[9] = "yay!";

    cout << "Unsorted string vector:\n";
    coutVector( v_string );

    sortVector( v_string );

    cout << "Sorted string vector:\n";
    coutVector( v_string );

    return 0;
}

template <typename T>
void sortVector( vector<T> &v ) {
    for ( typename vector<T>::iterator itr = v.begin(); itr != ( v.end() -1 ); ++itr )
    {
        if ( *itr < *(itr + 1) )
        {
            T temp;
            temp = *itr;
            *itr = *(itr + 1);
            *(itr + 1) = temp;

            sortVector( v );
        }
    }
}

template <typename T>
void coutVector( vector<T> &v ) {
    for ( typename vector<T>::iterator itr = v.begin(); itr != v.end(); ++itr )
    {
        cout << *itr << endl;
    }
}