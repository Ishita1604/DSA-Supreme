#include <iostream>
#include <vector>
using namespace std;

void print1DVector(vector<int> v, int size)
{
    for (int i = 0; i < size; i++)
        cout << v[i] << "  ";
    cout << endl;
}

void print2DVector(vector<vector<int>> V, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << V[i][j] << "  ";
        cout << endl;
    }
}

int main()
{
    // 1-D Array
    vector<int> arr;
    vector<int> brr(5);
    brr = {1, 2, 3, 4};
    vector<int> crr{69, 69, 69, 69};
    crr.push_back(8);
    int size = crr.size();
    print1DVector(crr, size);

    // 2-D Array
    vector<vector<int>> drr;
    vector<vector<int>> err(5, vector<int>(3, 1)); // Size 5x3, all initialized to 1.
    err = {{1, 2, 3},
           {4, 5, 6},
           {7, 8, 6},
           {10, 5, 6},
           {12, 5, 9}};
    int rows = err.size();
    int cols = err[0].size();
    print2DVector(err, rows, cols);

    cout << "Everything is Fine!" << endl;
    return 0;
}

/*
                                      Size    Initialized value
                                         ↓    ↓
vector<vector<int>> A(rows, vector<int>(cols, 0));
                        ↑   --------------------
                       SIZE          ↑
                                INITIALIZED VALUE

*/