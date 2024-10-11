// Jump statements in Loops.
// 2. "break" statement.
// Used to terminate the loop.

#include <iostream>
#include <string>

using namespace std;

int main()
{
    int pocketMoney = 3000;
    for (int i = 1; i <= 30; i++)
    {
        if (pocketMoney == 0) break;
        if (i % 2 == 0)
        {
            cout << i << " Go out today!" << endl;
            pocketMoney = pocketMoney - 300;
        }
        else continue;
    }
    return 0;
}