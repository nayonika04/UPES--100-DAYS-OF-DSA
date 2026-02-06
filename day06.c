#include <stdio.h>

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    int arr[n];
    // Read the elements of the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Handle the case of an empty array
    if (n == 0) {
        printf("\n");
        return 0;
    }

    // Print the first element, it is always unique in the context of the first run
    printf("%d", arr[0]);

    // Iterate through the rest of the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Check if the current element is different from the previous one
        if (arr[i] != arr[i - 1]) {
            // If it is different, it's a new unique element. Print it with a space.
            printf(" %d", arr[i]);
        }
    }

    // Print a newline at the end of the output
    printf("\n");

    return 0;
}
