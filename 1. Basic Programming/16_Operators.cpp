// Operators in C++:

/*
1. Arithmetic
    a) Binary + - * / %                               (2 operands)
    b) Unary  ++ -- Increment Decrement, Pre Post     (1 operand)

2. Relational    >, <, ==, <=, >=, !=                                         - Defines relation between two operands, returns a boolean value.
3. Assignment    =, +=, -+, *=, /=, %=
4. Logical       && (AND), || (OR), ! (NOT)                                   - Connect multiple conditions/expressions together or reverse value.
5. Bitwise       & (AND), | (OR), ~ (NOT/1's complement), ^ (XOR), >>, <<     - Perform bit-by-bit operations.
 

Pre  : 1st increment then assign (Current statement gets updated value) / Instantly updated.
Post : 1st assign then increment (Next statement gets updated value) / Temporarily stored & incremented when next statement is executed.

*/



// #include <iostream>

// using namespace std;

// int main()
// {
//     int i = 1;
//     int j = 2;
//     int k;
//     k = i + j + ++i + i++ - j++ + ++j + --i - --j;
//     //  1   2     2   2     2       4     2     3

//     cout << i << endl; // 2
//     cout << j << endl; // 3
//     cout << k << endl; // 8

//     return 0;
// }






// #include <iostream>

// using namespace std;

// int main()
// {
//     int a = 10;
//     int b = a++;

//     cout << a << endl;
//     cout << b << endl;

//     return 0;
// }






// #include <iostream>

// using namespace std;

// int main()
// {
//     int a = 10;
//     int b = ++a;

//     cout << a << endl;
//     cout << b << endl;

//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main()
// {
//     int a = 12;
//     cout << a++ << endl;
//     cout << a;

//     return 0;
// }




#include <iostream>
using namespace std;

int main()
{
    int a = 5;
    // Compiler dependent.
    cout << (++a) * (++a) << endl;

    return 0;
}
