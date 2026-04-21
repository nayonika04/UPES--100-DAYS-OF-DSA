#include <stdio.h>

#define INF 1e9

void floydWarshall(int n, int dist[n][n]) {
    // Treat each vertex k as an intermediate point
    for (int k = 0; k < n; k++) {
        // Source vertex i
        for (int i = 0; i < n; i++) {
            // Destination vertex j
            for (int j = 0; j < n; j++) {
                // If path through k is shorter, update dist[i][j]
                if (dist[i][k] != INF && dist[k][j] != INF && 
                    dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    int dist[n][n];
    
    // Read the adjacency matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            // Replace -1 with INF (except for self-loops)
            if (val == -1) {
                dist[i][j] = INF;
            } else {
                dist[i][j] = val;
            }
        }
    }

    floydWarshall(n, dist);

    // Print the final shortest distance matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) {
                printf("-1 ");
            } else {
                printf("%d ", dist[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
