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
    int size = 0;
    if ( !bin_file.is_open() )
    {
        cout << "Could not open bin file!\n";
        return 0;
    }

    cout << "Binary file open!\n";
    // read in the vector size
    bin_file.read((char*)&size, sizeof(int));
    // resize the vector to hold the binary data
    bin_scores.resize(size);
    // read in the vector data
    bin_file.read((char*)&bin_scores[0], bin_scores.size() * sizeof(int));
    cout << "bin_scores from binary file:\n";
    for ( vector<int>::iterator itr = bin_scores.begin(); itr != bin_scores.end(); ++itr )
    {
        cout << *itr << endl;        
    }

    int new_high_score = 0;
    cout << "Enter or remove scores(-1 to exit)\n";
    while ( true )
    {
        cout << "score: ";
        cin >> new_high_score;
        if ( new_high_score == -1)
            break;


        // if the vector size is 0 we insert the new_high_score without sorting
        if ( bin_scores.size() == 0 )
        {
            bin_scores.push_back( new_high_score );
        }
        // otherwise we insert the new_high_score into the sorted vector
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
                // if we hit the end of the vector without finding a lower score
                // push back the new score
                else if ( *itr == new_high_score)
                {
                    bin_scores.erase(itr);
                    break;
                }
                else if ( itr == bin_scores.end() - 1 )
                {
                    bin_scores.push_back( new_high_score );
                    break;
                }
            }
        }
    }

    // // cout the vector data for comparison
    // cout << "vector scores:\n";
    // for ( vector<int>::iterator itr = bin_scores.begin(); itr != bin_scores.end(); ++itr )
    // {
    //     cout << *itr << endl;
    // }

    // write the size of the vector to file
    // we'll use this when setting up the blank vector for reading
    bin_file.seekg( 0, ios::beg );
    size = bin_scores.size();
    bin_file.write((char*)&size, sizeof(int));
    // write the vector data
    bin_file.write(reinterpret_cast<const char*>(&bin_scores[0]), bin_scores.size()*sizeof(int));

    // reseting the location so we can read the file data
    bin_file.seekg( 0, ios::beg );
    // testing the binary file
    cout << "Printing binary file data:\n";
    // read in the vector size and initialize
    bin_file.read((char*)&size, sizeof(int));
    vector<int> b_read(size);
    // read in the vector data
    bin_file.read((char*)&b_read[0], b_read.size() * sizeof(int));
    for ( vector<int>::iterator itr = b_read.begin(); itr != b_read.end(); ++itr)
    {
        cout << *itr << endl;        
    }

    return 0;
}