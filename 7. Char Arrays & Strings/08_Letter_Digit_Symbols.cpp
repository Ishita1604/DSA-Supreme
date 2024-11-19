#include <bits/stdc++.h>
using namespace std;

// Count letters, numbers, and special characters in a string.
// Anything that is not alpha-numeric, is a special character. Basically symbols and punctuation marks.

int main()
{
    string str = "helloXYZ#@12345_:;";
    int alpha_count = 0;
    int digit_count = 0;
    int symbol_count = 0;
    for (char c : str)
    {
        if (isalpha(c)) alpha_count++;
        else if (isdigit(c)) digit_count++;
        else symbol_count++;
    }

    cout << "Number of Letter(s) = " << alpha_count << endl;
    cout << "Number of Number(s) = " << digit_count << endl;
    cout << "Number of Special Character(s) = " << symbol_count << endl;

    return 0;
}