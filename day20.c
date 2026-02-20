#include <stdio.h>
#include <stdlib.h>

// A simple structure for the hash map
struct HashEntry {
    int key;
    int value; // count of occurrences
    struct HashEntry *next;
};

// Simple hash function (modulo size)
int hash(int key, int size) {
    // Use the absolute value to handle negative keys
    return abs(key) % size;
}

// Function to insert/update an entry in the hash map
void insert(struct HashEntry **map, int size, int key) {
    int index = hash(key, size);
    struct HashEntry *current = map[index];
    while (current != NULL) {
        if (current->key == key) {
            current->value++;
            return;
        }
        current = current->next;
    }
    // If not found, create new entry and add to front of list
    struct HashEntry *newEntry = (struct HashEntry *)malloc(sizeof(struct HashEntry));
    newEntry->key = key;
    newEntry->value = 1;
    newEntry->next = map[index];
    map[index] = newEntry;
}

// Function to get the count of a key from the hash map
int get_count(struct HashEntry **map, int size, int key) {
    int index = hash(key, size);
    struct HashEntry *current = map[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return 0; // Key not found
}

// Function to count subarrays with zero sum
long long countSubarraysWithZeroSum(int arr[], int n) {
    // The hash map stores (cumulative_sum, frequency)
    // We use a reasonably large size for the hash table to minimize collisions
    int HASH_SIZE = 2 * n; 
    struct HashEntry **map = (struct HashEntry **)calloc(HASH_SIZE, sizeof(struct HashEntry *));

    long long count = 0;
    int current_sum = 0;

    // Insert the initial sum of 0 with a frequency of 1
    insert(map, HASH_SIZE, 0);

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];

        // If the current sum is already in the hash map, 
        // it means we found subarrays with sum zero
        if (get_count(map, HASH_SIZE, current_sum) > 0) {
            count += get_count(map, HASH_SIZE, current_sum);
        }
        
        // Insert or update the current sum's frequency in the hash map
        insert(map, HASH_SIZE, current_sum);
    }

    // Free the allocated memory (important for C programming)
    for (int i = 0; i < HASH_SIZE; i++) {
        struct HashEntry *current = map[i];
        while (current != NULL) {
            struct HashEntry *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(map);

    return count;
}

int main() {
    int n;
    // Read the number of elements
    if (scanf("%d", &n) != 1) return 1;

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) return 1;

    // Read the array elements
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            free(arr);
            return 1;
        }
    }

    // Call the function and print the result
    long long result = countSubarraysWithZeroSum(arr, n);
    printf("%lld\n", result);

    free(arr);
    return 0;
}
