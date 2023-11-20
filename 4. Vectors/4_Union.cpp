#include <iostream>
#include <vector>
using namespace std;

bool isPresent(vector<int> urr, int num)
{
    for (int i = 0; i < urr.size(); i++)
    {
        if (urr[i] == num)
            return true;
    }
    return false;
}
int main()
{
    system("cls");

    vector<int> arr{10, 2, 3, 4, 23};
    vector<int> brr{6, 23};
    vector<int> urr;

    for (int i = 0; i < arr.size(); i++)
        urr.push_back(arr[i]);

    for (int i = 0; i < brr.size(); i++)
    {
        if (isPresent(urr, brr[i]))
            continue;
        else
            urr.push_back(brr[i]);
    }

    for (int i = 0; i < urr.size(); i++)
    {
        cout << urr[i] << "  ";
    }
    return 0;
}

/* Algorithm:

1. Append all the elements of `arr` into `urr`.
2. Then check for each element of `brr` if it is already present.
3. If present, continue to the next iteration, else append it.
4. There you have it!
*/