// Chapter 28 Practice Problem 1
// Reimplement the text file version of the high-score program that inserts into the correct file position, but do it using a binary file format instead of a text file format. How can you tell if your program is working? Create a program that displays the file as a text file.

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct PlayerRecord {
    int age;
    int score;
    string name;
};

int main () {
    PlayerRecord rec;
    rec.age = 17;
    rec.score = 999;
    rec.name = "Joey";

    fstream file ( "28.1.txt", ios::in | ios::out );
    if ( !file.is_open() )
    {
        cout << "Could not open file!\n";
        return 0;
    }

    int new_high_score;
    cout << "Enter your new high score: ";
    cin >> new_high_score;

    int cur_score;
    streampos pre_score_pos = file.tellg();
    while ( file >> cur_score )
    {
        if (cur_score < new_high_score)
        {
            // we've found the point where we must insert the new score
            // stop iterating through the list of scores
            break;
        }
        pre_score_pos = file.tellg();
    }

    if ( file.fail() && !file.eof() )
    {
        cout << "Error, exiting\n";
        return 0;
    }

    // without calling clear we won't be able to write to the file if we hit eof
    file.clear();

    // we move to the point before we want to enter the new_high_score so that we can move the subsequent scores 1 position down
    file.seekg( pre_score_pos );

    vector<int> scores;
    while( file >> cur_score )
    {
        scores.push_back(cur_score);
    }
    // we expect to hit eof, so we check if not
    if ( !file.eof() )
    {
        cout << "Error, didn't hit EOF!\n";
    }

    // we've hit eof so now we need to clear again to write to file
    file.clear();

    // seek back to the position we are inserting to
    file.seekg( pre_score_pos );

    // if we are not writing to the beginning of the file, we need to include a newline. The reason is that when a number is read in it stops at the first whitespace, so the position we are at prior to writing is at the end of the number rather than at the start of the next line
    if ( pre_score_pos != 0 )
    {
        file << endl;
    }
    // write out the new highscore
    file << new_high_score << endl;
    // now we loop through the remaining scores from our vector
    for ( vector<int>::iterator itr = scores.begin(); itr != scores.end(); ++itr )
    {
        file << *itr << endl;
    }


    file.clear();
    file.seekg(0, ios::beg );
    cout << "Current high scores:\n";
    while ( file >> cur_score )
    {
        cout << cur_score << endl;
    }
    cout << endl;

    return 0;
}