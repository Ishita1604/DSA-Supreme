/********* Linear Search Implementation *********/
// Time: O(n)

#include <iostream>
using namespace std;

int linearSearch1(int arr[], int size, int key)
{
    // Using `return`:
    // No need of `flag` or `break` here because of `return`!!
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1; // Not present.
}

int linearSearch2(int arr[], int size, int key)
{
    // Using `flag` and `break`:
    int flag = -1, i;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            flag = 1; // Element found.
            break;    // No need to further traverse the array.
        }
    }
    if (flag != -1)
        return i;
    return flag;
}

int main()
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = 10;
    int key = 4;

    int ans1 = linearSearch1(arr, size, key);
    if (ans1 == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found at Index: " << ans1 << endl;



    // int ans2 = linearSearch2(arr, size, key);
    // if (ans2 == -1)
    //     cout << "Not Found" << endl;
    // else
    //     cout << "Found at Index: " << ans2 << endl;

    return 0;
}