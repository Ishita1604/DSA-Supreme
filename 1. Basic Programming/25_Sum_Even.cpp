#include <iostream>
using namespace std;

// Print sum of all even numbers from 1 to N.

int evenSum(int N)
{
    int sum = 0;
    for (int i = 2; i <= N; i = i + 2)
        sum = sum + i;
    return sum;
}

int main()
{
    int N;
    cout << "Enter a Number: ";
    cin >> N;
    int sum = evenSum(N);
    cout << "Sum of Even Numbers 1 - " << N << " is: " << sum;
    return 0;
}