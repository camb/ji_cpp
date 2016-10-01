// Chapter 26 Practice Problem 3
// Implement a logging method that an interface class, StringConvertable, with a method toString that converts the resulting object into a string representation of itself. The logging method should print out the date and time as well as the object itself. (You can find information on getting the date at http://www.cplusplus.com/reference/clibrary/ctime/). Again notice how we are able to reuse our logging method simply by implementing an interface.

#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class StringConvertable {
// Convert the object to a string representation of itself
public:
    virtual string toString();
private:
    static string objectType;
};

class FirstType : public StringConvertable {
public:
    virtual string toString();
private:
    static string objectType;
};

class SecondType : public StringConvertable {
public:
    virtual string toString();
private:
    static string objectType;
};

class ThirdType : public StringConvertable {
public:
    virtual string toString();
private:
    static string objectType;
};

int main () {
    StringConvertable* foo[8];
    StringConvertable *p_test1 = new StringConvertable;
    StringConvertable *p_test2 = new FirstType;
    StringConvertable *p_test3 = new SecondType;
    StringConvertable *p_test4 = new ThirdType;
    StringConvertable *p_test5 = new SecondType;
    StringConvertable *p_test6 = new StringConvertable;
    StringConvertable *p_test7 = new FirstType;
    StringConvertable *p_test8 = new SecondType;

    foo[0] = p_test1;
    foo[1] = p_test2;
    foo[2] = p_test3;
    foo[3] = p_test4;
    foo[4] = p_test5;
    foo[5] = p_test6;
    foo[6] = p_test7;
    foo[7] = p_test8;

    for (int i = 0; i < 8; i++)
    {
        cout << foo[i]->toString() << endl;
    }
}

string StringConvertable::objectType = "Super Class type";
string FirstType::objectType = "First type";
string SecondType::objectType = "Second type";
string ThirdType::objectType = "Third type";

string StringConvertable::toString () {
    time_t result = time(NULL);
    string str_time;
    str_time = string(asctime(localtime(&result)));
    str_time.erase(remove(str_time.begin(), str_time.end(), '\n'), str_time.end());
    return ( str_time + " - " + objectType);
}

string FirstType::toString () {
    time_t result = time(NULL);
    string str_time;
    str_time = string(asctime(localtime(&result)));
    str_time.erase(remove(str_time.begin(), str_time.end(), '\n'), str_time.end());
    return ( str_time + " - " + objectType);}

string SecondType::toString () {
    time_t result = time(NULL);
    string str_time;
    str_time = string(asctime(localtime(&result)));
    str_time.erase(remove(str_time.begin(), str_time.end(), '\n'), str_time.end());
    return ( str_time + " - " + objectType);}

string ThirdType::toString () {
    time_t result = time(NULL);
    string str_time;
    str_time = string(asctime(localtime(&result)));
    str_time.erase(remove(str_time.begin(), str_time.end(), '\n'), str_time.end());
    return ( str_time + " - " + objectType);}