#include <iostream>
using namespace std;

// Count the number of 0's and 1's in an array.

int main()
{
    int arr[] = {1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 2, 3, 4};
    int i, count_1 = 0, count_0 = 0;
    int size = sizeof(arr) / sizeof(arr[0]);

    for (i = 0; i < size; i++)
    {
        if (arr[i] == 1)
            count_1++;

        if (arr[i] == 0)
            count_0++;
    }
    cout << "Count of 1's: " << count_1 << endl;
    cout << "Count of 0's: " << count_0 << endl;

    return 0;
}
