#include <bits/stdc++.h>
using namespace std;

// Print ASCII value of each character in a string.
// In Python, we have ord() built-in function to print ASCII value of a character.

/*
    0 -→ 48
    A -→ 65
    a -→ 97

*/

int main()
{
    string str = "a1bd";
    for (char c : str)
    {
        int ascii = c; // As int(c) = ASCII value of character c.
        cout << ascii << " ";
    }

    return 0;
}