// Chapter 19 Practice Problem 1
// Write a program that reads in two strings, a "needle" and a "haystack" and counts the number of times the "needle" appears in the "haystack".

#include <iostream>
#include <string>

using namespace std;

int main ()
{
    string needle;
    string haystack;
    int num = 0;

    cout << "Enter your needle: ";
    getline(cin, needle);
    cout << "Enter your haystack: ";
    getline(cin, haystack);

    int i = 0;
    for (i = haystack.find(needle, 0); i != string::npos; i = haystack.find(needle, i))
    {
        num++;
        i++;
    }

    cout << needle << " appears in " << haystack << " " << num << " times.\n";

    return 0;
}