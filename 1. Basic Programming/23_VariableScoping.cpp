// Global variable: Accessible anywhere in program. It is bad practice due to lack of encapsulation.
// Local variable: Accessible  within a specific scope like loop/function. Good as frees memory when no longer needed.

#include <iostream>
using namespace std;


int globalCounter = 0; // Global variable.

void incrementGlobal()
{
    globalCounter++; // Modifies global variable.
}

void displayLocal()
{
    int localCounter = 0; // Local variable.
    localCounter++; // Modifies local variable.
    cout << "Local Counter: " << localCounter << endl;
}

int main()
{
    incrementGlobal();
    cout << "Global Counter after increment: " << globalCounter << endl;
    displayLocal();
    displayLocal(); // Resets localCounter on each call.
    
    return 0;
}
