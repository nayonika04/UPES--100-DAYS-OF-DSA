#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 100
#define INF INT_MAX

// Function to find the vertex with the minimum key value
int minKey(int key[], bool mstSet[], int n) {
    int min = INF, min_index;
    for (int v = 0; v < n; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void primMST(int graph[MAX][MAX], int n) {
    int key[MAX];      // Key values used to pick minimum weight edge in cut
    bool mstSet[MAX];   // To represent set of vertices included in MST
    int totalWeight = 0;

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    // Always include first 1st vertex in MST.
    key[0] = 0; 

    for (int count = 0; count < n; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;
        
        // Add weight of the picked edge to total weight
        totalWeight += key[u];

        for (int v = 0; v < n; v++) {
            // graph[u][v] is non-zero only for adjacent vertices of m
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                key[v] = graph[u][v];
        }
    }
    printf("%d\n", totalWeight);
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int graph[MAX][MAX] = {0};

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        // Adjust for 1-based indexing in input
        graph[u-1][v-1] = w;
        graph[v-1][u-1] = w;
    }

    primMST(graph, n);
    return 0;
}
