// Chapter 28 Practice Problem 3
/*
Create a simple XML parser. XML is a basic formatting language, similar to HTML. The document is a tree structure of nodes, of the form <node>[data]</node>, where [data] is either some text or another nested node. XML nodes may have attributes, of the form <node attribute=”value”></node>. (The true XML specification includes many more details, but that would be a lot more work to implement.) Your parser should accept an interface class with several methods that it calls when something interesting happens:
    1) Whenever a node is read, it calls a method nodeStart, with the name of the node.
    2) Whenever an attribute is read, it calls a method, attributeRead; this method should always be called immediately after the nodeStart method for the node with which the attribute is associated.
    3) Whenever a node has body text, call nodeTextRead, with the content of the text, as a string. If you have a situation like this <node>text<sub-node>text</sub-node>more text</node>, there should be separate calls to nodeTextRead for the text before to the sub- node and the text after the sub-node.
    4) Whenever an end-node is read, call nodeEnd, with the name of the node.
    5) You may treat any < or > character as the start of a node. If an XML author wants < or > to appear in the text, it should be written as &lt; or &gt; (for less-than and greater-than). Since ampersands must also be escaped, they must appear as &amp;. You do not need to perform translation of &lt; and &gt; or &amp; in your code, however.
*/


#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


class classOfType {
public:
    string getName();
    string getText();
    classOfType(string n, int p, int e, string* d);
    void nodeTextRead(string t);
private:
    string* p_data;
    int pos;
    string name;
    vector<string> text;
    void nodeStart(string n, int p, int e, string* d);
};


int main () {
    fstream xml_file("28.3.xml");
    if ( !xml_file.is_open() )
    {
        cout << "Failed to open XML file!\n";
        return 0;
    }

    // convert XML file to string
    stringstream buffer;
    buffer << xml_file.rdbuf();
    string data;
    data = buffer.str();
    cout << "Original XML:\n";
    cout << data << endl << endl;

    vector<classOfType> vec_node;
    string* p_data = &data;

    // remove newlines.
    for ( int i = data.find("\n", 0); i != string::npos; i = data.find("\n", i))
    {
        data.erase(i, 1);
    }

    // instantiate a node for each XML tag
    for ( int i = data.find("<", 0); i != string::npos; i = data.find("<", i))
    {
        if ( data[i + 1] != '/' )
        {
            int end;
            end = data.find(">", i);
            string tag;
            tag = data.substr( i + 1 , (end - i - 1) );

            vec_node.push_back( classOfType(tag, i, end, &data) );
        }

        i++;
    }

    // print each node tag
    for ( vector<classOfType>::iterator itr = vec_node.begin(); itr != vec_node.end(); ++itr )
    {
        cout << itr->getName() << endl;
        cout << itr->getText() << endl;
    }

    return 0;
}

string classOfType::getName() {
    return name;
}

string classOfType::getText() {
    string return_text = "";
    if ( sizeof(text) > 0 )
    {
        for ( vector<string>::iterator itr = text.begin(); itr != text.end(); ++itr )
        {
            return_text += *itr;
        }
    }

    return return_text;
}

void classOfType::nodeTextRead(string t) {
    text.push_back(t);
}

void classOfType::nodeStart(string n, int p, int e, string* d) {
    name = n;
    p_data = d;
    pos = p;

    string substring;
    int substr_end = p_data->find("</" + name, p);
    substring = p_data->substr( e + 1, substr_end - e -1 );
    nodeTextRead(substring);
}

classOfType::classOfType(string n, int p, int e, string* d) {
    nodeStart(n, p, e, d);
}