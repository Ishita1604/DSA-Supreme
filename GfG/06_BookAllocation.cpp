/**** Allocate Minimum Number of Pages [HARD LEVEL] ****/

#include <bits/stdc++.h>
using namespace std;

// You have N books, each with A[i] number of pages.
// M students need to be allocated contiguous books, each getting at least one book.
// The objective is to minimize the maximum sum of pages allocated to any student.
// Return -1 if a valid assignment is impossible, ensuring contiguous allotment.

// APPROACH:
// Binary Search is applied in a defined search space as we have to minimize the maximum number of pages.
// Time: O(N*logS) where S is the sum of number of pages of all the books.

bool isPossibleSolution(int A[], int N, int M, int sol) // Function to check if allocation permutation is possible or not.
{
    int pageSum = 0; // Sum of pages that have been allocated.
    int c = 1;       // Counter to keep track of number of students allocated with pages.
    for (int i = 0; i < N; i++)
    {
        if (A[i] > sol) // As at-most `sol` as known as `mid` number of pages must be allocated to students.
            return false;
        if (pageSum + A[i] > sol)
        {
            // Then allocate rest pages to the next person.
            c++;
            pageSum = A[i];
            if (c > M) // If counter exceeds the number of students, then allocation is not possible.
                return false;
        }
        else
            pageSum += A[i]; // Current person can be allocated more.
    }
    return true;
}


int findPages(int A[], int N, int M) // Function to find minimum number of pages.
{
    int s = 0;
    int e = accumulate(A, A + N, 0); // Function used to sum up array elements, start to end, initialized by 0.
    int ans = -1;

    if (M > N)
        return -1; // Allocation not possible.

    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossibleSolution(A, N, M, mid))
        {
            // Store and try to miminimise the number of pages.
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
            // If for a value of mid, we can't allocate, then allocation still not possible if mid further reduces.
            // Thus, increase value of mid by going towards the right, as array is monotonically increasing.
        }
    }
    return ans;
}


int main()
{
    int N = 4, M = 2;
    int A[N] = {12, 34, 67, 90};
    cout << findPages(A, N, M) << endl;

    return 0;
}