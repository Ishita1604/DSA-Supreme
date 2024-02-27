#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* Store & search RIGHT!! */

int firstOcc(vector<int> v, int target)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = start + ((end - start) / 2);
    int ans = -1;

    while (start <= end)
    {
        if (target == v[mid])
        {
            // Store & search right for another last occurence:
            ans = mid;
            start = mid + 1;
        }
        else if (target > v[mid])
            start = mid + 1; // Search right.
        else
            end = mid - 1; // Search left.

        mid = start + ((end - start) / 2);
    }

    return ans;
}

int main()
{
    system("cls");

    vector<int> v{1, 3, 3, 3, 5, 7, 7, 8, 9, 10};
    int target = 3;

    int ans = firstOcc(v, target);

    if (ans == -1)
        cout << "Target Not Found" << endl;
    else
        cout << "Target Last Found At: " << ans << endl;

}