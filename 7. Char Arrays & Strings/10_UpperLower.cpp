#include <bits/stdc++.h>
using namespace std;

// Convert uppercase to lowercase and vice-versa in a string.



// WAY 1: Using in-built functions.
void toggleCase1(string str)
{
    for (char x : str)
    {
        if (isupper(x))
        {
            char l = char(tolower(x));
            cout << l;
        }
        else if (islower(x))
        {
            char u = toupper(x);
            cout << u;
        }
        else cout << x; // Non-alphabetic characters remain same.
    }
    cout << endl;
}



/*
    0 -→ 48
    A -→ 65
    a -→ 97
*/

// WAY 2: By checking ASCII value.
void toggleCase2(string str)
{
    for (char x : str)
    {
        if (x >= 65 && x <= 90) // Uppercase letter.
        {
            x = x + 32; // Converted upper to lower.
            cout << x;
        }
        else if (x >= 97 && x <= 122) // Lowercase.
        {
            x = x - 32; // Converted lower to upper.
            cout << x;
        }
        else cout << x;
    }
    cout << endl;
}



int main()
{
    string str = "Ishita Gupta";
    toggleCase1(str);
    toggleCase2(str);

    cout << str << endl; // Original string remains unchanged.

    return 0;
}