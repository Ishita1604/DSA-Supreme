// 3) This code tries to move all negative numbers to one side but have some errors, can you spot those errors?
// Hint: Incomplete conditions applied.

// Time: O(n)
// Space: O(1)

#include <iostream>
using namespace std;

void moveNegative(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (arr[i] < 0)
        {
            i++; // Move to the next element if it's already negative.
        }
        while (arr[j] > 0)
        {
            j--; // Move to the previous element if it's already positive.
        }
        if (i < j) // To avoid unnecessary swaps when `i` and `j` have crossed each other.
        {
            // Remaining cases where swapping is required.
            swap(arr[i], arr[j]); // Swap the elements.
            i++;
            j--;
        }
    }
}

int main()
{
    int n = 5;
    int arr[n] = {2, -3, -1, 5, -4};
    moveNegative(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}