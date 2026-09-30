#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((rear + 1) % MAX == front)
        printf("Queue is Full\n");
    else {
        if (front == -1)
            front = 0;

        rear = (rear + 1) % MAX;
        queue[rear] = x;

        printf("%d inserted\n", x);
    }
}

void dequeue() {
    if (front == -1)
        printf("Queue is Empty\n");
    else {
        printf("%d deleted\n", queue[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void frontElement() {
    if (front == -1)
        printf("Queue is Empty\n");
    else
        printf("Front = %d\n", queue[front]);
}

void display() {
    if (front == -1) {
        printf("Queue is Empty\n");
        return;
    }

    printf("Queue: ");

    int i = front;
    while (1) {
        printf("%d ", queue[i]);

        if (i == rear)
            break;

        i = (i + 1) % MAX;
    }

    printf("\n");
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);

    display();
    frontElement();

    dequeue();
    dequeue();

    enqueue(50);
    enqueue(60);

    display();

    return 0;
}
