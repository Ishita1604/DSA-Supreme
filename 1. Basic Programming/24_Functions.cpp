#include <iostream>
using namespace std;


// Why functions are needed?
// 1. Prevent bulky code.
// 2. Run same code multiple times, while writing it only once.


// Student Grade Problem using Switch Case.


char tellMyGrade(int marks)
{
    switch (marks / 10)
    {
    case 9:
        return 'A';
        break;
    case 8:
        return 'B';
        break;
    case 7:
        return 'C';
        break;
    case 6:
        return 'D';
        break;
    case 5:
        return 'E';
        break;

    default:
        return 'F';
        break;
    }
}

int main()
{
    int marks;
    cout << "Enter your Marks: ";
    cin >> marks;
    char grade = tellMyGrade(marks);
    cout << "You secured " << grade << " grade!";
    return 0;
}