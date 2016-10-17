// Chapter 30 Practice Problem 2
// Implementing an example of output formatting

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Person {
    Person ( const string& first_name,
             const string& last_name)
    : _first_name ( first_name )
    , _last_name ( last_name )
    {}

    string _first_name;
    string _last_name;
};

int main () {
    vector<Person> people;

    people.push_back( Person("Jimmy", "Smits") );
    people.push_back( Person("Yo", "Gabagaba") );
    people.push_back( Person("Chim", "Echurri") );
    people.push_back( Person("Deb", "Utah") );
    people.push_back( Person("Barbaduke", "McGillacutti") );

    int fn_max_width = 0;
    int ln_max_width = 0;

    for (vector<Person>::iterator itr = people.begin(); itr != people.end(); ++itr)
    {
        if ( itr->_first_name.length() > fn_max_width )
        {
            fn_max_width = itr->_first_name.length();
        }

        if ( itr->_last_name.length() > ln_max_width )
        {
            ln_max_width = itr->_last_name.length();
        }
    }

    for (vector<Person>::iterator itr = people.begin(); itr != people.end(); ++itr)
    {
        cout << setw(fn_max_width) << left << itr->_first_name << " ";
        cout << setw(ln_max_width) << left << itr->_last_name << endl;
    }

    return 0;
}