#include <stdio.h>
#include <stdlib.h>
#include <math.h> // For the pow function (optional, can be done manually)

// Define the structure for a polynomial term (node)
typedef struct Node {
    int coefficient;
    int exponent;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int coeff, int exp) {
    Node* newNode = (Node*)malloc(sizeof(Node)); // Dynamic memory allocation
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a term into the polynomial linked list while maintaining descending order of exponents
Node* insertTerm(Node* head, int coeff, int exp) {
    if (coeff == 0) return head; // Don't add terms with zero coefficient

    Node* newNode = createNode(coeff, exp);
    Node* current;

    // Case 1: If the list is empty or the new node has a higher exponent than the head
    if (head == NULL || newNode->exponent > head->exponent) {
        newNode->next = head;
        head = newNode;
    } else {
        // Traverse to find the correct insertion position
        current = head;
        while (current->next != NULL && current->next->exponent >= newNode->exponent) {
            // If a term with the same exponent exists, add coefficients
            if (current->next->exponent == newNode->exponent) {
                current->next->coefficient += newNode->coefficient;
                free(newNode); // Free the new node as it's no longer needed
                return head;
            }
            current = current->next;
        }

        // Insert the new node
        newNode->next = current->next;
        current->next = newNode;
    }
    return head;
}

// Function to read the polynomial terms from the user
Node* readPolynomial() {
    Node* head = NULL;
    int n, coeff, exp;

    printf("Enter the number of terms: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of terms. Exiting.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient and exponent for term %d (e.g., 10 4): ", i + 1);
        if (scanf("%d %d", &coeff, &exp) != 2) {
            printf("Invalid input. Exiting.\n");
            exit(1);
        }
        head = insertTerm(head, coeff, exp);
    }
    return head;
}

// Function to print the polynomial in standard form
void printPolynomial(Node* head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        if (current->coefficient != 0) {
            // Print coefficient and variable (if exponent > 0)
            printf("%d", current->coefficient);
            if (current->exponent > 0) {
                printf("x");
                if (current->exponent > 1) {
                    printf("^%d", current->exponent);
                }
            }

            // Add '+' sign if there are more terms with non-zero coefficients
            if (current->next != NULL && current->next->coefficient != 0) {
                 printf(" + ");
            }
        }
        current = current->next;
    }
    printf("\n");
}

// Main function to drive the program
int main() {
    Node* polynomial = NULL;

    printf("--- Polynomial Creator ---\n");
    polynomial = readPolynomial();

    printf("Output: ");
    printPolynomial(polynomial);

    // Free the allocated memory (optional for a simple program, good practice)
    Node* temp;
    while (polynomial != NULL) {
        temp = polynomial;
        polynomial = polynomial->next;
        free(temp);
    }

    return 0;
}
