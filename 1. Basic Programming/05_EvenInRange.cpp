// Find even numbers in the range [a, b].
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cout << "Enter the Value of a: ";
    cin >> a;
    cout << "Enter the Value of b: ";
    cin >> b;

    if (a % 2 != 0)
        a = a + 1;

    for (int i = a; i <= b; i = i + 2)
        cout << i << "  " << endl;

    return 0;
}
