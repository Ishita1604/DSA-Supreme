#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    int n = sizeof(arr) / sizeof(arr[0]);
    print(arr, n);

    // Using 2 Pointer Approach:
    // NOT declared in while loop.
    int start = 0;
    int end = n - 1;

    while (start <= end)
    {
        if (start == end)
            break;

        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    print(arr, n);
    return 0;
}

/* Algorithm:
1) Get the 1st and last extremes.
2) Swap them and update the pointers.
3) Move to the next extremes.
4) Repeat step 2.
5) Keep on doing this till start <= end.

*/
