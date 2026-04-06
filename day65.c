#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX]; // Adjacency Matrix
bool visited[MAX];
int V, E;

// DFS function to detect cycle
bool isCyclicUtil(int v, int parent) {
    visited[v] = true;

    for (int i = 0; i < V; i++) {
        // Check if there is an edge to neighbor 'i'
        if (adj[v][i]) {
            // If neighbor is not visited, recurse
            if (!visited[i]) {
                if (isCyclicUtil(i, v))
                    return true;
            }
            // If neighbor is visited and not the parent, a cycle exists
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

// Function to handle disconnected components
void isCyclic() {
    for (int i = 0; i < V; i++) visited[i] = false;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, -1)) {
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main() {
    // Example: V = 4, E = 4 (Cycle: 0-1-2-0)
    V = 4;
    for(int i=0; i<V; i++) for(int j=0; j<V; j++) adj[i][j] = 0;
    
    // Adding edges (undirected)
    int edges[][2] = {{0, 1}, {1, 2}, {2, 0}, {2, 3}};
    for(int i = 0; i < 4; i++) {
        adj[edges[i][0]][edges[i][1]] = 1;
        adj[edges[i][1]][edges[i][0]] = 1;
    }

    isCyclic();
    return 0;
}
