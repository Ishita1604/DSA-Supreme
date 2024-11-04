#include <iostream>
using namespace std;

int main()
{
    system("cls");
    int n, i;
    cout << "Enter a Number: ";
    cin >> n;

    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            cout << "Not prime" << endl;
            break;
        }
    }
    if (i == n)
        cout << "Prime" << endl;

    return 0;
}

/* Approach 2. */

// #include <iostream>
// using namespace std;

// int main()
// {
//     system("cls");
//     int num;
//     bool isPrime = false;
//     cin >> num;

//     if (num == 1)
//     {
//         cout << num << " is neither Prime nor Not Prime";
//         abort();
//     }
//     if (num == 2)
//         isPrime = true;

//     for (int i = 2; i < num; i++)
//     {
//         if (num % 2 == 0)
//             break;
//         else
//             isPrime = true;
//     }

//     if (isPrime == true)
//         cout << "Prime";
//     else
//         cout << "Not Prime";

//     return 0;
// }
