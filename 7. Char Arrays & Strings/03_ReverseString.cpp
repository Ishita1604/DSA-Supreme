#include <bits/stdc++.h>
using namespace std;

// Using 2-pointer approach to reverse the character array.
// Time: O(N)
// Space: O(1)
void reverseString(char word[])
{
    int i = 0;                // Start index.
    int j = strlen(word) - 1; // End index.
    while (i <= j)            // Swap positions till they meet or cross each other.
    {
        swap(word[i], word[j]);
        i++;
        j--;
    }
}


// Using stack data structure.
// As stack follows Last-In-First-Out (LIFO) order, last pushed character is the first one popped out.
// Thus, the last character of original array becomes the 1st character in the reversed array.
// Time: O(N)
// Space: O(N)
void reverseString2(char word[])
{
    stack<char> st;
    int len = strlen(word);
    for (int i = 0; i < len; i++) // Push characters onto the stack.
        st.push(word[i]);
    for (int i = 0; i < len; i++) // Pop characters from the stack and place them back into the array.
    {
        word[i] = st.top();
        st.pop();
    }
}



int main()
{
    char word[] = "Hello";
    cout << "Word originally: " << word << endl;
    reverseString(word);
    // reverseString2(word);
    cout << "After reversing: " << word << endl;

    return 0;
}
