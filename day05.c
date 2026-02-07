/*A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, q;

    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    int i = 0, j = 0;
    
    while (i < p && j < q) {
        if (log1[i] < log2[j]) {
            printf("%d ", log1[i++]);
        } else {
            printf("%d ", log2[j++]);
        }
    }

    while (i < p) printf("%d ", log1[i++]);
    while (j < q) printf("%d ", log2[j++]);

    printf("\n");
    return 0;
}

