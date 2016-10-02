// Chapter 27 Practice Problem 1
// Take your implementation of a vector from the practice prolem at the end of chapter 25 and add it to a namespace


#include <iostream>

using namespace std;

struct intNode {
        intNode *_p_next;
        int value;
    };

namespace VOI {
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
}

int main () {
    VOI::vectorOfInt test(0);
    test.setVal(0, 4);
    test.pushfront(3);
    test.pushfront(2);
    test.pushback(5);
    test.pushfront(1);
    test.print();

    VOI::vectorOfInt testCopy(test);
    testCopy.print();

    VOI::vectorOfInt testCopy2 = testCopy;
    testCopy2.setVal(2, 9);  
    testCopy2.pushback(14);    
    testCopy2.print();

    return 0;
}


int VOI::vectorOfInt::getVal(int index) {
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

void VOI::vectorOfInt::setVal(int index, int value) {
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

void VOI::vectorOfInt::pushback(int value) {
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

void VOI::vectorOfInt::pushfront(int value) {
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

void VOI::vectorOfInt::print () {
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

VOI::vectorOfInt::vectorOfInt () {
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

VOI::vectorOfInt::vectorOfInt (int size) {
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

VOI::vectorOfInt& VOI::vectorOfInt::operator=  (const VOI::vectorOfInt& other) {
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

VOI::vectorOfInt::vectorOfInt (const VOI::vectorOfInt& other) {
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

VOI::vectorOfInt::~vectorOfInt () {
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
