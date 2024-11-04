#include <iostream>
using namespace std;

int main()
{
    float a, b, c;
    cout << "Enter the Sides of the Triangle: ";
    cin >> a >> b >> c;

    if ((a + b >= c) && (b + c >= a) && (a + c >= b))
        cout << "Valid\n";
    else
        cout << "Not valid\n";

    return 0;
}
