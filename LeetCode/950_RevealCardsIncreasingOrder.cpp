#include <bits/stdc++.h>
using namespace std;

vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    // REVERSE SIMULATION:
    // Start from the sorted deck.
    // Perform given steps on the indices queue.
    // And place the deck elements into the answer vector accordingly.
    // This provides the required order.
    int n = deck.size();
    queue<int> id_queue; // Queue for moving indices as per steps.
    vector<int> ans(n);
    sort(deck.begin(), deck.end());

    for (int i = 0; i < n; i++)
        id_queue.push(i);

    for (int i = 0; i < n; i++)
    {
        // Place deck's top element at the front index.
        ans[id_queue.front()] = deck[i]; // Use front index of queue for placing deck element.
        id_queue.pop();                  // Work of this index is done.

        // Move deck's next top card to the bottom.
        if (!id_queue.empty())
        {
            id_queue.push(id_queue.front());
            id_queue.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> ans;
    ans = deckRevealedIncreasing(deck);
    for (int i : ans)
        cout << i << "  ";
    return 0;
}