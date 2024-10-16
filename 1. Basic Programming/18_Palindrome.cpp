// Check whether the number is a Palindrome.
// Uncomment print statements to understand better.


/* ---- 1st Approach: ----
1. Store the number.
2. Find middle element.
3. Store the right of "mid".
4. Store the left of "mid".
5. Reverse one of them and compare.

Even:
1. Mid element (n/2) and (n/2 - 1), both must be equal.


---- 2nd Approach: ----
Reverse the entire number.
If same, it's a palindrome.


*/


#include <iostream>
using namespace std;

int reverse(int N)
{
    int reversed_number = 0;
    while (N != 0)
    {
        int r = N % 10;
        reversed_number = reversed_number * 10 + r;
        N /= 10;
    }
    return reversed_number;
}

int lengthFunc(int N)
{
    // Length of number
    int length = 0;
    while (N != 0)
    {
        N = N / 10;
        length++;
    }
    return length;
}

int main()
{
    int n;
    cout << "Enter a Number: ";
    cin >> n;

    int length = lengthFunc(n);

    // Even:
    if (length % 2 == 0)
    {
        int l = length / 2;
        // cout << "l is " << l << endl;

        int p = 1;
        for (int i = 0; i < l; i++)
            p = p * 10;
        // cout << "p " << p << endl;

        int first = n / p;
        // cout << "first " << first << endl;

        int second = n % p;
        second = reverse(second);
        // cout << "second " << second << endl;

        if (first == second) cout << "Palindrome";
        else cout << "Not a Palindrome";
    }

    // Odd:
    if (length % 2 != 0)
    {
        int l = (length / 2) + 1;
        // cout << "l is " << l << endl;

        int p = 1;
        for (int i = 0; i < l; i++)
            p = p * 10;
        // cout << "p " << p << endl;

        int first = n / p;
        // cout << "first " << first << endl;

        int second = n % (p / 10);
        second = reverse(second);
        // cout << "second " << second << endl;

        if (first == second) cout << "Palindrome";
        else cout << "Not a Palindrome";
    }

    return 0;
}
