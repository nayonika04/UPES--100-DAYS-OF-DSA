#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100 // Maximum size of the stack

int stack[MAX_SIZE];
int top = -1; // Initialize top to -1 to indicate an empty stack

// Function to push an element onto the stack
void push(int value) {
    if (top == MAX_SIZE - 1) {
        // In a real program, you might handle this more gracefully, but for this problem, we follow the input/output rules
        // The problem doesn't specify an output for overflow, so we just return.
    } else {
        top++;
        stack[top] = value;
    }
}

// Function to pop an element from the stack
void pop() {
    if (top == -1) {
        printf("Stack Underflow\n"); // Print 'Stack Underflow' for an empty stack
    } else {
        int popped_value = stack[top];
        top--;
        printf("%d\n", popped_value); // Print the popped element
    }
}

// Function to display the elements of the stack from top to bottom
void display() {
    if (top == -1) {
        // The problem example doesn't show any output for an empty stack display, so we do nothing.
    } else {
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, operation_type, value;

    // Read the number of operations
    if (scanf("%d", &n) != 1) return 1;

    for (int i = 0; i < n; i++) {
        // Read the operation type
        if (scanf("%d", &operation_type) != 1) return 1;

        switch (operation_type) {
            case 1: // Push operation
                if (scanf("%d", &value) != 1) return 1;
                push(value);
                break;
            case 2: // Pop operation
                pop();
                break;
            case 3: // Display operation
                display();
                break;
            default:
                // Handle invalid operation type if necessary
                break;
        }
    }

    return 0;
}
