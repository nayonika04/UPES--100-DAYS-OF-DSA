#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

// Structure to represent a node in the priority queue
typedef struct {
    int v;
    int dist;
} Node;

// Structure for the Min-Heap (Priority Queue)
typedef struct {
    Node *nodes;
    int size;
    int capacity;
} MinHeap;

// Function to create a Min-Heap
MinHeap* createMinHeap(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->nodes = (Node*)malloc(capacity * sizeof(Node));
    return heap;
}

// Function to swap two nodes in the heap
void swap(Node *a, Node *b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

// standard min-heapify function
void minHeapify(MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->nodes[left].dist < heap->nodes[smallest].dist)
        smallest = left;
    if (right < heap->size && heap->nodes[right].dist < heap->nodes[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->nodes[smallest], &heap->nodes[idx]);
        minHeapify(heap, smallest);
    }
}

// Function to extract the node with the minimum distance
Node extractMin(MinHeap* heap) {
    Node root = heap->nodes[0];
    heap->nodes[0] = heap->nodes[heap->size - 1];
    heap->size--;
    minHeapify(heap, 0);
    return root;
}

// Function to insert a node into the Min-Heap
void insertMinHeap(MinHeap* heap, int v, int dist) {
    heap->size++;
    int i = heap->size - 1;
    heap->nodes[i].v = v;
    heap->nodes[i].dist = dist;

    while (i != 0 && heap->nodes[(i - 1) / 2].dist > heap->nodes[i].dist) {
        swap(&heap->nodes[i], &heap->nodes[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Dijkstra's Algorithm implementation
void dijkstra(int V, int graph[V][V], int src) {
    int dist[V];
    for (int i = 0; i < V; i++) dist[i] = INF;

    MinHeap* pq = createMinHeap(V * V); // Capacity for multiple entries of same vertex
    dist[src] = 0;
    insertMinHeap(pq, src, 0);

    while (pq->size != 0) {
        Node minNode = extractMin(pq);
        int u = minNode.v;
        int d = minNode.dist;

        // Skip if a better distance was already processed
        if (d > dist[u]) continue;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] != 0) { // If there is an edge
                int weight = graph[u][v];
                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    insertMinHeap(pq, v, dist[v]);
                }
            }
        }
    }

    printf("Vertex   Distance from Source %d\n", src);
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    
    free(pq->nodes);
    free(pq);
}

int main() {
    int V = 5;
    // Adjacency matrix representation
    int graph[5][5] = { {0, 10, 0, 30, 100},
                        {10, 0, 50, 0, 0},
                        {0, 50, 0, 20, 10},
                        {30, 0, 20, 0, 60},
                        {100, 0, 10, 60, 0} };

    dijkstra(V, graph, 0);
    return 0;
}
