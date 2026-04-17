#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
int n, m;

// DFS function to visit all nodes in a component
void dfs(int u) {
    visited[u] = true;
    for (int v = 1; v <= n; v++) {
        if (adj[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}

int main() {
    // Input format: n m
    if (scanf("%d %d", &n, &m) != 2) return 0;

    // Reset graph and visited array
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        for (int j = 1; j <= n; j++) adj[i][j] = 0;
    }

    // Input format: edges (u v)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1; // Undirected graph
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            count++; // New component found
            dfs(i);  // Mark all nodes in this component
        }
    }

    printf("%d\n", count);
    return 0;
}
