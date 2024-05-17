// In-built sort() function of STL:
// sort(begin_ptr, end_ptr, greater<int>())

// 1. Beginning of the array / vector - arr / v.begin().
// 2. End of the array / vector - (arr + n) / v.end().
// 3. Optional parameter for when sorting in descending order

// Time: O(N*logN)
// Space: O(log N)

// Uses Introspective Sort (IntroSort), a hybrid of Quick, Heap, and Insertion Sort.
// Default Quick Sort.
// Switches to Heap Sort if unfair partitioning or time > N*logN.
// Insertion Sort if small array size.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    cout << "Sorted Array: " << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    vector<int> v = {11, 15, 18, 19, 16, 17, 13, 14, 12, 10};
    int N = v.size();
    sort(v.begin(), v.end());
    cout << "Sorted Vector: " << endl;
    for (int i = 0; i < N; i++)
        cout << v[i] << " ";

    return 0;
}
