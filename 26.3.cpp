// Chapter 26 Practice Problem 3
// Implement a logging method that an interface class, StringConvertable, with a method toString that converts the resulting object into a string representation of itself. The logging method should print out the date and time as well as the object itself. (You can find information on getting the date at http://www.cplusplus.com/reference/clibrary/ctime/). Again notice how we are able to reuse our logging method simply by implementing an interface.

#include <iostream>
#include <string>
#include <ctime>

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

}

string StringConvertable::objectType = "Super Class object type";
string FirstType::objectType = "First object type";
string SecondType::objectType = "Second object type";
string ThirdType::objectType = "Third object type";

string StringConvertable::toString () {
    time_t result = time(NULL);
    cout << asctime(localtime(&result)) << " - " << objectType << endl;
}

string FirstType::toString () {
    time_t result = time(NULL);
    cout << asctime(localtime(&result)) << " - " << objectType << endl;

}

string SecondType::toString () {
    time_t result = time(NULL);
    cout << asctime(localtime(&result)) << " - " << objectType << endl;

}

string ThirdType::toString () {
    time_t result = time(NULL);
    cout << asctime(localtime(&result)) << " - " << objectType << endl;

}