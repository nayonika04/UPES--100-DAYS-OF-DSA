#include <stdio.h>

#define MAX 100

void displayMatrix(int matrix[MAX][MAX], int n) {
    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n, m, u, v, type;
    int adj[MAX][MAX] = {0}; // Initialize all elements to 0

    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &m);
    printf("Enter graph type (0 for Undirected, 1 for Directed): ");
    scanf("%d", &type);

    printf("Enter %d pairs of edges (u v):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        
        // Basic validation for vertex indices (assuming 0 to n-1)
        if (u >= 0 && u < n && v >= 0 && v < n) {
            adj[u][v] = 1;
            if (type == 0) {
                adj[v][u] = 1; // Symmetric for undirected graphs
            }
        } else {
            printf("Invalid edge! Vertices must be between 0 and %d\n", n - 1);
            i--; // Decrement to re-enter this edge
        }
    }

    displayMatrix(adj, n);
    return 0;
}
