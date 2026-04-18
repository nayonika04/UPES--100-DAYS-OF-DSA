#include <stdio.h>

int adj[20][20], visited[20], n;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

int main() {
    int m, u, v, count = 0;
    
    // Input format: n (nodes), m (edges)
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    // Initialize adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) adj[i][j] = 0;
        visited[i] = 0;
    }

    // Input m edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    // Start DFS from the first node
    if (n > 0) dfs(1);

    // Check if all nodes were visited
    for (int i = 1; i <= n; i++) {
        if (visited[i]) count++;
    }

    if (count == n)
        printf("CONNECTED\n");
    else
        printf("NOT CONNECTED\n");

    return 0;
}
