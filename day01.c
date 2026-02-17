#include <stdio.h>

int main() {
    int n, pos, i;

    // Read the number of elements
    scanf("%d", &n);

    int arr[n];

    // Read the n elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read the 1-based position to delete
    scanf("%d", &pos);

    // Validate the position
    if (pos < 1 || pos > n) {
        printf("Invalid position\n");
        return 1;
    }

    // Shift elements to the left starting from the deletion position
    // The loop runs from the 1-based 'pos' to 'n-1' (the second-to-last original index)
    // and copies the element from the next position into the current one.
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Print the updated array with n-1 elements
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
