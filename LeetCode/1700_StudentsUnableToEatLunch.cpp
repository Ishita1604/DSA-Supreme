#include <bits/stdc++.h>
using namespace std;

int countStudents(vector<int> &students, vector<int> &sandwiches)
{
    int stud_size = students.size();
    int sand_size = sandwiches.size();
    queue<int> stud_queue;
    stack<int> sand_stack;
    int count = 0; // To keep track of students unable to eat.

    for (int i = 0; i < stud_size; i++)
        stud_queue.push(students[i]); // Push the preference into the queue.

    for (int i = sand_size - 1; i >= 0; i--)
        sand_stack.push(sandwiches[i]); // Push the sandwich type into the stack in reverse fashion.

    while (!stud_queue.empty() && count < stud_queue.size())
    {
        if (stud_queue.front() == sand_stack.top())
        {
            // Student got the sandwich he wanted at the top.
            count = 0; // Reset count to zero.
            stud_queue.pop();
            sand_stack.pop();
        }
        else
        {
            // Student didn't get his preferred sandwich, so move him to the end of the queue.
            count++;
            int move_at_end = stud_queue.front();
            stud_queue.pop();
            stud_queue.push(move_at_end);
            if (count == stud_queue.size()) // All students have been moved to the end of the queue, and preference doesn't match.
                break;
        }
    }
    return count;
}

int main()
{
    vector<int> students = {1, 1, 1, 0, 0, 1};
    vector<int> sandwiches = {1, 0, 0, 0, 1, 1};
    int ans = countStudents(students, sandwiches);
    cout << ans;
    return 0;
}