#include <stdio.h>
#include <stdlib.h>

// Define the structure for a binary tree node
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Define a structure for the queue used in level-order traversal
struct QueueNode {
    struct TreeNode *node;
    struct QueueNode *next;
};

struct Queue {
    struct QueueNode *front, *rear;
};

// Function to create a new tree node
struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new queue node
struct QueueNode* createQueueNode(struct TreeNode* node) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

// Function to enqueue a node to the queue
void enqueue(struct Queue* q, struct TreeNode* node) {
    if (node == NULL) return;
    struct QueueNode* newNode = createQueueNode(node);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }
    q->rear->next = newNode;
    q->rear = newNode;
}

// Function to dequeue a node from the queue
struct TreeNode* dequeue(struct Queue* q) {
    if (q->front == NULL) return NULL;
    struct QueueNode* temp = q->front;
    struct TreeNode* node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) q->rear = NULL;
    free(temp);
    return node;
}

// Function to check if the queue is empty
int isQueueEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Function to build the binary tree from level-order input
struct TreeNode* buildTree(int arr[], int n) {
    if (n <= 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = createTreeNode(arr[0]);
    struct Queue* q = createQueue();
    enqueue(q, root);
    int i = 1;

    while (i < n && !isQueueEmpty(q)) {
        struct TreeNode* currentNode = dequeue(q);

        // Process left child
        if (i < n && arr[i] != -1) {
            currentNode->left = createTreeNode(arr[i]);
            enqueue(q, currentNode->left);
        }
        i++;

        // Process right child
        if (i < n && arr[i] != -1) {
            currentNode->right = createTreeNode(arr[i]);
            enqueue(q, currentNode->right);
        }
        i++;
    }
    // Note: Queue memory should be freed after use in a production environment
    return root;
}

// Function to print the right view of the binary tree
void printRightView(struct TreeNode* root) {
    if (root == NULL) return;

    struct Queue* q = createQueue();
    enqueue(q, root);

    while (!isQueueEmpty(q)) {
        int levelSize = 0;
        struct QueueNode* temp = q->front;
        while(temp != NULL) {
            levelSize++;
            temp = temp->next;
        }
        
        for (int i = 0; i < levelSize; i++) {
            struct TreeNode* currentNode = dequeue(q);

            // If it's the last node of the current level, print it
            if (i == levelSize - 1) {
                printf("%d ", currentNode->data);
            }

            // Enqueue children
            if (currentNode->left != NULL) {
                enqueue(q, currentNode->left);
            }
            if (currentNode->right != NULL) {
                enqueue(q, currentNode->right);
            }
        }
    }
    // Note: Queue memory should be freed after use
}

// Main function to run the program with the example
int main() {
    int N = 7;
    int arr[] = {1, 2, 3, 4, 5, -1, 6};

    struct TreeNode* root = buildTree(arr, N);
    
    printf("Output: ");
    printRightView(root);
    printf("\n");

    // Memory management: free the tree nodes (simplified)
    // In a real application, a separate function for post-order deletion would be better
    // For this example, we focus on the logic
    return 0;
}
