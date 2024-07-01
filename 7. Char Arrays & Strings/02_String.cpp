#include <bits/stdc++.h>
using namespace std;

// Both character arrays & strings are used to store sequences of characters.
// But they have some key differences:

// Character Array: Data structure that stores elements of 'char' datatype.
// Declared using brackets.
// char arr[] = {'h', 'e', 'l', 'l', 'o'};
// Is static as fixed size.
// Ends with a null character that can be accessed. We manually insert the '\0' character.
// String manipulation done manually using strcpy(), strcat(), strlen(), etc.
// Faster, memory efficient.


// String: A datatype itself.
// Declared using double quotes.
// string arr = "hello";
// Dynamic in nature as automatically manages memory.
// Null can't be accessed easily and is inserted on its own.
// String manipulation with built-in functions like append(), substr(), find(), etc.
// Flexible, easy to use.


int main()
{
    string str;
    str[0] = 'B';
    str[1] = 'a';
    str[2] = '\0';
    str[3] = 'b';
    str[4] = 'b';
    str[5] = 'a';
    str[6] = '\0';
    str[7] = 'r';
    cout << "String: " << str << endl;

    char ch[100];
    ch[0] = 'B';
    ch[1] = 'a';
    ch[2] = '\0';
    ch[3] = 'b';
    ch[4] = 'b';
    ch[5] = 'a';
    ch[6] = '\0';
    ch[7] = 'r';
    cout << "Character Array: " << ch << endl;

    // In-built STL functions for strings:
    string name = "Ishita";
    cout << "Length: " << name.length() << endl;
    cout << "Empty? " << name.empty() << endl;
    name.push_back('A');
    cout << name << endl;

    name.pop_back();
    cout << name << endl;

    cout << name.substr(0, 4) << endl;

    string first_word = "Success";
    string second_word = "Easy";
    if (first_word.compare(second_word) == 0)
        cout << "Exactly same strings!" << endl;
    else
        cout << "Strings NOT same!" << endl;

    string x = "abcd";
    string y = "pqrs";
    cout << x.compare(y) << endl; // Gives -1 as 'a' is smaller than 'p'.
    cout << y.compare(x) << endl; // Gives 1 as 'p' is greater than 'a'.
    // If first character is same in both, then it checks for next.

    string sentence = "The only thing we have to fear is fear itself.";
    string target = "The";
    cout << sentence.find(target) << endl;
    if (sentence.find(target) != 0)
        cout << "Target not found!";
    else
        cout << "Found!" << endl;

    string target2 = "just";
    sentence.replace(4, 4, target2); // The 1st argument is the word to be replaced, 2nd is how many characters to be replaced.
    cout << sentence << endl;

    sentence.erase(0, 3);
    cout << sentence << endl;

    return 0;
}
