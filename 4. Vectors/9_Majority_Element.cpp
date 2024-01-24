#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> arr = {9, 3, 1, 6, 3, 3, 9, 9, 3, 1};
    int maxCount = 0;
    int majority_element = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxCount)
        {
            maxCount = count;
            majority_element = arr[i];
        }
    }
    cout << majority_element;
    return 0;
}