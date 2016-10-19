// Chapter 31 Practice Problem 1
// testing exceptions

#include <iostream>

using namespace std;


int main() {
    try
    {
        // code that produces failure
    }
    catch (...)
    {
        cout << "Failure caught!\n";
    }

    return 0;
}