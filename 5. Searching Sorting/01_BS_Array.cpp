/********* Binary Search Implementation *********/
// Time complexity: O(log N)
// Space complexity: O(1)

#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;
    // int mid = (start + end) / 2;
    // Gives integer overflow issue.
    int mid = start + ((end - start) / 2);

    while (start <= end) // Parsing the entire array.
    {
        int element = arr[mid];

        if (target == element)
            return mid;
        else if (target < element)
        {
            // Search in the left side:
            end = mid - 1;
        }
        else // if (target > element)
        {
            // Search in the right side:
            start = mid + 1;
        }
        // Update `mid` for selected array:
        // mid = (start + end) / 2;
        mid = start + ((end - start) / 2);
    }
    // Out of the loop & no index returned.
    // Hence, target not found!

    return -1;
}

int main()
{
    int size = 10;
    int arr[10] = {2, 4, 6, 7, 8, 9, 11, 17, 19, 23};
    int target = -11;

    int indexOfTarget = binarySearch(arr, size, target);

    if (indexOfTarget == -1)
        cout << "\nNot Found!" << endl;
    else
        cout << "\nTarget Found at Index: " << indexOfTarget << endl;

    return 0;
}
