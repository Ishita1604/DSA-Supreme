#include <bits/stdc++.h>
using namespace std;

void print(vector<int> sub_arr)
{
    for (int i = 0; i < sub_arr.size(); i++)
        cout << sub_arr[i] << "  ";
    cout << endl;
}

void allSubarray(int arr[], int n)
{
    int a, b;
    vector<int> sub_arr;
    for (int a = 0; a < n; a++)
    {
        for (int b = a; b < n; b++)
        {
            sub_arr.push_back(arr[b]);
            print(sub_arr);
        }
        sub_arr.clear();
    }
}

int main()
{
    // int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int arr[] = {-2, 1, 5};
    int n = sizeof(arr) / sizeof(int);

    allSubarray(arr, n);

    return 0;
}