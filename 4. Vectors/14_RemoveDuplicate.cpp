// ************* Approach: *************

// 1. Sort the array.
// 2. If two adjacent elements are same, duplicate exists.    → TIME: O(N) to iterate over each element.
// 3. Remove that element.                                    → TIME: O(N) to shift each element by one space.
// 4. Reduce size by 1.
// 5. Move all elements after that by one space.

// Time Complexity: O(N)

#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    vector<int> arr = {1, 2, 3, 3, 4, 5, 5, 5, 5, 10};
    int n = arr.size();

    printArray(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == arr[i + 1]) // Duplicate exists.
        {
            int dupl = arr[i];
            int dupl_index = i;
            while (dupl_index < n) // Duplicate element se last tak saare ek ek shift.
            {
                arr[dupl_index] = arr[dupl_index + 1];
                dupl_index++;
            }
            n = n - 1; // Finally reduce the size by 1 for 1 duplicate found.
            i--;       // Recheck if there are more than 2 duplicates.
        }
    }
    cout << "\n\n";
    printArray(arr, n);

    return 0;
}
