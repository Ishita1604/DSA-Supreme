// 4) This code attempts to print elements (only once) which appear more than one time.
// Can you spot the error in the code?

#include <iostream>
#include <cstring>
using namespace std;

void printDuplicates(int arr[], int n)
{
    int freq[n + 1];
    memset(freq, 0, sizeof(freq)); // Initialize the frequency array to 0.
    bool flag = false;             // Added a flag to check if there are no duplicate elements.
    for (int i = 0; i <= n; i++)
    {
        freq[arr[i]]++; // Increment the frequency of each element in `arr` by 1.
        if (freq[arr[i]] == 2)
        {
            flag = true;
            cout << arr[i] << " ";
        }
    }
    if (!flag)
        cout << "No duplicate elements";
}

int main()
{
    int n = 6;
    int arr[n] = {3, 8, 1, 8, 8, 3};
    printDuplicates(arr, n);
    return 0;
}