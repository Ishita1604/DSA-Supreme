#include <iostream>
#include <vector>
using namespace std;

// Check out next code for XOR explanation.
// XOR of same elements gives 0, different give 1.
// In entire array, XOR of each element is done, and same elements get cancelled.

// 1 4 6 2 7 6 2 1 7
int findUnique(vector<int> arr)
{
    int result = 0; // Because XOR with 0 se koi fark nahi padta.
    for (int i = 0; i < arr.size(); i++)
    {
        result = result ^ arr[i];
        cout << "XOR " << result << endl;
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the Size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the Elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int result = findUnique(arr);
    cout << "Unique Element in Vector is: " << result << endl;

    return 0;
}


/******** Drawbacks of this Approach:
 * 1. Non-unique elements must appear an even number of times so that the XOR cancellations work effectively.
 * 2. The approach fails when there are multiple unique elements in the array.
*********/
