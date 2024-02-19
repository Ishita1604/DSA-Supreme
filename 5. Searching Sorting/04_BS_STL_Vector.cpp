// In-built Binary Search Function of STL:
// binary_search(begin_ptr, end_ptr, target)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v{1, 3, 5, 6, 7, 8, 9, 10, 13, 19};
    int target = 34;

    bool targetFound = binary_search(v.begin(), v.end(), target);

    if (targetFound == false)
        cout << "Not Found!" << endl;
    else
        cout << "Found!" << endl;

    return 0;
}