#include <stdio.h>
#include <string.h>

#define MAX 1000

int pq[MAX];
int size = 0;

// Function to find the index of the highest priority element (smallest value)
int find_highest_priority_index() {
    if (size == 0) return -1;
    int min_idx = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

void insert(int x) {
    if (size < MAX) {
        pq[size++] = x;
    }
}

void delete_op() {
    int idx = find_highest_priority_index();
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[idx]);
        // Shift elements to the left to fill the gap
        for (int i = idx; i < size - 1; i++) {
            pq[i] = pq[i + 1];
        }
        size--;
    }
}

void peek() {
    int idx = find_highest_priority_index();
    if (idx == -1) {
        printf("-1\n");
    } else {
        printf("%d\n", pq[idx]);
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    char op[10];
    for (int i = 0; i < n; i++) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            int x;
            scanf("%d", &x);
            insert(x);
        } else if (strcmp(op, "delete") == 0) {
            delete_op();
        } else if (strcmp(op, "peek") == 0) {
            peek();
        }
    }

    return 0;
}
