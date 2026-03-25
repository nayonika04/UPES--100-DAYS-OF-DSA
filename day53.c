#include <stdio.h>
#include <stdlib.h>

// Define a structure for a binary tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Define a structure to store a node and its horizontal distance (HD)
struct QueueItem {
    struct Node* node;
    int hd;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build the tree from level order input
struct Node* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Node** queue = (struct Node**)malloc(n * sizeof(struct Node*));
    int head = 0, tail = 0;
    queue[tail++] = root;

    for (int i = 1; i < n; i += 2) {
        struct Node* current = queue[head++];

        if (arr[i] != -1) {
            current->left = newNode(arr[i]);
            queue[tail++] = current->left;
        }
        if (i + 1 < n && arr[i + 1] != -1) {
            current->right = newNode(arr[i + 1]);
            queue[tail++] = current->right;
        }
    }
    free(queue);
    return root;
}

// Function to perform vertical order traversal and print nodes
void verticalOrder(struct Node* root) {
    if (root == NULL) return;

    // Use a queue for level order traversal, storing Node and HD
    struct QueueItem* queue = (struct QueueItem*)malloc(100 * sizeof(struct QueueItem)); // Assuming max 100 nodes for simplicity
    int head = 0, tail = 0;
    queue[tail].node = root;
    queue[tail++].hd = 0;

    // Use a dynamically growing array to store nodes by their HD
    // In a real C solution, a dynamically allocated hash map (e.g., a balanced BST or a hash table)
    // would be necessary to efficiently manage the various HDs. 
    // The problem constraints suggest a small enough tree that a simpler approach might work, 
    // but the best general approach uses a map. 
    // For this example, we will use the idea of finding min/max HD first and then iterating.
    
    // The simplest way to handle this in standard C without custom hash map implementation is 
    // to use the approach of finding min/max HD first, and then traversing the tree for each HD.
    // The following code demonstrates the map approach idea (common in C++/Java), 
    // but a full C implementation would be more complex.
    
    // For the prompt's simplicity and constraints:
    // A standard C solution often finds min/max HD and then iterates. 
    // The below implements a single BFS pass logic using map which is a more advanced C++ approach.
    
    // Since we need to follow the "left to right, top to bottom" rule, the BFS with a map 
    // is efficient. However, a C implementation of a map requires careful handling.

    // Given the constraints and typical C problem structure, the following approach might be expected:

    // 1. Find the min and max horizontal distances (HD).
    // 2. Iterate from min HD to max HD and for each HD, collect nodes using BFS to maintain top-bottom order.

    // Re-implementing with the expected C-style approach:
    
    int min_hd = 0, max_hd = 0;
    findMinMaxHD(root, &min_hd, &max_hd, 0);

    for (int i = min_hd; i <= max_hd; i++) {
        printVerticalLine(root, i, 0);
    }
    free(queue); // Free the temporary queue allocated earlier.
}

void findMinMaxHD(struct Node* node, int* min_hd, int* max_hd, int current_hd) {
    if (node == NULL) return;
    if (current_hd < *min_hd) *min_hd = current_hd;
    if (current_hd > *max_hd) *max_hd = current_hd;
    findMinMaxHD(node->left, min_hd, max_hd, current_hd - 1);
    findMinMaxHD(node->right, min_hd, max_hd, current_hd + 1);
}

void printVerticalLine(struct Node* root, int target_hd, int current_hd) {
    if (root == NULL) return;

    // A queue is used to maintain level order for elements on the same vertical line
    // but the outer loop traverses the tree multiple times.
    // The problem statement requires nodes on the same vertical line to be printed top-to-bottom.
    // The multiple traversal method guarantees the top-to-bottom order within a vertical line implicitly.

    if (current_hd == target_hd) {
        printf("%d ", root->data);
    }
    printVerticalLine(root->left, target_hd, current_hd - 1);
    printVerticalLine(root->right, target_hd, current_hd + 1);
    
    // Note: The simple recursive print might not strictly follow the "top to bottom and left to right" 
    // for multiple nodes on the same *level* of the same vertical line (which shouldn't happen 
    // with standard tree coordinates, but the problem states this condition). 
    // The proper fix involves using a queue to collect nodes for a given HD in level order.
    // The simpler implementation is often acceptable for basic C problems.

    // The snippet below shows the BFS method for collecting nodes for a single HD:
    /*
    struct QueueItem q[100];
    int h=0, t=0;
    q[t].node = root; q[t++].hd = 0;
    while(h < t) {
        struct QueueItem current = q[h++];
        if (current.hd == target_hd) printf("%d ", current.node->data);
        if (current.node->left) { q[t].node = current.node->left; q[t++].hd = current.hd - 1; }
        if (current.node->right) { q[t].node = current.node->right; q[t++].hd = current.hd + 1; }
    }
    */
    // This inner BFS is what guarantees the correct top-to-bottom order within the line.
}


int main() {
    int N;
    // Read number of nodes
    if (scanf("%d", &N) != 1) return 1;

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i) {
        scanf("%d", &arr[i]);
    }

    struct Node* root = buildTree(arr, N);
    
    // The provided example requires the output in a single line with spaces.
    
    // The logic to print correctly needs to be integrated. 
    // The previous verticalOrder function needs the inner BFS loop.
    // Let's integrate that into the main function for simplicity and correctness as per the example.

    // A full, correct implementation requires managing the collection of nodes for each HD.
    // We can simulate a map using a min/max HD finding and iterating with BFS for each line.

    int min_hd_val = 0, max_hd_val = 0;
    findMinMaxHD(root, &min_hd_val, &max_hd_val, 0);

    for (int i = min_hd_val; i <= max_hd_val; i++) {
        // Collect nodes for vertical line 'i' using BFS
        struct QueueItem q_line[100]; // Another temporary queue
        int h_line=0, t_line=0;
        q_line[t_line].node = root; 
        q_line[t_line++].hd = 0;

        while(h_line < t_line) {
            struct QueueItem current = q_line[h_line++];
            if (current.hd == i) {
                printf("%d ", current.node->data);
            }
            if (current.node->left) { 
                q_line[t_line].node = current.node->left; 
                q_line[t_line++].hd = current.hd - 1; 
            }
            if (current.node->right) { 
                q_line[t_line].node = current.node->right; 
                q_line[t_line++].hd = current.hd + 1; 
            }
        }
    }
    
    printf("\n");
    free(arr);
    // Free the tree nodes if needed (omitted for brevity in the main function).

    return 0;
}
