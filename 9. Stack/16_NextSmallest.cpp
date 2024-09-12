#include <bits/stdc++.h>
using namespace std;

// Find the next smallest element in an array.
// Link: [https://www.naukri.com/code360/problems/next-smaller-element_1112581]

// You are given an array 'ARR' of integers of length N.
// Find the NSE for each array element.
// Next Smaller Element (NSE) for an element is the 1st element to its right which has a strictly smaller value than that element.
// If for an element the NSE does not exist, print -1 for that element.

// Example:
// If the given array is [2, 3, 1], we need to return [1, 1, -1].
// Because for 2, 1 is the Next Smaller Element.
// For 3, 1 is the Next Smaller Element.
// And for 1 there is no Next Smaller Element hence the answer for this element is -1.

// ALGORITHM:
// Traverse the array from right to left to avoid O(N^2) time complexity from left-to-right traversal.
// Initialize a stack and push -1 as its NSE -1.
// For each element, check if stack's top is smaller then return it.
// If not, pop elements until a smaller one.
// At the end if no NSE exists, base of stack i.e. -1 would be returned.
// Lastly push current element in stack to potentially serve as NSE for future elements.

// TIME: O(N) as each array element is traversed once from right to left, while checking, popping and pushing to stack take constant time.
// SPACE: O(N) due to stack.
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> v(n);
    stack<int> st;
    st.push(-1); // Initialize stack with -1.
    for (int i = n - 1; i >= 0; i--)
    {
        while (st.top() >= arr[i])
        {
            if (!st.empty()) st.pop();
        }
        // This inserts elements in reverse order into the array, so avoid!
        // v.push_back(st.top());
        v[i] = st.top(); // Inserts elements from right to left.
        st.push(arr[i]);
    }
    return v;
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    vector<int> arr = {2, 1, 4, 3};
    int n = 4;
    vector<int> ans = nextSmallerElement(arr, n);
    print(ans);
    return 0;
}