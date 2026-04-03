#include <stdio.h>
#include <stdlib.h>

// Structure definitions for adjacency list node and graph
struct AdjListNode { int dest; struct AdjListNode* next; };
struct AdjList { struct AdjListNode* head; };
struct Graph { int V; struct AdjList* array; };

// Function to create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V * sizeof(struct AdjList));
    for (int i = 0; i < V; ++i) graph->array[i].head = NULL;
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add edge from src to dest
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest; newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    // Add edge from dest to src (undirected)
    newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = src; newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

// Function to print the graph
void printGraph(struct Graph* graph) {
    for (int v = 0; v < graph->V; ++v) {
        struct AdjListNode* temp = graph->array[v].head;
        printf("Vertex %d: ", v);
        while (temp) { printf("-> %d ", temp->dest); temp = temp->next; }
        printf("\n");
    }
}

int main() {
    int n, m, u, v;
    if (scanf("%d %d", &n, &m) != 2) return -1;
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        if (scanf("%d %d", &u, &v) == 2) addEdge(graph, u, v);
    }
    printGraph(graph);
    return 0;
}
