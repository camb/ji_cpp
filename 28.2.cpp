// Chapter 28 Practice Problem 2
// Modify the HTML parser you implemented in Chapter 19 about Strings so that it can read data from a file on disk.

// Chapter 19 Practice Problem 2
// Write a program that reads in HTML text that the user types in (don't worry, we'll cover how to read from a file later). It should support the following HTML tags: <html>, <head>, <body>, <b>, <i>, and <a>. Each HTML tag has an open tag, e.g. <html>, and a closing tag that has a forward-slash at the start: </html>. Inside the tag is text that is controlled by that tag: <b>text to be bolded</b> or <i>text to be italicized</i>. The <head> </head> tags control text that is metadata, and the <body></body> tags surround text that is to be displayed. <a> targs are used for hyperlinks, and have an URL in the following format: <a href=URL>text</a>.
// Once your program has read in some HTML, it should simply ignore <html>. It should remove any text from the <head> section so that it doesn't show up when you output it. It should then display all text in the body, modifying it so that any text between a <b> and a </b> will show up with asterisks(*) around it, amy text inside <i> and </i> will show up with underscores (_) around it, and any text with a <a href=linkurl>link text</a> tag shows up as link text (linkurl).

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

int main () {
    ifstream html_file("28.2.html");
    if ( !html_file.is_open() )
    {
        cout << "Failed to open HTML file!\n";
        return 0;
    }

    stringstream buffer;
    buffer << html_file.rdbuf();
    string data;
    data = buffer.str();
    cout << "Original HTML:\n";
    cout << data << endl << endl;
    
    // remove newlines.
    for ( int i = data.find("\n", 0); i != string::npos; i = data.find("\n", i))
    {
        data.erase(i, 1);
    }

    // ignore/remove <html> tag
    for ( int i = data.find("<html>", 0); i != string::npos; i = data.find("<html>", i))
    {
        data.erase(i, i + 6);
    }
    for ( int i = data.find("</html>", 0); i != string::npos; i = data.find("</html>", i))
    {
        data.erase(i, i + 7);
    }

    // remove <body> tag
    for ( int i = data.find("<body>", 0); i != string::npos; i = data.find("<body>", i))
    {
        data.erase(i, 6);
    }
    for ( int i = data.find("</body>", 0); i != string::npos; i = data.find("</body>", i))
    {
        data.erase(i, 7);
    }

    // ignore/remove <head> tag
    for ( int i = data.find("<head>", 0); i != string::npos; i = data.find("<head>", i))
    {
        int end = data.find("</head>", i);
        data.erase(i, (end - i) + 7);
    }

    // replace <b> tags with * around text
    for ( int i = data.find("<b>", 0); i != string::npos; i = data.find("<b>", i))
    {
        data.erase(i, 3);
        data.insert(i, "*");
    }
    for ( int i = data.find("</b>", 0); i != string::npos; i = data.find("</b>", i))
    {
        data.erase(i, 4);
        data.insert(i, "*");
    }

    // replace <i> tags with _ around text
        for ( int i = data.find("<i>", 0); i != string::npos; i = data.find("<i>", i))
    {
        data.erase(i, 3);
        data.insert(i, "_");
    }
    for ( int i = data.find("</i>", 0); i != string::npos; i = data.find("</i>", i))
    {
        data.erase(i, 4);
        data.insert(i, "_");
    }

    // replace <p> tag with a newline.
    for ( int i = data.find("<p>", 0); i != string::npos; i = data.find("<p>", i))
    {
        data.erase(i, 3);
    }
    for ( int i = data.find("</p>", 0); i != string::npos; i = data.find("</p>", i))
    {
        data.erase(i, 4);
        data.insert(i, "\n");
    }

    // replace <a> tag with link in parens following text
    string link_text;
    for ( int i = data.find("<a href=\"", 0); i != string::npos; i = data.find("<a href=\"", i))
    {
        int link_end = data.find( "\">", i );
        link_text = data.substr( i + 9, link_end - (i + 9) );
        data.erase(i, link_end - (i + 9) + 11);
        int j = data.find("</a>", 0);
        data.erase(j, 4);
        link_text = "(" + link_text + ")";
        data.insert(j, link_text);
    }

    cout << "Modified HTML:\n";
    cout << data << endl;

    return 0;
}