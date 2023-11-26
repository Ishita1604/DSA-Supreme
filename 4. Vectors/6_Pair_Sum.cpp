#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr = {1, 4, 6, 2, 7, 9, 3};
    int sum = 9;
    // Outer loop finds pair's first element.
    // Inner loop finds pair's second element.
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            // Print all loops.
            // cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            if (arr[i] + arr[j] == sum)
                cout << "Pair found: (" << arr[i] << "," << arr[j] << ")" << endl;
        }
    }

    return 0;
}

/*
1) Find all pairs.
2) Check their sum.
3) Remember, `i` goes from 0 to size, but `j` goes (i+ 1) to size.
*/
