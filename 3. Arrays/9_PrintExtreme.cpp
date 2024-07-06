#include <iostream>
using namespace std;

int main()
{
    int arr[] = {10, 20, 30, 40, 50, 60, 70};
    //            0   1   2   3   4   5   6
    int n = sizeof(arr) / sizeof(arr[0]);

    int start = 0, end = n - 1;
    while (true)
    {
        if (start == end)
        {
            cout << arr[start];
            break;
        }
        else if (start > end)
            break;

        cout << arr[start] << "  ";
        start++;
        cout << arr[end] << "  ";
        end--;
    }

    return 0;
}
