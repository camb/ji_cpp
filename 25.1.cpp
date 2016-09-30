// Chapter 25 Practice Problem 1
/* 1. Implement a vector replacement that operates only on integers, vectorOfInt (you don't need to use templates like the normal STL). Your class should have the following interface:
    • A no-argument constructor that allocates a 32 element vector
    • A constructor that takes an initial size as the argument
    • A method get, taking an index as returning the value at that index
    • A method set, that takes an index and a value, and sets the value at that index
    • A method pushback that adds an element to the end of the array, resizing if necessary
    • A method pushfront that adds an element to the beginning of the array
    • A Copy constructor and assignment operator
Your class should not leak memory; any memory it allocates must be deleted. Try to think carefully
about how your class can be misused, and how you should handle them. What do you do if a user gives
a negative initial size? What about accessing a negative index?*/

#include <iostream>

using namespace std;

struct intNode {
        intNode *_p_next;
        int value;
    };

class vectorOfInt {
public:
    int getVal(int index);
    void setVal(int index, int value);
    void pushback(int value);
    void pushfront(int value);
    void print();
    vectorOfInt (); // No argument constructor, create a 32 element vector
    vectorOfInt (int size); // Constructor that takes an initial size
    vectorOfInt& operator= (const vectorOfInt& other); // Assignment operator
    vectorOfInt (const vectorOfInt& other); // Copy constructor
    ~vectorOfInt (); // Destructor
private:
    intNode *_p_head;
};

int main () {
    // vectorOfInt fivetest(3);
    // fivetest.print();

    vectorOfInt test(0);
    test.setVal(0, 4);
    test.pushfront(3);
    test.pushfront(2);
    test.pushback(5);
    test.pushfront(1);
    test.print();

    vectorOfInt testCopy(test);
    testCopy.print();

    vectorOfInt testCopy2 = testCopy;
    testCopy2.setVal(2, 9);  
    testCopy2.pushback(14);    
    testCopy2.print();

    // cout << "Get index 4: " << test.getVal(4) << endl;
    // cout << "Get index 2: " << test.getVal(2) << endl;
    // cout << "Get index 0: " << test.getVal(0) << endl;
    // test.setVal(0, 10);
    // test.setVal(2, 100);
    // test.setVal(4, 1000);
    // test.print();

    // vectorOfInt noargtest;
    // noargtest.print();

    return 0;
}


int vectorOfInt::getVal(int index) {
    intNode *p_temp = new intNode;
    p_temp = _p_head;
    for (int i = 0; i < index; i++)
    {
        p_temp = p_temp->_p_next;
    }
    return p_temp->value;

    p_temp = NULL;
    delete p_temp;
}

void vectorOfInt::setVal(int index, int value) {
    intNode *p_temp = new intNode;
    p_temp = _p_head;
    for (int i = 0; i < index; i++)
    {
        p_temp = p_temp->_p_next;
    }
    p_temp->value = value;
    p_temp = NULL;
    delete p_temp;
}

void vectorOfInt::pushback(int value) {
    intNode *p_temp = new intNode;
    intNode *pushback = new intNode;
    pushback->_p_next = NULL;
    pushback->value = value;
    p_temp = _p_head;
    if (p_temp != NULL)
    {
        while (p_temp->_p_next != NULL) 
        {
            p_temp = p_temp->_p_next;
        }
        p_temp->_p_next = pushback;
    }
    else
    {
        _p_head = pushback;
    }

    p_temp = NULL;
    pushback = NULL;
    delete p_temp;
    delete pushback;
}

void vectorOfInt::pushfront(int value) {
    intNode *p_temp = new intNode;
    intNode *pushfront = new intNode;
    pushfront->value = value;
    p_temp = _p_head;
    if (p_temp == NULL)
    {
        _p_head = pushfront;
        pushfront->_p_next = NULL;
    }
    else
    {
        pushfront->_p_next = _p_head;
        _p_head = pushfront;
    }

    p_temp = NULL;
    pushfront = NULL;
    delete p_temp;
    delete pushfront;
}

void vectorOfInt::print () {
    cout << "Printing values:\n";
    intNode *p_temp = new intNode;
    p_temp = _p_head;

    while (p_temp != NULL)
    {
        cout << p_temp->value << endl;
        p_temp = p_temp->_p_next;
    }

    delete p_temp;
}

vectorOfInt::vectorOfInt () {
    intNode *p_temp = new intNode;
    p_temp->value = 0;
    p_temp->_p_next = NULL;
    _p_head = p_temp;
    for(int i = 1; i < 32; i++)
    {
        intNode *p_next = new intNode;

        p_next->value = 0;
        p_next->_p_next = NULL;
        p_temp->_p_next = p_next;
        p_temp = p_temp->_p_next;
        p_temp->value = 0;
        p_temp->_p_next = NULL;

        p_next = NULL;
        delete p_next;
    }

    p_temp = NULL;
    delete p_temp;
}

vectorOfInt::vectorOfInt (int size) {
    intNode *p_temp = new intNode;
    p_temp->value = 0;
    p_temp->_p_next = NULL;
    _p_head = p_temp;
    for(int i = 1; i < size; i++)
    {
        intNode *p_next = new intNode;

        p_next->value = 0;
        p_next->_p_next = NULL;
        p_temp->_p_next = p_next;
        p_temp = p_temp->_p_next;
        p_temp->value = 0;
        p_temp->_p_next = NULL;

        p_next = NULL;
        delete p_next;
    }

    p_temp = NULL;
    delete p_temp;
}

vectorOfInt& vectorOfInt::operator=  (const vectorOfInt& other) {
    intNode *p_temp = new intNode;
    intNode *p_other = new intNode;
    p_other = other._p_head;
    if (p_other != NULL)
    {
        p_temp->value = p_other->value;
        p_temp->_p_next = NULL;
        _p_head = p_temp;
        while (p_other->_p_next != NULL)
        {
            p_other = p_other->_p_next;

            intNode *p_next = new intNode;
            p_next->value = p_other->value;
            p_next->_p_next = NULL;

            p_temp->_p_next = p_next;
            p_temp = p_next;

            p_next = NULL;
            delete p_next;
        }
    }

    p_other = NULL;
    delete p_other;
    p_temp = NULL;
    delete p_temp;
}

vectorOfInt::vectorOfInt (const vectorOfInt& other) {
    intNode *p_temp = new intNode;
    intNode *p_other = new intNode;
    p_other = other._p_head;
    if (p_other != NULL)
    {
        p_temp->value = p_other->value;
        p_temp->_p_next = NULL;
        _p_head = p_temp;
        while (p_other->_p_next != NULL)
        {
            p_other = p_other->_p_next;

            intNode *p_next = new intNode;
            p_next->value = p_other->value;
            p_next->_p_next = NULL;

            p_temp->_p_next = p_next;
            p_temp = p_next;

            p_next = NULL;
            delete p_next;
        }
    }

    p_other = NULL;
    delete p_other;
    p_temp = NULL;
    delete p_temp;
}

vectorOfInt::~vectorOfInt () {
    intNode *p_temp = new intNode;
    intNode *p_next = new intNode;
    if (_p_head != NULL)
    {
        p_temp = _p_head;
        while(p_temp != NULL)
        {
            p_next = p_temp->_p_next;
            delete p_temp;
            p_temp = p_next;
        }
    }

    p_temp = NULL;
    p_next = NULL;
    _p_head = NULL;
    delete p_temp;
    delete p_next;
    delete _p_head;
}
