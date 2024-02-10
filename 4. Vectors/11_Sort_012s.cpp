#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr, int size)
{
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "  ";
}

int main()
{
    cout << "Sorting ...\n";
    vector<int> arr = {2, 0, 1, 1, 2, 2, 0, 1, 0, 2, 1};
    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

    // Can't do (start <= end).
    // while (i <= end)
    while (start <= end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[start]);
            start++;
            i++;
        }
        else if (arr[i] == 1)
        {
            swap(arr[i], arr[start]);
            i++;
        }
        else
        {
            swap(arr[i], arr[end]);
            end--;
        }
    }

    print(arr, arr.size());

    return 0;
}