// In-built Binary Search Function of STL:
// binary_search(begin_ptr, end_ptr, target)

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[100] = {1, 3, 5, 6, 7, 8, 9, 10, 13, 19};
    int size = 10;
    int target = 10;

    // bool targetFound = binary_search(arr, arr + size, target);

    // if (targetFound == false)
    //     cout << "Not Found" << endl;
    // else
    //     cout << "Found" << endl;

    if (binary_search(arr, arr + size, target))
        cout << "Found!" << endl;
    else
        cout << "Not Found!" << endl;

    return 0;
}