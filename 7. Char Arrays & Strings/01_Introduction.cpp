#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Entire array can be inputted at once.
    // char ch[100] = "Ishita";
    // cout << ch << endl;
    // cout << ch[0] << ch[1] << endl << endl;

    // Input the characters one-by-one.
    // char name[100];
    // name[0] = 'a';
    // name[1] = 'b';
    // name[2] = 'c';
    // cout << name << endl;
    // cout << name[0] << name[1] << name[2] << endl;

    // At the end of character array, NULL is contained by default, to denote termination.
    // char name[100];
    // cin >> name; // "Ishita" is inputted.
    // for (int i = 0; i < 7; i++)
    //     cout << "Index: " << i << "    Value: " << name[i] << endl;
    // int end_of_array = int(name[6]);
    // cout << "ASCII value of end of array: " << end_of_array << endl; // ASCII value of NULL character is 0.

    // It stops taking input at the first space or tab character.
    char arr[100];
    cin >> arr;  // "Ishita Gupta" inputted.
    cout << arr; // Prints "Ishita" only.

    return 0;
}
