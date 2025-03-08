class Solution
{
public:
    // Time: O(1)
    // Space: O(1)
    bool checkPowersOfThree(int n)
    {
        // Here i represents power of 3 starting from backwards.
        for (int i=14; i>=0; i--)      // Highest power of 3 within 1 ≤ n ≤ 10^7 is 3^14.
        {
            int x = pow(3, i);         // Compute 3^i.
            if (n - x >= 0) n -= x;    // Number can still be represented as more powers of 3.
            if (n == 0) return true;   // Sum of distinct powers of 3.
        }
        return false;                  // Can't be.
    }
};
