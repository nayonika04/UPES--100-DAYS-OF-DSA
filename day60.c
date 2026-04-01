#include <stdio.h>
#include <stdbool.h>

// Function to check if the array represents a Min-Heap
bool isMinHeap(int arr[], int n) {
    // Only internal nodes need to be checked as leaves have no children
    for (int i = 0; i <= (n - 2) / 2; i++) {
        // Check if left child exists and violates Min-Heap property
        if (2 * i + 1 < n && arr[i] > arr[2 * i + 1]) {
            return false;
        }
        // Check if right child exists and violates Min-Heap property
        if (2 * i + 2 < n && arr[i] > arr[2 * i + 2]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    // Input number of nodes
    if (scanf("%d", &n) != 1) return 0;

    int arr[n];
    // Input level-order traversal
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Output YES if it's a valid Min-Heap, otherwise NO
    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
