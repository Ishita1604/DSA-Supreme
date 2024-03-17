#include <bits/stdc++.h>
using namespace std;

bool binarySearch2D(int arr[][4], int rows, int cols, int target)
{
    int s = 0;
    int e = rows * cols - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        // Calculate the rowIndex and colIndex of that element:
        int rowIndex = mid / cols;
        int colIndex = mid % cols;

        if (arr[rowIndex][colIndex] == target)
        {
            // cout << "Row Index: " << rowIndex << endl;
            // cout << "Column Index: " << colIndex << endl;
            return true;
        }
        else if (arr[rowIndex][colIndex] < target)
        {
            // Search in right.
            s = mid + 1;
        }
        else
        {
            // Search in left.
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }

    return false;
}

int main()
{
    int rows = 5;
    int cols = 4;
    int arr[5][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}};
    int target = 9;
    bool present = binarySearch2D(arr, rows, cols, target);
    if (present)
        cout << "FOUND!" << endl;
    else
        cout << "NOT FOUND!" << endl;

    return 0;
}