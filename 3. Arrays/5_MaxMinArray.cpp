#include <iostream>
#include <climits>

using namespace std;

int getMax(int a[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        // maxi = max(maxi, a[i]);
        if (a[i] > maxi)
            maxi = a[i];
    }
    return maxi;
}

int getMin(int a[], int n)
{
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        // mini = min(mini, a[i]);
        if (a[i] < mini)
            mini = a[i];
    }
    return mini;
}

int main()
{
    int size;
    cout << "Enter Array Size: ";
    cin >> size;
    int arr[100];
    cout << "\nEnter the Elements --" << endl;
    for (int i = 0; i < size; i++)
        cin >> arr[i];

    cout << "\n\nMaximum Element IS: " << getMax(arr, size);
    cout << "\n\nMinimum Element IS: " << getMin(arr, size);

    return 0;
}
