#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front; // Pointer to the front of the queue.
    Node *rear;  // Pointer to the rear of the queue.

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
    }

    // Function to check if the queue is empty.
    bool isEmpty()
    {
        return front == nullptr;
    }

    // Function to add an element to the queue.
    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            front = rear = newNode; // If queue is empty, both front and rear point to new node.
        }
        else
        {
            rear->next = newNode; // Link the new node at the end of the queue.
            rear = newNode;       // Update rear to point to the new node.
        }
        cout << value << " enqueued to queue\n";
    }

    // Function to remove an element from the queue.
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1; // Return -1 if the queue is empty.
        }

        int value = front->data; // Get the front value.
        Node *temp = front;      // Temporary pointer to the front node.
        front = front->next;     // Move front to the next node.
        delete temp;             // Delete the old front node.

        if (front == nullptr)
        {
            rear = nullptr; // If the queue becomes empty, update rear.
        }

        cout << value << " dequeued from queue\n";
        return value;
    }

    // Function to get the front element of the queue.
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1; // Return -1 if the queue is empty.
        }
        return front->data; // Return the front value.
    }

    // Function to display the queue.
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = front;
        cout << "Queue: ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    cout << "Front element is: " << q.peek() << endl;

    return 0;
}
