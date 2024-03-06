#include <iostream>
using namespace std;

int main()
{
    // Declaration
    // int arr[3][3];

    // Initialization
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int rows = 3;
    int cols = 3;

    /* Print Row - Wise */
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //         cout << arr[i][j] << "  ";
    //     cout << endl;
    // }



    /* Print Column - Wise */
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //         cout << arr[j][i] << "  ";
    //     cout << endl;
    // }



    /* Input Row - Wise */
    // for (int i = 0; i < rows; i++)
    // {
    //     for (int j = 0; j < cols; j++)
    //         cin >> arr[i][j];
    // }



    /* Input Column - Wise */
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> arr[j][i]; // Note this step.
    }
    // Input taken column-wise so it can be normally printed i.e. row-wise.



    return 0;
}
