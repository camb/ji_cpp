// Chapter 11 Practice Problem 4

#include <iostream>
#include <string>
#include <limits>

using namespace std;

struct playerScore
{
    int score;
    string name;

};

void printHighestScore(playerScore scores[], int size);
void showUserScores(playerScore scores[], int size);
void showAllScores(playerScore scores[], int size);
void listAllUsers(playerScore scores[], int size);


int main ()
{
    int num_scores = 0;
    cout << "How many scores will you enter?\n";
    cin >> num_scores;

    // Establish list of scores and names
    playerScore score_list[num_scores];

    for (int i = 0; i < num_scores; i++)
    {    
        cout << "Enter the score: ";
        cin >> score_list[i].score;
        cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
        cout << "Enter the player's name: ";
        getline( cin, score_list[i].name, '\n' );
    }

    int input = 0;
    do
    {
        cout << "What would you like to do now?\n";
        cout << "0 - Quit program\n";
        cout << "1 - Show highest score\n";
        cout << "2 - Show user scores\n";
        cout << "3 - Show all scores\n";
        cout << "4 - List users\n";
        cin >> input;
    
        switch (input)
        {
        case 0:
            return 0;
            break;
        case 1:
            printHighestScore(score_list, num_scores);
            break;
        case 2:
            showUserScores(score_list, num_scores);
            break;
        case 3:
            showAllScores(score_list, num_scores);
            break;
        case 4:
            listAllUsers(score_list, num_scores);
            break;
        }
    } while (input != 0);

    return 0;
}

void printHighestScore(playerScore scores[], int size)
{
    int high_score = 0;
    for (int i = 0; i < size; i++)
    {
        if (scores[i].score > high_score)
            high_score = scores[i].score; 
    }
    cout << "Highest score: " << high_score << endl;
}

void showUserScores(playerScore scores[], int size)
{
    string user;
    cout << "Which user would you like to lookup?\n";
    cin.ignore ( numeric_limits<streamsize>::max(), '\n' );
    getline( cin, user, '\n' );
    for (int i = 0; i < size; i++)
    {
        if (scores[i].name == user)
            cout << scores[i].score << endl;
    }
}

void showAllScores(playerScore scores[], int size)
{
    for (int i = 0; i < size; i++)
        cout << scores[i].score << endl;
}

void listAllUsers(playerScore scores[], int size)
{
    for (int i = 0; i < size; i++)
        cout << scores[i].name << endl;
}
