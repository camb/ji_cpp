// Chapter 26 Practice Problem 1
// Implement a sort function that takes a vector of pointers to an interface class, Comparable, that defines a method, compare(Comparable& other), and returns 0 if the objects are the same, 1 if the object is greater than other, and -1 if the object is less than other. Create a class that implements this interface, createseveral instances, abd sort them. If you're looking for some inspiration for what to create--try a HighScoreElement class that has a name and a score, and sorts so that the top scores are first, but if two scores are the same, they are sorted next by name.

#include <iostream>
#include <string>

using namespace std;

class Comparable {
public:
    // = 0 makes this a pure virtual function
    virtual int compare (Comparable& other) = 0;
private:
};

class HighScoreElement : public Comparable {
public:
    int score;
    string name;
    virtual int compare (Comparable& other);
private:
};

int main () {
    cout << "blek!\n";

    HighScoreElement test;
    test.score = 999;
    test.name = "Yimmy";
    test.compare(test);
}

int HighScoreElement::compare(Comparable& other) {
    cout << "phoey!\n";
    //returns 0 if the objects are the same, 1 if the object is greater than other, and -1 if the object is less than other
}