// If found, print index of the position of the Key element.
// Else, print "Not found".

#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int key, int indexArr[])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            indexArr[count] = i;
            count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {1, 3, 4, 2, 4, 2, 1, 4};
    int n = 8;
    int key = 4;

    int indexArr[] = {};
    int count = linearSearch(arr, n, key, indexArr);

    if (count == 0)
        cout << "Not found";
    else
    {
        cout << "Found at: ";
        for (int i = 0; i < count; i++)
            cout << indexArr[i] << " ";
    }

    return 0;
}
