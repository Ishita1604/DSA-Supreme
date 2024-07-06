#include <bits/stdc++.h>
using namespace std;

int passThePillow(int n, int time)
{
    int full_round = time / (n - 1);       // To find the direction of passing.
    int remaining_passes = time % (n - 1); // To find the final position of pillow.
    if (full_round % 2 == 0)               // Forward direction.
        return remaining_passes + 1;       // Because of 1-based indexing, 1 is added.
    else                                   // Backward direction.
        return (n - remaining_passes);
}

int main()
{
    int n = 5;
    int time = 9;
    int ans = passThePillow(n, time);
    cout << "After " << time << " passes, the pillow has reached at position " << ans << endl;

    return 0;
}
