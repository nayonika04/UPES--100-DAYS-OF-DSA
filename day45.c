#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN check if needed, though the input format doesn't require it

// Define the structure for a binary tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Define the structure for a queue node (used for tree construction)
struct QNode {
    struct Node *node;
    struct QNode *next;
};

// Define the Queue structure
struct Queue {
    struct QNode *front, *rear;
};

// Function to create a new tree node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a new queue node
struct QNode* newQNode(struct Node* node) {
    struct QNode* qNode = (struct QNode*)malloc(sizeof(struct QNode));
    qNode->node = node;
    qNode->next = NULL;
    return qNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a node
void enqueue(struct Queue* q, struct Node* node) {
    if (node == NULL) return; // Only enqueue valid nodes

    struct QNode* temp = newQNode(node);

    if (q->rear == NULL) {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

// Function to dequeue a node
struct Node* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;

    struct QNode* temp = q->front;
    struct Node* node = temp->node;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

// Function to build the binary tree from level order input
struct Node* buildTreeLevelOrder(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;

    struct Node* root = newNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;

    while (i < n && q->front != NULL) {
        struct Node* curr = dequeue(q);

        // Process left child
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(q, curr->left);
        }
        i++;

        // Process right child
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(q, curr->right);
        }
        i++;
    }
    // Free the queue memory after building the tree
    free(q);
    return root;
}

// Function to calculate the height of the tree using recursion (DFS approach)
int treeHeightRecursive(struct Node* root) {
    if (root == NULL) {
        return 0; // Height of an empty tree is 0
    } else {
        // Compute the height of left and right subtrees
        int leftHeight = treeHeightRecursive(root->left);
        int rightHeight = treeHeightRecursive(root->right);

        // Use the larger one and add 1 for the current node
        if (leftHeight > rightHeight) {
            return (leftHeight + 1);
        } else {
            return (rightHeight + 1);
        }
    }
}

// Main function to handle input and output
int main() {
    int N;
    // Read the number of nodes
    if (scanf("%d", &N) != 1) return 1;

    int arr[N];
    for (int i = 0; i < N; i++) {
        // Read the level order elements
        if (scanf("%d", &arr[i]) != 1) return 1;
    }

    // Build the tree from the input array
    struct Node* root = buildTreeLevelOrder(arr, N);

    // Calculate the height of the tree
    int height = treeHeightRecursive(root);

    // Print the result
    printf("%d\n", height);

    // Note: A full memory deallocation of the tree nodes is recommended in a complete program

    return 0;
}
