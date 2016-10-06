// Chapter 28 Practice Problem 1
// Reimplement the text file version of the high-score program that inserts into the correct file position, but do it using a binary file format instead of a text file format. How can you tell if your program is working? Create a program that displays the file as a text file.

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;


int main () {

    fstream bin_file ( "28.1.b.dat", ios::in | ios::out | ios::binary );

    // open and load high score info from binary file
    vector<int> bin_scores(0);

    if ( !bin_file.is_open() )
    {
        cout << "Could not open bin file!\n";
    }
    else
    {
        cout << "Binary file open!\n";
        bin_file.read((char*) &bin_scores[0], bin_scores.size() * sizeof(int));
        // TODO fix the reading in and display of previous scores
        cout << "bin_scores from binary file:\n";
        for ( vector<int>::iterator itr = bin_scores.begin(); itr != bin_scores.end(); ++itr )
        {
            cout << *itr << endl;        
        }
    }


    int new_high_score = 0;
    while ( true )
    {
        if ( new_high_score == -1)
            break;

        cout << "Enter your new high score(-1 to exit): ";
        cin >> new_high_score;

        // if the vector size is 0 we insert the new_high_score without sorting
        if ( bin_scores.size() == 0 )
        {
            bin_scores.push_back( new_high_score );
        }
        else
        {
            // loop through the vector until hitting a lower score
            for ( vector<int>::iterator itr = bin_scores.begin(); itr < bin_scores.end(); ++itr)
            {
                if ( new_high_score > *itr )
                {
                    bin_scores.insert( itr, new_high_score );
                    break;
                }
                // if we reach the end of the vector without finding a lower score
                // Push back the score
                else if ( itr == bin_scores.end() - 1 )
                {
                    bin_scores.push_back( new_high_score );
                    break;
                }
            }
        }
    }

    cout << "vector scores:\n";
    for ( vector<int>::iterator itr = bin_scores.begin(); itr != bin_scores.end(); ++itr )
    {
        cout << *itr << endl;
    }

    bin_file.seekg( 0, ios::beg );
    bin_file.write(reinterpret_cast<const char*>(&bin_scores[0]), bin_scores.size()*sizeof(int));

    // reseting the location so we can read the file data
    bin_file.seekg( 0, ios::beg );

    cout << "Printing binary file data:\n";
    // TODO derive the size of the b_read vector from the binary file, not the other vector
    vector<int> b_read(bin_scores.size());
    bin_file.read((char*)&b_read[0], b_read.size() * sizeof(int));
    for ( vector<int>::iterator itr = b_read.begin(); itr != b_read.end(); ++itr)
    {
        cout << *itr << endl;        
    }

    return 0;
}