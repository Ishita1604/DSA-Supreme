#include <bits/stdc++.h>
using namespace std;


/************* First Approach: *************/
// Take XOR of an element with every other element.
// If XOR == 0, then duplicate is found.
// Time Complexity: O(n^2)
void xorMethod(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1 + i; j < n; j++)
        {
            if ((arr[i] ^ arr[j]) == 0)
                cout << "Duplicate Element: " << arr[i] << endl;
        }
    }
}



/************* 2nd Approach: *************/
// Sort the vector.
// If two adjacent elements are equal, duplicate is found.
// Time Complexity: O(nlogn)
void sortMethod(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    for (int i = 0; i < (n - 1); i++)
    {
        if ((arr[i] == arr[i + 1]))
            cout << "Duplicate Element: " << arr[i] << endl;
    }
}



/************* 3rd Approach: *************/
// Use unordered set to check for duplicate elements.
// Time: O(N) due to array traversal. Insertion and lookup in set take O(1).
// Space: O(N) in worst case, O(K) general case.
vector<int> freqMethod(vector<int> arr, int n)
{
    unordered_set<int> set;
    vector<int> duplicates_arr;
    for (int i = 0; i < n; i++)
    {
        if (set.find(arr[i]) == set.end()) // Element not already present.
            set.insert(arr[i]);
        else
        {
            // Duplicate found.
            duplicates_arr.push_back(arr[i]);
        }
    }
    return duplicates_arr; // No duplicates.
}



int main()
{
    vector<int> arr = {-3, 7, 4, 65, -3, 4, -9, 12, 80};
    int n = arr.size();
    // xorMethod(arr, n);
    // sortMethod(arr, n);
    vector<int> res = freqMethod(arr, n);
    if (res.size() > 0)
    {
        cout << "Duplicate element(s): " << endl;
        for (int num : res)
            cout << num << "  ";
    }
    else
        cout << "No duplicates exist!" << endl;

    return 0;
}