#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Define the maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Initialize top to -1 to indicate an empty stack

// Function to check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
int isFull() {
    return top == MAX_SIZE - 1;
}

// Function to push an element onto the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push element %d.\\n", value);
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! No element to pop.\\n");
        return -1; // Return a sentinel value for error
    } else {
        int popped_element = stack[top];
        top--;
        return popped_element;
    }
}

// Function to display stack elements from top to bottom
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\\n");
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("IN C PROGRAM\\n"); // Match the specific output format
    }
}

int main() {
    int n, m, value;

    // Input the number of elements to push (n)
    scanf("%d", &n);

    // Input n integers to push
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        push(value);
    }

    // Input the number of pops (m)
    scanf("%d", &m);

    // Perform m pop operations
    for (int i = 0; i < m; i++) {
        pop();
    }

    // Print the remaining stack elements from top to bottom
    display();

    return 0;
}
