#include <iostream>
using namespace std;

// Print number counting from N to 1.

int main()
{
    int N;
    cin >> N;

    while (N >= 1)
    {
        cout << N << "  ";
        N--;
    }

    return 0;
}