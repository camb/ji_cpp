// Chapter 26 Practice Problem 1
// Implement a sort function that takes a vector of pointers to an interface class, Comparable, that defines a method, compare(Comparable& other), and returns 0 if the objects are the same, 1 if the object is greater than other, and -1 if the object is less than other. Create a class that implements this interface, createseveral instances, and sort them. If you're looking for some inspiration for what to create--try a HighScoreElement class that has a name and a score, and sorts so that the top scores are first, but if two scores are the same, they are sorted next by name.

#include <iostream>
#include <string>

using namespace std;

class Comparable {
public:
    int score;
    // = 0 makes this a pure virtual function
    virtual int compare (Comparable& other) = 0;
private:
};

class HighScoreElement : public Comparable {
public:
    string name;
    virtual int compare (Comparable& other);
    void sort();
private:
};

void sortComparables (Comparable* bar[], int size);

int main () {
    HighScoreElement* test1;
    test1 = new HighScoreElement;
    test1->score = 1;
    test1->name = "One";
    HighScoreElement* test2;
    test2 = new HighScoreElement;
    test2->score = 2;
    test2->name = "Two";
    HighScoreElement* test3;
    test3 = new HighScoreElement;
    test3->score = 3;
    test3->name = "Three";

    Comparable* foo[3];
    foo[2] = test1; 
    foo[1] = test2;
    foo[0] = test3;

    for (int i = 0; i < 3; i++)
    {
        cout << foo[i]->score << endl;
    }

    sortComparables(foo, 3);

    for (int i = 0; i < 3; i++)
    {
        cout << foo[i]->score << endl;
    }

}

void sortComparables(Comparable* bar[], int size) {
    Comparable *p_temp;
    for (int i = 0; i < size - 1; i++)
    {
        if (bar[i]->compare(*bar[ i + 1 ]) == -1)
        {
            // Correct sort order, do nothing
        }
        else if (bar[i]->compare(*bar[ i + 1 ]) == 1)
        {
            p_temp = bar[i];
            bar[i] = bar[ i + 1 ];
            bar[ i + 1 ] = p_temp;
            sortComparables(bar, size);
        }
        else if(bar[i]->compare(*bar[ i + 1 ]) == 0)
        {
            // Sort on name
        }
    }
}

int HighScoreElement::compare(Comparable& other) {
    //returns 0 if the objects are the same, 1 if the object is greater than other, and -1 if the object is less than other
    if (score < other.score)
    {
        return -1;
    }
    else if (score == other.score)
    {
        return 0;
    }
    else if (score > other.score)
    {
        return 1;
    }
}