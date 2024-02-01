/** You are given a large integer represented as an integer array digits.
Where each digits[i] is the ith digit of the integer.
The digits are ordered from most significant to least significant in left-to-right order.
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
**/

#include <bits/stdc++.h>
using namespace std;

void print(vector<int> digits)
{
    for (int i = 0; i < digits.size(); i++)
        cout << digits[i] << "  ";
    cout << endl;
}
class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        for (int i = n - 1; i >= 0; i--)
        {
            if (digits[i] < 9)
            {
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }

        // If we reach here that means we never got any other digits than 9.
        // All were 9 that is.

        // LOGIC TO INSERT 1 AT BEGINNING:
        digits.push_back(0); // Pushed another 0 at end with O(1) time complexity.
        digits[0] = 1;

        return digits;
    }
};
int main()
{
    vector<int> digits = {9, 9, 9};
    print(digits);
    Solution obj;
    obj.plusOne(digits);
    print(digits);
    return 0;
}