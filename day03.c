#include <stdio.h>

int main() {
    int n, k, i;
    int comparisons = 0;
    int found_index = -1;

    // Read array size 'n'
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read key 'k' to search
    scanf("%d", &k);

    // Perform linear search
    for (i = 0; i < n; i++) {
        comparisons++;          // Increment comparison counter
        if (arr[i] == k) {      // Check if current element matches the key
            found_index = i;    // Store the index if found
            break;              // Exit the loop once found
        }
    }

    // Display the result
    if (found_index != -1) {
        printf("Found at index %d\n", found_index);
    } else {
        printf("Not Found\n");
    }

    // Display the total number of comparisons
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
