Question 1:Design and Implement a Stack Using an Array 

Aim:-
To design and implement a stack using an array in C language without using any built-in stack library. The program performs PUSH, POP, PEEK, and DISPLAY operations and handles stack overflow and stack underflow conditions.

Theory:-
A stack is a linear data structure that follows the LIFO (Last In, First Out) principle. This means that the element inserted last is removed first.
For example, a stack of books: the book placed on top is removed first.
Basic operations of a stack:-

.PUSH(x): Inserts an element into the stack.

.POP(): Removes the top element from the stack.

.PEEK(): Displays the top element without removing it.

.DISPLAY(): Displays all elements present in the stack.

Stack diagram
Stack (LIFO)

30 — TOP
20
10
POP removes 30 first; PUSH inserts a new element at the top.
 
Algorithm:-
PUSH(x)

Check whether top == MAX - 1.
If true, display Stack Overflow.
Otherwise, increment top and insert the element.
Stop.

POP()

Check whether top == -1.
If true, display Stack Underflow.
Otherwise, display the top element and decrement top.
Stop.

PEEK()

Check whether the stack is empty.
If empty, display an appropriate message.
Otherwise, display stack[top].

DISPLAY()
Check whether the stack is empty.
If not, display all elements from top to index 0.

C program 
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void PUSH(int x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }

    stack[++top] = x;
    printf("%d pushed into stack\n", x);
}

void POP()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }

    printf("Popped element: %d\n", stack[top--]);
}

void PEEK()
{
    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Top element: %d\n", stack[top]);
}

void DISPLAY()
{
    int i;

    if (top == -1)
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements are:\n");

    for (i = top; i >= 0; i--)
    {
        printf("%d\n", stack[i]);
    }
}

int main()
{
    int choice, x;

    do
    {
        printf("\n1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. DISPLAY\n");
        printf("5. EXIT\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &x);
                PUSH(x);
                break;
            case 2:
                POP();
                break;
            case 3:
                PEEK();
                break;
            case 4:
                DISPLAY();
                break;
            case 5:
                printf("Exiting program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

Output 
--- STACK MENU ---
1. PUSH
2. POP
3. PEEK
4. DISPLAY
5. EXIT

Enter your choice: 1
Enter value: 10
10 pushed onto the stack.

Enter your choice: 1
Enter value: 20
20 pushed onto the stack.

Enter your choice: 1
Enter value: 30
30 pushed onto the stack.

Enter your choice: 4
Stack elements are:
30
20
10

Enter your choice: 3
Top element: 30
Enter your choice: 2
Popped element: 30
