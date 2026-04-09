#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int adj[MAX][MAX], int V) {
    int in_degree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topo_order[MAX], count = 0;

    // 1. Calculate in-degree of each vertex
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (adj[i][j]) {
                in_degree[j]++;
            }
        }
    }

    // 2. Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (in_degree[i] == 0) {
            queue[rear++] = i;
        }
    }

    // 3. Process the queue
    while (front < rear) {
        int u = queue[front++];
        topo_order[count++] = u;

        for (int v = 0; v < V; v++) {
            if (adj[u][v]) {
                in_degree[v]--;
                if (in_degree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    // 4. Check for cycles and print result
    if (count != V) {
        printf("The graph contains a cycle. Topological sort not possible.\n");
    } else {
        printf("Topological Sort: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", topo_order[i]);
        }
        printf("\n");
    }
}

int main() {
    int V = 6;
    int adj[MAX][MAX] = {0};

    // Example edges: (5, 2), (5, 0), (4, 0), (4, 1), (2, 3), (3, 1)
    adj[5][2] = 1; adj[5][0] = 1; adj[4][0] = 1;
    adj[4][1] = 1; adj[2][3] = 1; adj[3][1] = 1;

    topologicalSort(adj, V);
    return 0;
}
