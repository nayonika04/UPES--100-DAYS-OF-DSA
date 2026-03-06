#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer for the stack
struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamic memory allocation
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        exit(1);
    }
    struct Node* temp = top;
    int data = temp->data;
    top = top->next;
    free(temp); // Free memory of the popped node
    return data;
}

// Function to perform the arithmetic operation
int performOperation(char op, int op1, int op2) {
    switch (op) {
        case '+': return op1 + op2;
        case '-': return op1 - op2;
        case '*': return op1 * op2;
        case '/': return op1 / op2;
        default: return 0;
    }
}

// Function to evaluate the postfix expression
int evaluatePostfix(char* exp) {
    int i;
    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); // Convert char to int and push to stack
        } else if (exp[i] == ' ' || exp[i] == '\t') {
            continue; // Skip spaces and tabs
        } else {
            // Operator encountered, pop two operands
            int op2 = pop(); // Second operand popped first
            int op1 = pop(); // First operand popped second
            int result = performOperation(exp[i], op1, op2);
            push(result); // Push result back to stack
        }
    }
    return pop(); // The final result is the last element in the stack
}

int main() {
    char exp[] = "2 3 1 * + 9 -"; // Example input
    // Note: for multi-digit numbers, input parsing should use strtok or similar to handle spaces properly. This example assumes single digits or space-separated tokens.
    
    int result = evaluatePostfix(exp);
    printf("Output: \"%d\"\n", result);

    return 0;
}
