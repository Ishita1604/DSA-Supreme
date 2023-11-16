#include <iostream>
#include <vector>
using namespace std;

/*
1. Vector is called DYNAMIC ARRAY.
2. Always use size() function because sizeof() not helpful here, it's values are compiler dependent.
    _________________
   | n = arr.size() |
   ‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾
3. Array:       int arr[n] is bad practice.
   Vector:      vector<int> arr(n) is not.

4. Automatically doubles its size, no need to change the memory size.

*/

int main()
{
    system("cls");
    vector<int> ishi;            // Declaration
    cout << ishi.size() << endl; // Default size is 0.

    // Initialisation
    vector<int> a{10, 20, 30, 40};
    cout << a.size() << endl;

    // Declaration using size.
    vector<int> arr(16);

    // Declaration using size and initialize all elements.
    vector<int> avi(12, -2); // Each element initialised as -2.

    cout << "\nUsing sizeof: " << sizeof(arr) / sizeof(int) << endl; // Compiler dependent.
    cout << "Size: " << arr.size() << endl;                          // Stored elements.
    cout << "Capacity: " << arr.capacity() << endl;                  // Memory allocated or currenty holding.
    cout << "Empty? " << arr.empty() << endl;

    // Insert
    arr.push_back(69);
    arr.push_back(32);

    // Delete
    arr.pop_back();
    cout << "Size: " << arr.size() << endl;

    // Print
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << "  ";

    cout << endl;
    for (int i = 0; i < avi.size(); i++)
        cout << avi[i] << "  ";

    return 0;
}
