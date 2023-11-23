#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{10, 2, 77, 3, 30, 3, 77, 4, 19, 8};
    vector<int> brr{6, 3, 23, 77, 30};
    vector<int> urr;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr.size(); j++)
        {
            if ((arr[i] == brr[j]))
            {
                urr.push_back(arr[i]);
                // Mark the element to prevent further matching.
                brr[j] = -1;
            }
        }
    }
    for (int i = 0; i < urr.size(); i++)
        cout << urr[i] << "  ";

    if (urr.empty())
        cout << "Nothing in common" << endl;

    return 0;
}

/* Algorithm:

1. Nested for loop to check if any element in `arr` == `brr`.
2. If it is then append to `urr` and print.
3. If `urr` is empty, means nothing in common!
4. Marking is an important step so if same number comes more times in one array & only once in other, it gives answer as one common only.
*/
