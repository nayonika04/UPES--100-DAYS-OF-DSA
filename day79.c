#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct Node {
    int target, weight;
    struct Node* next;
} Node;

typedef struct {
    int vertex, dist;
} HeapNode;

// Function to create a new adjacency list node
Node* createNode(int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->target = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

// Dijkstra using Min-Heap
void dijkstra(int n, Node** adj, int source) {
    int dist[n + 1];
    for (int i = 1; i <= n; i++) dist[i] = INF;
    dist[source] = 0;

    HeapNode heap[n * n]; // Simple heap for demonstration
    int heapSize = 0;

    // Push source
    heap[heapSize++] = (HeapNode){source, 0};

    while (heapSize > 0) {
        // Extract Min
        int minIdx = 0;
        for (int i = 1; i < heapSize; i++)
            if (heap[i].dist < heap[minIdx].dist) minIdx = i;
        
        HeapNode current = heap[minIdx];
        heap[minIdx] = heap[--heapSize];

        if (current.dist > dist[current.vertex]) continue;

        Node* temp = adj[current.vertex];
        while (temp) {
            if (dist[current.vertex] + temp->weight < dist[temp->target]) {
                dist[temp->target] = dist[current.vertex] + temp->weight;
                heap[heapSize++] = (HeapNode){temp->target, dist[temp->target]};
            }
            temp = temp->next;
        }
    }

    for (int i = 1; i <= n; i++) printf("%d ", dist[i]);
    printf("\n");
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    Node* adj[n + 1];
    for (int i = 1; i <= n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        Node* newNode = createNode(v, w);
        newNode->next = adj[u];
        adj[u] = newNode;
    }

    int source;
    scanf("%d", &source);
    dijkstra(n, adj, source);

    return 0;
}
