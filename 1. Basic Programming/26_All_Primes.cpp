#include <iostream>
using namespace std;

// Check if Number from 1 to N is/are Prime or Not Prime.


int prime(int N)
{
    if (N == 1) return -1;
    if (N == 2) return 0;
    int flag = 0;
    for (int i = 2; i < N - 1; i++)
    {
        if (N % i == 0)
            flag = 1;
    }
    return flag;
}


int main()
{
    int N;
    cout << "Enter a Number: ";
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int flag = prime(i);
        if (flag == 0)
            cout << i << " is Prime" << endl;
        else if (flag == -1)
            cout << i << " is a Unique Number" << endl;
        else
            cout << i << " is Not Prime" << endl;
    }
    return 0;
}