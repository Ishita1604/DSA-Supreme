// Rectangle or Square
#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int R, C;
    cout << "Enter the Number of Rows: ";
    cin >> R;
    cout << "Enter the Number of Columns: ";
    cin >> C;

    for (int row = 0; row < R; row++)
    {
        for (int col = 0; col < C; col++)
        {
            cout << " * ";
        }
        cout << endl;
    }

    return 0;
}
