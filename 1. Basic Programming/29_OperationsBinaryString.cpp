#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

/* __________________________________________________________________________________________
---- Asked in Accenture OnCampus 10 Aug 2022, Slot 2 ----

Problem Description:
The Binary number system only uses two digits, 0 and 1 and number system can be called binary string.
You are required to implement the function:

int OperationsBinaryString(char* str);

The function accepts a string str as its argument. The string str consists of binary digits eparated with an alphabet as follows:
    – A denotes AND operation.
    – B denotes OR operation.
    – C denotes XOR Operation.
You are required to calculate the result of the string str, scanning the string to right taking one opearation at a time, and return the same.

Note:
    - No order of priorities of operations is required.
    - Length of str is odd.
    - If str is NULL or None (in case of Python), return -1.


Input:
str: 1C0C1C1A0B1
Output:1

Explanation:
The alphabets in str when expanded becomes “1 XOR 0 XOR 1 XOR 1 AND 0 OR 1”, result of the expression becomes 1, hence 1 is returned.

Input:
0C1A1B1C1C1B0A0
Output:0

_____________________________________________________________________________________________
*/



int OperationsBinaryString(char *str)
{
    int n = strlen(str);
    if (n == 0) return -1;
    stack<char> st;
    for (int i = n - 1; i >= 0; i++)
    {
        st.push(str[i]);
    }
    while (st.size() != 1)
    {
        char first = st.top();
        int first_int = first - '0'; // To convert char to int datatype.
        st.pop();
        char op = st.top();
        st.pop();
        char sec = st.top();
        int sec_int = sec - '0';
        st.pop();
        if (op == 'A')
        {
            int res = first_int & sec_int;
            char res_char = res + '0';
            st.push(res_char);
        }
        else if (op == 'B')
        {
            int res = first_int | sec_int;
            char res_char = res + '0';
            st.push(res_char);
        }
        else
        {
            int res = first_int ^ sec_int;
            char res_char = res + '0';
            st.push(res_char);
        }
    }
    char ans = st.top();
    return ans - '0';
}

int main()
{
    char str[] = "1C0C1C1A0B1";
    int ans = OperationsBinaryString(str);
    cout << ans;
}