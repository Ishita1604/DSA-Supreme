#include <iostream>
using namespace std;

int main()
{
    int n, arr[100];
    cout << "How many elements you want to Enter? ";
    cin >> n;
    cout << "Enter the Elements into the Array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Output Array: ";
    for (int i = 0; i < n; i++)
        cout << 2 * arr[i] << "  ";

    return 0;
}
