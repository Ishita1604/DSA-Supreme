/** Given three arrays sorted in increasing order.
    Find the elements that are common in all three arrays.
    Solve WITHOUT using any additional Data Structure.
    TIME: O(n1 + n2 + n3)
**/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Without using additional Data Structure.
    // We will drop the duplicates in each array.

    int *removeDuplicate(int arr[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr[i + 1]) // Duplicate exists.
            {
                int dupl = arr[i];
                int dupl_index = i;
                while (dupl_index < n) // Shifting.
                {
                    arr[dupl_index] = arr[dupl_index + 1];
                    dupl_index++;
                }
                n = n - 1; // Reduce the size.
                i--;
            }
        }
        return arr;
    }

    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        removeDuplicate(A, n1);
        removeDuplicate(B, n2);
        removeDuplicate(C, n3);

        vector<int> answer;
        int i, j, k;
        i = j = k = 0;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                answer.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
                i++;
            else if (B[j] < C[k])
                j++;
            else
                k++;
        }
        return answer;
    }
};

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3; // Input size of each array.
    int A[n1];
    int B[n2];
    int C[n3];

    // Input the elements:
    for (int i = 0; i < n1; i++)
        cin >> A[i];
    for (int i = 0; i < n2; i++)
        cin >> B[i];
    for (int i = 0; i < n3; i++)
        cin >> C[i];

    Solution ob;

    vector<int> res = ob.commonElements(A, B, C, n1, n2, n3);

    if (res.size() == 0)
        cout << -1;

    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    cout << endl;

    return 0;
}