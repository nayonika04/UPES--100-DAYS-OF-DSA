#include <stdio.h>
#include <stdlib.h>

// Define the node structure for the circular linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Dynamically allocate memory
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL; // Initially set to NULL, will be linked later
    return newNode;
}

// Function to insert a node at the end and maintain circularity
struct Node* insertEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
        newNode->next = head; // In a single-node circular list, it points to itself
    } else {
        struct Node* temp = head;
        // Traverse to the last node
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode; // Link the old last node to the new node
        newNode->next = head; // Link the new node to the head to maintain circularity
    }
    return head;
}

// Function to traverse and print the circular linked list
void traverseAndPrint(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty\n");
        return;
    }
    struct Node* temp = head;
    // Use a do-while loop to ensure all elements are printed exactly once, starting from head
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head); // Stop when the pointer returns to the head
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int n, data, i;

    // Input the number of nodes
    printf("Input the number of nodes: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input for number of nodes.\n");
        return 1;
    }

    // Input the elements and build the list
    for (i = 0; i < n; i++) {
        printf("Enter the data values to be placed in node %d: ", i + 1);
        if (scanf("%d", &data) != 1) {
            printf("Invalid input for data.\n");
            return 1;
        }
        head = insertEnd(head, data);
    }

    // Print the circular linked list
    printf("Output: ");
    traverseAndPrint(head);

    // Memory deallocation (optional but good practice)
    if (head != NULL) {
        struct Node *current = head;
        struct Node *next_node;
        while (current->next != head) {
            next_node = current->next;
            free(current);
            current = next_node;
        }
        free(current); // Free the last (head) node
    }


    return 0;
}
