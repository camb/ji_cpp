// Chapter 19 Practice Problem 2
// Write a program that allows a user to type in tabular data similar to a CSV file, but instead of using commas a separator, first prompt the user to enter the separator character, then let the user type in the lines of tabular data. Provide a set of possible punctuation characters as options by looking through the input for non-number, non-letter characters. Find characters that appear on every single line, and choose those characters as the option. For example, if you see input like this:
//Alex Allain, webmaster@cprogramming.com
//John Smith, john@nowhere.com
//You should prompt the user to choose between comma, at sign, and period for the separator.

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main ()
{
    vector<string> lines;
    string delim;
    string* p_data;

    cout << "Enter your delimiter: ";
    getline(cin, delim);

    cout << "Enter your tabular data enter 0 when complete: ";
    while (true)
    {
        p_data = new string;
        getline(cin, *p_data);
        if (*p_data == "0")
        {
            break;
        }

        lines.push_back(*p_data);
    }
    cout << "The data is " << lines.size() << " lines long.\n";

    map<string, int> symbols;
    symbols["!"] = 0;
    symbols["@"] = 0;
    symbols["#"] = 0;
    symbols["&"] = 0;

    cout << "Possible non-number, non-letter characters: ";
    for (int i = 0; i < lines.size(); i++)
    {
        // Iterate over map of each symbol for every line in csv
        for (map<string, int>::iterator itr = symbols.begin(); itr != symbols.end(); ++itr)
        {
            // If symbol found itr->second++
            int j = lines[i].find(itr->first, 0);
            if (j != string::npos)
            {
                itr->second++;
            }
        }
    }

    for (map<string, int>::iterator itr = symbols.begin(); itr != symbols.end(); ++itr)
    {
        if (itr->second == lines.size())
        {
            cout << itr->first;
        }
    }
    cout << endl;

    return 0;
}