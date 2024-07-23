#include <iostream>
using namespace std;

void inputArray(int arr[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cin >> arr[i][j];
    }
}

void printArray(int arr[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
}

void printRowSum(int arr[100][100], int rows, int cols)
{
    for (int i = 0; i < rows; i++) // First row loop.
    {
        int row_sum = 0; // Important to declare here, so it gets initialized to zero for every new row.
        for (int j = 0; j < cols; j++)
        {
            row_sum = row_sum + arr[i][j];
        }
        cout << "Row (" << i << ") Sum is: " << row_sum << endl;
    }
}

void printColSum(int arr[100][100], int rows, int cols)
{
    for (int i = 0; i < cols; i++) // First column loop.
    {
        int col_sum = 0;
        for (int j = 0; j < rows; j++)
        {
            col_sum = col_sum + arr[j][i];
        }
        cout << "Column (" << i << ") Sum is: " << col_sum << endl;
    }
}

int main()
{
    int rows = 0;
    int cols = 0;

    cout << "Enter # Rows: ";
    cin >> rows;
    cout << "Enter # Columns: ";
    cin >> cols;

    int arr[100][100];
    inputArray(arr, rows, cols);
    printArray(arr, rows, cols);

    printRowSum(arr, rows, cols);
    printColSum(arr, rows, cols);

    return 0;
}