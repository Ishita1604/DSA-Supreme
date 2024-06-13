#include <bits/stdc++.h>
using namespace std;

// 1. Sort both the vectors.
// 2. Greedy matching: Smallest positioned student goes to the smallest positioned seat.
// 3. Keep adding the total moves.
int minMovesToSeat(vector<int> &seats, vector<int> &students)
{
    int n = seats.size();
    sort(seats.begin(), seats.end());
    sort(students.begin(), students.end());
    int i = 0;
    int j = 0;
    int moves = 0;
    while (i < n && j < n)
    {
        moves += abs(seats[i] - students[j]);
        i++;
        j++;
    }
    return moves;
}

int main()
{
    vector<int> seats = {2, 2, 6, 6};
    vector<int> students = {1, 3, 2, 6};
    int moves = minMovesToSeat(seats, students);
    cout << "Total moves used: " << moves << endl;

    return 0;
}