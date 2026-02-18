#include <stdio.h>

void rotateRight(int arr[], int n, int k) {
    // Normalize k in case it is greater than n
    k = k % n;

    if (k == 0) {
        return; // No rotation needed
    }

    // Create a temporary array to store the last k elements
    int temp[k];
    for (int i = 0; i < k; i++) {
        temp[i] = arr[n - k + i];
    }

    // Shift the remaining n-k elements to the right by k positions
    for (int i = n - k - 1; i >= 0; i--) {
        arr[i + k] = arr[i];
    }

    // Copy the stored elements from the temporary array to the beginning of the original array
    for (int i = 0; i < k; i++) {
        arr[i] = temp[i];
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n, k;

    // Read the size of the array
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];

    // Read the n integers
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Read the number of rotations
    if (scanf("%d", &k) != 1) return 1;

    // Rotate the array
    rotateRight(arr, n, k);

    // Print the rotated array
    printArray(arr, n);

    return 0;
}
