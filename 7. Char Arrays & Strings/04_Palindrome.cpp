#include <bits/stdc++.h>
using namespace std;

int getLength(char word[])
{
    int length = 0;
    int i = 0;
    while (word[i] != 0) // ASCII value of NULL, present at the end of character array, is 0.
    {
        length++;
        i++;
    }
    return length;
}

bool isPalindrome(char word[])
{
    int i = 0;
    int j = getLength(word) - 1;
    while (i <= j)
    {
        if (word[i] != word[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    char word[] = "racecar1";
    // cout << "Length: " << getLength(word) << endl;
    bool ans = isPalindrome(word);
    if (ans)
        cout << "Given word IS a Palindrome!";
    else
        cout << "Given word is NOT a Palindrome!";

    return 0;
}