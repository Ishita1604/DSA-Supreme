#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "  ";
    cout << endl;
}

int main()
{
    vector<int> arr = {5, 9, 7, 8, 6, 2};
    int n = arr.size();

    cout << "Initial Array: ";
    print(arr, n);

    int no_of_rotations = 0;
    cout << "Enter the Number of Left Rotations: ";
    cin >> no_of_rotations;

    // Rotate Left Side:
    for (int i = 0; i < no_of_rotations; i++)
    {
        int left_most_element = *arr.begin(); // The arr.begin() function returns an iterator, not an integer.
        // cout << left_most_element << endl;

        cout << "Rotating ... (" << i + 1 << ")" << endl;
        arr.erase(arr.begin()); // Returns a vector type object.
        arr.push_back(left_most_element);
        print(arr, n);
    }

    return 0;
}