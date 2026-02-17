#include <stdio.h>

int main() {
    int n, pos, i;

    // Input the number of elements
    if (scanf("%d", &n) != 1) return 1;
    int arr[n];

    // Input the n elements
    for (i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Input the 1-based position to delete
    if (scanf("%d", &pos) != 1) return 1;

    // Validate the position
    if (pos < 1 || pos > n) {
        // Optional: print an error or handle invalid input
        return 1;
    }

    // Shift elements to the left
    // The element at pos-1 is overwritten by the element at pos, and so on.
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Decrement the size of the array effectively
    n--;

    // Print the updated array
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}

