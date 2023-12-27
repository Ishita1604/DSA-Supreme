// From two arrays, return the triplets that have sum equal to the given number.

#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> arr = {10, 20, 90};
    vector<int> brr = {30, 40, 50};

    int sum = 80;
    int pair_sum = 0;
    int triple_sum = 0;

    /* First Way: */
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < brr.size(); j++)
        {
            pair_sum = arr[i] + brr[j];
            int third_number = sum - pair_sum;

            // Check if the third_number is present in `arr`:
            for (int k = i + 1; k < arr.size(); k++)
            {
                if (arr[k] == third_number)
                    cout << "(" << arr[i] << ", " << brr[j] << ", " << third_number << ")" << endl;
            }

            // Check if the third_number is present in `brr`:
            for (int x = j + 1; x < brr.size(); x++)
            {
                if (brr[x] == third_number)
                    cout << "(" << arr[i] << ", " << brr[j] << ", " << third_number << ")" << endl;
            }
        }
    }





    /* Second Way: */
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < brr.size(); j++)
    //     {
    //         for (int k = i + 1; k < arr.size(); k++)
    //         {
    //             if (arr[i] + brr[j] + arr[k] == sum)
    //                 cout << "(" << arr[i] << ", " << brr[j] << ", " << arr[k] << ")" << endl;
    //         }
    //         for (int x = j + 1; x < brr.size(); x++)
    //         {
    //             if (arr[i] + brr[j] + brr[x] == sum)
    //                 cout << "(" << arr[i] << ", " << brr[j] << ", " << brr[x] << ")" << endl;
    //         }
    //     }
    // }

    return 0;
}
