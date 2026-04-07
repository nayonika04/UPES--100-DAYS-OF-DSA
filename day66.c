#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for Adjacency List Node
struct Node {
    int dest;
    struct Node* next;
};

// Structure for Graph
struct Graph {
    int V;
    struct Node** adj;
};

// Create a new adjacency list node
struct Node* createNode(int dest) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Create a graph with V vertices
struct Graph* createGraph(int V) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = malloc(V * sizeof(struct Node*));
    for (int i = 0; i < V; i++) graph->adj[i] = NULL;
    return graph;
}

// Add edge to directed graph
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

// Recursive function to detect cycle
bool isCyclicUtil(int v, bool visited[], bool recStack[], struct Graph* graph) {
    if (!visited[v]) {
        visited[v] = true;
        recStack[v] = true;

        struct Node* temp = graph->adj[v];
        while (temp != NULL) {
            int neighbor = temp->dest;
            if (!visited[neighbor] && isCyclicUtil(neighbor, visited, recStack, graph))
                return true;
            else if (recStack[neighbor])
                return true;
            temp = temp->next;
        }
    }
    recStack[v] = false; // Backtrack: remove from current path
    return false;
}

// Main function to check for cycles
void detectCycle(struct Graph* graph) {
    bool* visited = calloc(graph->V, sizeof(bool));
    bool* recStack = calloc(graph->V, sizeof(bool));

    for (int i = 0; i < graph->V; i++) {
        if (isCyclicUtil(i, visited, recStack, graph)) {
            printf("YES\n");
            free(visited); free(recStack);
            return;
        }
    }
    printf("NO\n");
    free(visited); free(recStack);
}

int main() {
    int V = 4;
    struct Graph* graph = createGraph(V);
    // Adding edges to form a cycle: 0->1->2->0
    addEdge(graph, 0, 1);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);

    detectCycle(graph); // Output: YES
    return 0;
}
