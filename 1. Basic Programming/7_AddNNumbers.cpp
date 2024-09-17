#include <iostream>
using namespace std;

int main()
{
    int N, num, sum = 0;
    cout << "Enter the Value of N: ";
    cin >> N;
    cout << "Enter N Numbers: ";
    for (int i = 0; i < N; i++)
    {
        cin >> num;
        sum = sum + num;
    }
    cout << "Sum is " << sum;

    return 0;
}