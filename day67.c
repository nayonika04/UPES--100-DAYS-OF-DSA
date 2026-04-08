#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int stack[MAX];
int top = -1;
int vertices;

// Function to push a vertex onto the stack
void push(int v) {
    stack[++top] = v;
}

// DFS-based recursive utility for topological sort
void topoSortDFS(int v) {
    visited[v] = 1; // Mark node as visited

    for (int i = 0; i < vertices; i++) {
        // If an edge exists and the adjacent node is not visited
        if (adj[v][i] == 1 && !visited[i]) {
            topoSortDFS(i);
        }
    }
    // Push vertex to stack after all its neighbors are processed
    push(v);
}

int main() {
    int edges, u, v;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);
    printf("Enter number of edges: ");
    scanf("%d", &edges);

    // Initialize adjacency matrix and visited array
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++)
            adj[i][j] = 0;
    }

    printf("Enter edges (source destination):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Call DFS for each unvisited vertex
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            topoSortDFS(i);
        }
    }

    // The topological order is obtained by popping from the stack
    printf("\nTopological Ordering: ");
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
    printf("\n");

    return 0;
}
