// Chapter 30 Practice Problem 1
// There are no real problems in this section, this just illustrates an interesting operation

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    // cout.fill() returns the current fill character while also setting the value
    const char last_fill = cout.fill( '-' );
    // set last_fill to hold the old value ' ', and set the new value to '-'
    cout << setw(10) << "A" << setw(10) << "B"
         << setw(10) << "C" << endl;

    // the fill is set again to lsat_fill, the original return value of ' '
    cout.fill(last_fill);

    cout << setw(10) << "D" << endl;
    return 0;
}