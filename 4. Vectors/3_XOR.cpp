#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // XOR is a bitwise operator.

    /* XOR Truth Table
       a    b    ^
       0    0    0
       0    1    1
       1    0    1
       1    1    0

        E.g. 5 ^ 5
        5 in binary representation: 101
        So 101
        ^  101
        -------
        000
        -------
        And 000 = 0
        Thus 5 ^ 5 = 0.


        E.g. 2 ^ 3
        2 in binary: 10
        3 in binary: 11
        So 10
        ^  11
        ------
        01
        ------
        And 01 = 1
        Thus, 2 ^ 3 = 1.


        E.g. 1009 ^ 11
        1009 in binary: 1111110001
        11 in binary: 1011
        So 1111110001
        ^        1011
        --------------
           1111111010
        --------------
        And the answer in decimal value is 1018 (2 + 8 + 16 + 32 + 64 + 128 + 256 + 512).

    */
    vector<int> a{1009};
    vector<int> b{11};
    int result = 0;
    for (int i = 0; i < a.size(); i++)
        result = a[i] ^ b[0];
    cout << result;

    return 0;
}