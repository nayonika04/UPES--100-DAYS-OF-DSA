#include <stdio.h>

int main() {
    int n, i, j, count;
    
    // 1. Input the size of the array
    printf("Input the number of elements to be stored in the array: ");
    scanf("%d", &n);
    
    // Declare array and a 'visited' array (use a large enough size or dynamic allocation)
    int arr[n];
    int visited[n]; 

    // 2. Input the elements of the array
    printf("Input %d elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", &arr[i]);
        visited[i] = 0; // Initialize all elements as unvisited
    }

    // 3. Count the frequency of each element
    for (i = 0; i < n; i++) {
        // Skip if the element has already been visited/processed
        if (visited[i] == 1) {
            continue;
        }

        count = 1; // Initialize count for the current element
        
        // Check for duplicates in the rest of the array
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1; // Mark the duplicate as visited
            }
        }
        
        // 4. Print the frequency in the specified format
        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
