#include <bits/stdc++.h>
using namespace std;

// Find the difference between the number of consonants and vowels.

int main()
{
    int vowel_count = 0;
    int consonant_count = 0;
    string str = "abcdefghijklmnopqrstuvwxyz_1234@#!;";

    for (char x : str)
    {
        if (isalpha(x))
        {
            if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
                vowel_count++;
            else consonant_count++;
        }
    }

    cout << "# of Vowel(s) = " << vowel_count << endl;
    cout << "# of Consonant(s) = " << consonant_count << endl;
    int diff = abs(vowel_count - consonant_count);
    cout << "Difference = " << diff << endl;

    return 0;
}