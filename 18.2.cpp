// Chapter 18 Practice Problem 2
// Use vectors to implement a high score list for a video game. Make it so that scores are updated automatically, and new scores are added into the right place in the list. You may find the SGI website listed above useful for finding more operations you can do on vectors.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct entry
{
	int num;
	string name;

    bool operator < (const entry& str) const
    {
        return (num > str.num);
    }
};

int main ()
{
	vector<entry> scores(0);
	string name;
	int score;
	entry* p_new_entry;

	int command = 1;
	while (command != 0)
	{
		cout << "What would you like to do?\n";
		cout << "0- Exit   1- Add score   2- List scores\n";
		cin >> command;
        cin.ignore();

		switch (command)
		{
			case 0:
				return 0;
				break;
			case 1:
				cout << "Adding new score.\n";
				cout << "Name: ";
				getline(cin, name);
				cout << "Score: ";
				cin >> score;

		        p_new_entry = new entry;
		        p_new_entry->name = name;
		        p_new_entry->num = score;
		        scores.push_back(*p_new_entry);

		        sort(scores.begin(), scores.end());
				break;
			case 2:
				cout << "High Scores:\n";
				for (vector<entry>::iterator itr=scores.begin(); itr != scores.end(); ++itr)
				{
					cout << itr->name << "\t" << itr->num << endl;;
				}
				break;
		}
	}

	return 0;
}