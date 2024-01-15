/**** Dutch National Flag Algorithm / 2 Pointer Approach ****/

// Time complexity: O(n)
// Space: O(1)

#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> arr, int size)
{
    // for (int i = 0; i < arr.size(); i++)
    //     cout << arr[i] << "  ";

    // For each loop:
    for (auto i : arr)
        cout << i << "  ";
}

int main()
{
    vector<int> arr = {1, 0, 1, 0, 1, 1, 0, 1};
    int start = 0;            // Position to insert next 0.
    int end = arr.size() - 1; // Position to insert next 1.
    int i = 0;                // For iterating the entire vector.

    // while (start <= end)
    while (i <= end)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[start]);
            start++;
            i++;
        }
        else
        {
            swap(arr[i], arr[end]);
            end--;
            // No `i++` here, most important step.
            // `i` is saying it will stand on that index only until it will become 0.
            // To re-evaluate element after swap at arr[i] in next iteration.
        }
    }

    print(arr, arr.size());

    return 0;
}
