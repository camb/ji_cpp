// Chapter 29 Practice Problem 1
// Write a function that takes a vector and sums all the values in the vector, no matter what type of numerical data the vector holds.

#include <vector>
#include <iostream>

using namespace std;

template <typename T>
T sumVector( vector<T> &v );

int main() {
    vector<int> v_int(3);
    vector<bool> v_bool(4);
    vector<float> v_flt(3);
    vector<double> v_dbl(3);

    v_int[0] = 1;
    v_int[1] = 15;
    v_int[2] = 7;

    v_bool[0] = true;
    v_bool[1] = 0;
    v_bool[2] = false;
    v_bool[3] = 1;

    v_flt[0] = 1.1;
    v_flt[1] = 8.256;
    v_flt[2] = 11.44;

    v_dbl[0] = 53452;
    v_dbl[1] = 9997123;
    v_dbl[2] = 32421233;

    cout << "Sum vectors:\n";
    cout << sumVector( v_int ) << endl;
    cout << sumVector( v_bool ) << endl;
    cout << sumVector( v_flt ) << endl;
    cout << sumVector( v_dbl ) << endl;

    return 0;
}

template <typename T>
T sumVector( vector<T> &v ) {
    T sum = 0;
    for ( typename vector<T>::iterator itr = v.begin(); itr != v.end(); ++itr )
    {
        sum += *itr;   
    }

    return sum;
}