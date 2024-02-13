#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = start + ((end - start) / 2);

    while (start <= end)
    {
        if (target == v[mid])
            return mid;
        else if (target > v[mid]) // Search in right.
            start = mid + 1;
        else // Search in left.
            end = mid - 1;

        // Update `mid`:
        mid = start + ((end - start) / 2);
    }
    return -1;
}

int main()
{
    vector<int> v{1, 3, 5, 6, 7, 8, 9, 10, 13, 19};
    int target = 9;

    int indexOfTarget = binarySearch(v, target);

    if (indexOfTarget == -1)
        cout << "Not Found!" << endl;
    else
        cout << "Found at Index " << indexOfTarget << endl;

    return 0;
}