#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    /*
    // METHOD 1: Swap count method.
    vector<int> arr = {-1, 0, 2, 34, -23, 12, -9};
    int n = arr.size();
    int swap_count = 0; // Keep swapping the found negative number till this index.
    cout << "Start" << endl;
    cout << "Original:" << endl;
    print(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            for (int x = i; x > swap_count; x--)
                swap(arr[x - 1], arr[x]);
            swap_count++;
        }
        else
            continue;
    }

    cout << "Final:" << endl;
    print(arr, n);

    return 0;
    */





    /*
    // METHOD 2: Dutch National Flag Algorithm / 2 Pointer.
    // Time: O(n)
    // Space: O(1)
    vector<int> arr = {-1, 0, 2, 34, -23, 12, -9};
    int l = 0;
    int h = arr.size() - 1;

    while (l <= h)
    {
        if (arr[l] < 0)
            l++;
        else if (arr[h] >= 0)
            h--;
        else
        {
            swap(arr[l], arr[h]);
            // Saved some extra iterations here! :)
            l++;
            h--;
        }
    }
    print(arr, arr.size());

    return 0;
    */

}

/*
1. For every element in array, check if it is negative.
2. If it is, then keep swapping till it reaches front of array.
3. Next found negative number is placed next to it, And so on ...
*/