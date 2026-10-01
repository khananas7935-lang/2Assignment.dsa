Q2. Implement a Circular Queue using an Array

1. Theory

A Circular Queue is a linear data structure that follows the FIFO (First In, First Out) principle. In a circular queue, the last position is connected to the first position, allowing the reuse of empty spaces.

It supports four main operations: ENQUEUE, DEQUEUE, FRONT and DISPLAY.

2. Logic and Operations

1. ENQUEUE(x)

Checks whether the queue is full.

If full, displays Queue Overflow.

If empty, sets FRONT = REAR = 0.

Otherwise, updates REAR = (REAR + 1) % SIZE.

Inserts the new element at REAR.

2. DEQUEUE()

Checks whether the queue is empty.

If empty, displays Queue Underflow.

If only one element exists, resets FRONT = REAR = -1.

Otherwise, updates FRONT = (FRONT + 1) % SIZE.

3. FRONT()

Checks whether the queue is empty.

If not empty, displays the element at queue[FRONT] without deleting it.

4. DISPLAY()

Checks whether the queue is empty.

Starts from FRONT and prints elements until REAR is reached.

Uses the modulo operator to move circularly through the array.

3. C++ Program
    ```cpp
#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int q[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if ((rear + 1) % SIZE == front) {
            cout << "Queue Full\n";
            return;
        }

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % SIZE;

        q[rear] = x;
        cout << x << " inserted\n";
    }

    void dequeue() {
        if (front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        cout << q[front] << " deleted\n";

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % SIZE;
    }

    void showFront() {
        if (front == -1)
            cout << "Queue Empty\n";
        else
            cout << "Front: " << q[front] << endl;
    }

    void display() {
        if (front == -1) {
            cout << "Queue Empty\n";
            return;
        }

        int i = front;
        cout << "Queue: ";

        while (true) {
            cout << q[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int ch, x;

    do {
        cout << "\n1.Enqueue  2.Dequeue";
        cout << "\n3.Front  4.Display  5.Exit";
        cout << "\nEnter choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                cq.enqueue(x);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.showFront();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                cout << "Exit\n";
                break;
            default:
                cout << "Invalid choice\n";
        }
    } while (ch != 5);

    return 0;
}
```
4. Important Logic

Condition

	

Purpose




front == -1

	

Checks whether the queue is empty.




(rear + 1) % SIZE == front

	

Checks whether the queue is full.




(rear + 1) % SIZE

	

Moves REAR to the next circular position.




(front + 1) % SIZE

	

Moves FRONT to the next position.




front = rear = -1

	

Resets the queue when it becomes empty.

The modulo (%) operator brings the index back to 0 after it reaches the last array position.
