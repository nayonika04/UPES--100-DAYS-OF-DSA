#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    struct ListNode *next;
};

/**
 * Rotates the linked list to the right by k places.
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0) {
        return head;
    }

    // 1. Find the length of the list and the last node
    struct ListNode* current = head;
    int length = 1;
    while (current->next != NULL) {
        current = current->next;
        length++;
    }
    struct ListNode* lastNode = current;

    // 2. Connect the last node to the head to form a circular list
    lastNode->next = head;

    // 3. Handle cases where k is greater than length by taking modulo
    k = k % length;

    // 4. Find the new tail: position (length - k - 1) from the original head
    int newTailPosition = length - k - 1;
    current = head;
    for (int i = 0; i < newTailPosition; i++) {
        current = current->next;
    }
    struct ListNode* newTail = current;

    // 5. The new head is the node after the new tail
    struct ListNode* newHead = newTail->next;

    // 6. Break the circle by setting the new tail's next to NULL
    newTail->next = NULL;

    return newHead;
}

/**
 * Creates a new node with dynamic memory allocation.
 */
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    if (!newNode) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

/**
 * Prints the linked list elements.
 */
void printList(struct ListNode* head) {
    struct ListNode* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

/**
 * Frees the memory allocated for the linked list.
 */
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    int n, k, val;
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    // Read n (number of elements)
    if (scanf("%d", &n) != 1) return 1;

    // Read n elements and build the list
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        struct ListNode* newNode = createNode(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Read k (number of rotations)
    if (scanf("%d", &k) != 1) return 1;

    // Rotate the list
    head = rotateRight(head, k);

    // Print the rotated list
    printList(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
