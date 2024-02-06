#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> answer;
        set<int> st; // Using the set data structure to avoid the duplicates.
        int i, j, k;
        i = j = k = 0;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] == B[j] && B[j] == C[k])
            {
                st.insert(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
                i++;
            else if (B[j] < C[k])
                j++;
            else // Means that C[k] is the smallest.
                k++;
        }

        for (auto i : st) // For-each loop used.
            answer.push_back(i);

        return answer;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
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
    }
}