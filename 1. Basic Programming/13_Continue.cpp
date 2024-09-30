// Jump statements in Loops.
// 1. "continue"
// Skip current iteration and move to next iteration of loop.
// Code after "continue" is not executed.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    for (int i = 1; i <= 30; i++)
    {
        if (i % 2 == 0)
            cout << i << " Go out today!" << endl;
        else
        {
            continue; // Iteration skipped.
            cout << "Not printed!";
        }
        cout << "Printed" << endl;
    }

    return 0;
}