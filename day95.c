#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list buckets
struct Node {
    float data;
    struct Node* next;
};

// Function to sort an array of n real numbers in [0, 1)
void bucketSort(float arr[], int n) {
    // 1. Create n empty buckets
    struct Node** buckets = (struct Node**)malloc(n * sizeof(struct Node*));
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // 2. Put array elements into different buckets
    for (int i = 0; i < n; i++) {
        int idx = n * arr[i]; // Determine bucket index
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = NULL;

        // Insertion sort while inserting into the bucket's linked list
        if (!buckets[idx] || buckets[idx]->data >= arr[i]) {
            newNode->next = buckets[idx];
            buckets[idx] = newNode;
        } else {
            struct Node* current = buckets[idx];
            while (current->next && current->next->data < arr[i]) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // 3. Concatenate all buckets back into the original array
    int j = 0;
    for (int i = 0; i < n; i++) {
        struct Node* node = buckets[i];
        while (node) {
            arr[j++] = node->data;
            struct Node* temp = node;
            node = node->next;
            free(temp); // Free memory
        }
    }
    free(buckets);
}

int main() {
    float arr[] = {0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%f ", arr[i]);
    }
    return 0;
}
