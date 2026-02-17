#include <stdio.h>

void reverseArray(int arr[], int start, int end) {
    int temp;
    while (start < end) {
        // Swap elements at start and end
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        // Move pointers inward
        start++;
        end--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Read the number of elements
    // printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1) {
        return 1; // handle error
    }

    int arr[n]; // Declaring a variable size array (C99 feature)

    // Read the array elements
    // printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 1; // handle error
        }
    }

    // Call the reverse function
    reverseArray(arr, 0, n - 1);

    // Print the reversed array
    printArray(arr, n);

    return 0;
}
