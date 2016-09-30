// Chapter 26 Practice Problem 2
// Provide another implementation of your sort function, this time taking an interface called Comparator, which has a method compare(const string& lhs, const string& rhs) that follows similar rules to the previous compare method: return 0 if the two values are the same, 1 if lhs > rhs or -1 if lhs < rhs. Write two different classes to do comparisson: one that does a case-insensitive comparison and one that sorts in reverse alphabetical order.

#include <iostream>
#include <string>

using namespace std;

class Comparator {
public:
    string name;
    // basic alphabetical sort
    virtual int compare (const string& lhs, const string& rhs);
    virtual string getCompareString ();
private:
};

class CaseInsensElement : public Comparator {
public:
    // case insensitive alphabetical sort
    virtual int compare (const string& lhs, const string& rhs);
private:
};

class ReverseSortElement : public Comparator {
public:
    // case insensitive alphabetical sort
    virtual int compare (const string& lhs, const string& rhs);
private:
};

void sortComparators (Comparator* bar[], int size);

int main () {
    ReverseSortElement* test1;
    test1 = new ReverseSortElement;
    test1->name = "all";
    ReverseSortElement* test2;
    test2 = new ReverseSortElement;
    test2->name = "Zoo";
    ReverseSortElement* test3;
    test3 = new ReverseSortElement;
    test3->name = "Apple";
    ReverseSortElement* test4;
    test4 = new ReverseSortElement;
    test4->name = "Zoinks!";
    ReverseSortElement* test5;
    test5 = new ReverseSortElement;
    test5->name = "awol";

    Comparator* foo[5];
    foo[4] = test1; 
    foo[3] = test2; 
    foo[2] = test3; 
    foo[1] = test4;
    foo[0] = test5;

    cout << "Unsorted objects:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << foo[i]->getCompareString() << endl;
    }

    sortComparators(foo, 5);

    cout << "Sorted objects:\n";
    for (int i = 0; i < 5; i++)
    {
        cout << foo[i]->getCompareString() << endl;
    }

}

void sortComparators(Comparator* bar[], int size) {
    Comparator *p_temp;
    for (int i = 0; i < size - 1; i++)
    {
        if (bar[i]->compare(bar[i]->getCompareString(), bar[ i + 1 ]->getCompareString()) == -1)
        {
            // Correct sort order, do nothing
        }
        else if (bar[i]->compare(bar[i]->getCompareString(), bar[ i + 1 ]->getCompareString()) == 1)
        {
            p_temp = bar[i];
            bar[i] = bar[ i + 1 ];
            bar[ i + 1 ] = p_temp;
            sortComparators(bar, size);
        }
        else if(bar[i]->compare(bar[i]->getCompareString(), bar[ i + 1 ]->getCompareString()) == 0)
        {
            // Sort on name
        }
    }
}


string Comparator::getCompareString() {
    return name;
}

int Comparator::compare(const string& lhs, const string& rhs) {
    // return 0 if the two values are the same, 1 if lhs > rhs or -1 if lhs < rhs
    // basic, case sensitive alphabetical sorting
    if (lhs < rhs)
    {
        return -1;
    }
    else if (lhs == rhs)
    {
        return 0;
    }
    else if (lhs > rhs)
    {
        return 1;
    }
}

int CaseInsensElement::compare(const string& lhs, const string& rhs) {
    // basic, case insensitive alphabetical sorting
    string lhs_lower = lhs;
    string rhs_lower = rhs;

    for(int i = 0; i < lhs.length(); ++i) {
        lhs_lower[i] = tolower(lhs[i]);
    }
    for(int i = 0; i < rhs.length(); ++i) {
        rhs_lower[i] = tolower(rhs[i]);
    }

    if (lhs_lower < rhs_lower)
    {
        return -1;
    }
    else if (lhs_lower == rhs_lower)
    {
        return 0;
    }
    else if (lhs_lower > rhs_lower)
    {
        return 1;
    }
}

int ReverseSortElement::compare(const string& lhs, const string& rhs) {
    // reverse, case sensitive alphabetical sorting
    if (lhs < rhs)
    {
        return 1;
    }
    else if (lhs == rhs)
    {
        return 0;
    }
    else if (lhs > rhs)
    {
        return -1;
    }
}